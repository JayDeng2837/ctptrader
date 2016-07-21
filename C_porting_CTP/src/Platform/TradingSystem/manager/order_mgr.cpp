//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     ordermgr.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/19
//////////////////////////////////////////////////////////////////////////
// self header
#include "order_mgr.h"

// c header

// c++ header
#include <fstream>

// third library header

// inner header
#include "Base.h"
#include "global_variables.h"
#include "strategy.h"

#include "DateTime.h"

#include "lctslog.h"

typedef boost::mutex::scoped_lock lc_scoped_lock;

using namespace std;

void OrderMgr::Init(int FRONT_ID, int SESSION_ID)
{
	this->FRONT_ID = FRONT_ID;
	this->SESSION_ID = SESSION_ID;
}

void OrderMgr::OMS_OnRtnOrder(CThostFtdcOrderFieldEx * pOrderTemp)
{

#ifndef LOCK_FREE_OMS
	lc_scoped_lock _lock(oms_Mutex);
#endif // LOCK_FREE_OMS

	pOrderTemp->currentMicroSec = GetElapsedTime(GetCurrentTick());

	CThostFtdcOrderField * pOrder = &pOrderTemp->field;

	const string & key = getKey(pOrder->FrontID, pOrder->SessionID, pOrder->OrderRef);

	ORDER_ITOR itor = orderCenter.find(key);

	int new_trade_count = -1;

	if (itor != orderCenter.end())
	{
		CThostFtdcOrderFieldEx * pCurrOrder = itor->second;
		new_trade_count = pOrder->VolumeTraded - pCurrOrder->field.VolumeTraded;

		if (!pCurrOrder)
		{
			LOGFILE(LOG_ERROR, "pCurrOrder == null");
			throw std::logic_error("pCurrOrder == null");
		}

		refreshSignal(pOrder, key);

		memcpy(&pCurrOrder->field, pOrder, sizeof(CThostFtdcOrderField));
	}
	else
	{
		refreshSignal(pOrder, key);

		new_trade_count = pOrder->VolumeTraded;
		orderCenter[key] = pOrderTemp;
	}

	if (new_trade_count < 0)
	{
		throw std::logic_error("trade_count < 0");
	}
	else if (new_trade_count > 0)
	{
		positionMgr.CalcPosition(pOrder->InstrumentID, pOrder->Direction, pOrder->CombOffsetFlag, new_trade_count);
	}
}

void OrderMgr::refreshSignal(CThostFtdcOrderField * pOrder, const std::string & key)
{

	ORDER_SIGNAL_ITOR itor2 = orderId_pSignal_Map.find(key);
	if (itor2 != orderId_pSignal_Map.end())
	{
		Signal * s = (Signal *)itor2->second;
		if (s)
		{
			if (s->orderRtnMicroSec == 0)
			{
				if (strcmp(pOrder->OrderSysID, "") != 0)
				{
					get_curtime_l(s->orderRtnTime);
					s->orderRtnMicroSec = GetElapsedTime(GetCurrentTick());
				}
			}

			IStrategy * pStrategy = (IStrategy *)s->strategy_ptr;

			switch (pOrder->OrderStatus)
			{
			case THOST_FTDC_OST_AllTraded: // end
			{
				LOGFILE(LOG_ERROR, "THOST_FTDC_OST_AllTraded");
				break;
			}
			case THOST_FTDC_OST_Canceled: // end
			{
				LOGFILE(LOG_ERROR, "THOST_FTDC_OST_AllTraded");
				pStrategy->OnOrderCancelled(itor2->second, pOrder->OrderLocalID);
				break;
			}
			case THOST_FTDC_OST_PartTradedNotQueueing: // end
			{
				LOGFILE(LOG_ERROR, "THOST_FTDC_OST_PartTradedNotQueueing");
				throw std::logic_error("got THOST_FTDC_OST_PartTradedNotQueueing");
				break;
			}
			case THOST_FTDC_OST_NoTradeNotQueueing: // end
			{
				LOGFILE(LOG_ERROR, "THOST_FTDC_OST_NoTradeNotQueueing");
				throw std::logic_error("got THOST_FTDC_OST_NoTradeNotQueueing");
				break;
			}
			case THOST_FTDC_OST_NoTradeQueueing:
			{
				LOGFILE(LOG_ERROR, "THOST_FTDC_OST_NoTradeQueueing");
				break;
			}
			case THOST_FTDC_OST_Unknown:
			{
				LOGFILE(LOG_ERROR, "THOST_FTDC_OST_Unknown");
				break;
			}
			default:
			{
				throw std::logic_error("got others order status");
				break;
			}
			}
		}
	}

}

void OrderMgr::OMS_OnRspQryOrder(CThostFtdcOrderFieldEx * pOrder)
{
	if (pOrder)
	{
		const string & key = pOrder->field.InstrumentID;
		ORDER_LIST_ITOR itor = exchangeOrderCenter.find(key);

		if (itor == exchangeOrderCenter.end())
		{
			std::list<CThostFtdcOrderFieldEx *> temp;
			temp.push_back(pOrder);
			exchangeOrderCenter[key] = temp;
		}
		else
		{
			itor->second.push_back(pOrder);
		}
	}
}

void OrderMgr::OMS_OnRtnTrade(CThostFtdcTradeField * pTrade)
{

#ifndef LOCK_FREE_OMS
	lc_scoped_lock _lock(oms_Mutex);
#endif // LOCK_FREE_OMS

	const string & key = pTrade->OrderSysID;
	TRADE_ITOR itor = tradeCenter.find(key);

	if (itor != tradeCenter.end())
	{
		itor->second.push_back(pTrade);
	}
	else
	{
		std::list<CThostFtdcTradeField *> temp;
		temp.push_back(pTrade);
		tradeCenter[key] = temp;
	}
}

void OrderMgr::OMS_OnErrRtnOrderInsert(CThostFtdcInputOrderFieldEx2 * pInputOrder)
{
}

void OrderMgr::OMS_OnErrRtnOrderAction(CThostFtdcOrderActionFieldEx2 * pOrderAction)
{
}

void OrderMgr::OMS_OnRspOrderInsert(CThostFtdcInputOrderFieldEx2 * pInputOrder)
{
}

void OrderMgr::OMS_OnRspOrderAction(CThostFtdcInputOrderActionFieldEx2 * pOrderAction)
{
}

std::string OrderMgr::getKey(int frontId, int sessionId, const char * orderRef)
{
	char key[100];
	MY_SPRINTF(key, "%d|%d|%s", frontId, sessionId, orderRef);
	return key;
}

void OrderMgr::OMS_OrderInsert(LCLONGLONG pSignal_Addr, string local_orderid, int orderRef)
{

#ifndef LOCK_FREE_OMS
	lc_scoped_lock _lock(oms_Mutex);
#endif // LOCK_FREE_OMS

	LocalKey key;
	key.localOrderId = local_orderid;
	key.orderRef = orderRef;

	pSignal_orderId_Map[pSignal_Addr] = key;
	orderId_pSignal_Map[local_orderid] = pSignal_Addr;
}

bool OrderMgr::OMS_InputOrderAction(LCLONGLONG pSignal_ptr, std::string & localOrderId, int & orderRef)
{

#ifndef LOCK_FREE_OMS
	lc_scoped_lock _lock(oms_Mutex);
#endif // LOCK_FREE_OMS

	SIGNAL_ORDER_ITOR itor = pSignal_orderId_Map.find(pSignal_ptr); //get local_orderid
	if (itor != pSignal_orderId_Map.end())
	{
		localOrderId = itor->second.localOrderId;
		orderRef = itor->second.orderRef;
		return true;
	}

	return false;
}

void OrderMgr::WriteToDisk(const std::string & path)
{
	ofstream fout;

	try
	{
		fout.open(path, ios::trunc);

		SIGNAL_ORDER_ITOR itor = pSignal_orderId_Map.begin();

		fout << "InstrumentID, price, qty, order_type, direction, orderTime, orderRtnTime, currentMicroSec_in_queue, "
			"currentMicroSec, deltaT_in_queue, orderRtnMicroSec,"
			" deltaT, SystemID, tradeInfo, StrategyName" << endl;

		for (; itor != pSignal_orderId_Map.end(); itor++)
		{
			Signal * s = (Signal *)itor->first;

			if (s)
			{
				fout << s->InstrumentID << "," << s->price << "," << s->qty << "," << ot_arr[s->orderType - Market]
					<< "," << d_arr[s->direction - Buy] << "," << s->orderTime << "," << s->orderRtnTime << ","
					<< s->currentMicroSec_in_queue << "," << s->currentMicroSec << "," << (s->currentMicroSec - s->currentMicroSec_in_queue)
					<< "," << s->orderRtnMicroSec << ","
					<< (s->orderRtnMicroSec > 0 ? (s->orderRtnMicroSec - s->currentMicroSec_in_queue) : 0);

				string orderSysId = ",";
				ORDER_ITOR itor2 = orderCenter.find(itor->second.localOrderId);
				if (itor2 != orderCenter.end())
				{
					CThostFtdcOrderFieldEx * order = itor2->second;
					if (order)
					{
						orderSysId.append(order->field.OrderSysID);
					}
				}

				fout << orderSysId;

				TRADE_ITOR itor_trade = tradeCenter.find(orderSysId);

				string tradeInfo = ",";

				if (itor_trade != tradeCenter.end())
				{
					const std::list<CThostFtdcTradeField *> & listTrade = itor_trade->second;

					std::list<CThostFtdcTradeField *>::const_iterator citor = listTrade.begin();

					for (; citor != listTrade.end(); citor++)
					{
						CThostFtdcTradeField * pTrade = *citor;
						char temp[100];
						MY_SPRINTF(temp, "%s|%.2f|%d;", pTrade->TradeTime, pTrade->Price, pTrade->Volume);
						tradeInfo.append(temp);
					}
				}

				fout << tradeInfo;

				IStrategy * pStrategy = (IStrategy *)s->strategy_ptr;
				if (pStrategy)
				{
					fout << "," << pStrategy->getName();
				}

				fout << endl;
			}
		}

		fout.flush();
	}
	catch (...)
	{
	}

	if (fout.is_open())
		fout.close();

	try
	{
		fout.open("_exchange_" + path, ios::trunc);

		ORDER_LIST_ITOR itor = exchangeOrderCenter.begin();

		fout << "InstrumentID, OrderSysID, OrderType, OrderRef, OrderLocalID, OrderPriceType, "
			"LimitPrice, Direction, CombOffsetFlag, OrderStatus, StatusMsg, InsertTime" << endl;

		for (; itor != exchangeOrderCenter.end(); itor++)
		{
			const string & instrument = itor->first;
			list<CThostFtdcOrderFieldEx *> order_lst = itor->second;
			list<CThostFtdcOrderFieldEx *>::iterator itor1 = order_lst.begin();
			fout << instrument;
			for (; itor1 != order_lst.end(); itor1++)
			{
				const CThostFtdcOrderField & field = (*itor1)->field;
				fout << "," << field.OrderSysID << "," << field.OrderType << "," << field.OrderRef
					<< "," << field.OrderLocalID << "," << field.OrderPriceType << "," << field.LimitPrice
					<< "," << field.Direction << "," << field.CombOffsetFlag << "," << field.OrderStatus
					<< "," << field.StatusMsg << "," << field.InsertTime << "\n";
			}
		}

		fout.flush();
	}
	catch (...)
	{
	}

	if (fout.is_open())
		fout.close();

}
