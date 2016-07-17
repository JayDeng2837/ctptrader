//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     OMSWorker.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/18
//////////////////////////////////////////////////////////////////////////
// self header
#include "omsworker.h"

// c header

// c++ header

// third library header
#include <boost/thread.hpp>

// inner header
#include "fifo_hpq.h"
#include "lctslog.h"
#include "TraderWrapper.h"
#include "queue_helper.h"
#include "global_variables.h"

#include "Base.h"
#include "strategy.h"

using namespace std;

OMSWorker::OMSWorker(ITrader * trader) : trader(trader)
{
}

OMSWorker::~OMSWorker()
{
}

void OMSWorker::ProcessOrderQueue()
{
	while (isRun)
	{
		FIFO_ELEM elem;
		int res = extract_hpq(global_queue + ORDER_FIFO_ID, &elem);
		if (res == SUCCESS)
		{
			switch (elem.type)
			{
			case TRADER_ONRSPQRYORDER:
			{
				CThostFtdcOrderFieldEx * pOrder = (CThostFtdcOrderFieldEx *)elem.data;
				OMS.OMS_OnRspQryOrder(pOrder);
				break;
			}
			case TRADER_REQORDERINSERT: // 下单
			{
				Signal * pSignal = (Signal *)elem.data;

				if (!pSignal)
					break;

				string local_orderid;
				int orderRef = 0;

				//产生本地单号
				trader->GetLocalID(local_orderid, orderRef);

				//策略回调
				IStrategy * pStrategy = (IStrategy *)pSignal->strategy_ptr;
				LCLONGLONG pSignal_Addr = (LCLONGLONG)pSignal;
				//OMS记录
				OMS.OMS_OrderInsert(pSignal_Addr, local_orderid, orderRef);
				pStrategy->NotifyOrderPlacing(pSignal_Addr, local_orderid);

				//下单
				trader->PlaceOrder(pSignal, orderRef);

				break;
			}
			case TRADER_REQORDERACTION: // 撤单
			{
				Signal * pSignal = (Signal *)elem.data;

				if (!pSignal)
					break;

				//策略回调
				IStrategy * pStrategy = (IStrategy *)pSignal->strategy_ptr;
				string localOrderId;
				int orderRef = 0;
				bool got = OMS.OMS_InputOrderAction(pSignal->signal_id, localOrderId, orderRef);

				if (pStrategy)
				{
					pStrategy->NotifyOrderCancelling(pSignal->signal_id, localOrderId);
				}

				if (got && orderRef > 0)
				{
					trader->CancelOrder(pSignal->InstrumentID, orderRef);
				}
				break;
			}
			case TRADER_ONRTNORDER: // 报单回报
			{
				CThostFtdcOrderFieldEx * pOrder = (CThostFtdcOrderFieldEx *)elem.data;
				OMS.OMS_OnRtnOrder(pOrder);
				break;
			}
			case TRADER_ONRTNTRADE: // 成交回报
			{
				CThostFtdcTradeField * pTrade = (CThostFtdcTradeField *)elem.data;
				OMS.OMS_OnRtnTrade(pTrade);
				break;
			}
			case TRADER_ONERRRTNORDERINSERT: // exchange下单失败
			{
				CThostFtdcInputOrderFieldEx2 * pInputOrder = (CThostFtdcInputOrderFieldEx2 *)elem.data;
				OMS.OMS_OnErrRtnOrderInsert(pInputOrder);
				break;
			}
			case TRADER_ONERRRTNORDERACTION: // exchange撤单失败
			{
				CThostFtdcOrderActionFieldEx2 * pOrderAction = (CThostFtdcOrderActionFieldEx2 *)elem.data;
				OMS.OMS_OnErrRtnOrderAction(pOrderAction);
				break;
			}
			case TRADER_ONRSPORDERINSERT: // ctp下单失败
			{
				CThostFtdcInputOrderFieldEx2 * pInputOrder = (CThostFtdcInputOrderFieldEx2 *)elem.data;
				OMS.OMS_OnRspOrderInsert(pInputOrder);
				break;
			}
			case TRADER_ONRSPORDERACTION: // ctp撤单失败
			{
				CThostFtdcInputOrderActionFieldEx2 * pInputOrderAction = (CThostFtdcInputOrderActionFieldEx2 *)elem.data;
				OMS.OMS_OnRspOrderAction(pInputOrderAction);
				break;
			}
			default:
				break;
			}
		}

		_yield();
	}
}
