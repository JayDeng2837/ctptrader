//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     TraderWrapper.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/18
//////////////////////////////////////////////////////////////////////////
// self header
#include "TraderWrapper.h"

// c header

// c++ header

// third library header
#include <boost/filesystem.hpp>
#include <boost/thread.hpp>

#include "ctp_cmessage.h"

// inner header
#include "lctslog.h"
#include "queue_helper.h"
#include "global_variables.h"

#include "DateTime.h"

using namespace std;

TraderWrapper::TraderWrapper(const string username, const string pwd, const string front_addr,
	const std::string brokerID, const vector<string> & instru_lst)
	:AbsWrapper(username, pwd, front_addr, brokerID)
{
	this->instru_lst = instru_lst;
	string con_path = folder_path + "/trader_";
	create_directories(boost::filesystem::path(folder_path));
	pTraderApi = CThostFtdcTraderApi::CreateFtdcTraderApi(con_path.c_str());
	pTraderApi->RegisterSpi(this);
	pTraderApi->RegisterFront((char *)front_addr.c_str());
	pTraderApi->SubscribePrivateTopic(THOST_TERT_QUICK);
	pTraderApi->SubscribePublicTopic(THOST_TERT_QUICK);
}

TraderWrapper::~TraderWrapper()
{
	if (pTraderApi)
	{
		pTraderApi->RegisterSpi(nullptr);
		if (isInited)
			pTraderApi->Release();
		pTraderApi = nullptr;
	}
}

void TraderWrapper::GetLocalID(std::string & localID, int & orderRef)
{
	char key[100];
	MY_SPRINTF(key, "%d|%d|%d", FRONT_ID, SESSION_ID, iNextOrderRef);
	orderRef = iNextOrderRef++;
	localID = key;
}

bool TraderWrapper::PlaceOrder(Signal * signal, const int & orderRef)
{
	if (pTraderApi == nullptr)
		return false;

	GEN_STRUCT(inputOrder, CThostFtdcInputOrderField);

	MY_STRCPY(inputOrder.InstrumentID, signal->InstrumentID);
	MY_STRCPY(inputOrder.UserID, username.c_str());
	MY_STRCPY(inputOrder.InvestorID, username.c_str());
	MY_STRCPY(inputOrder.BrokerID, brokerID.c_str());
	MY_SPRINTF(inputOrder.OrderRef, "%d", orderRef);

	inputOrder.LimitPrice = signal->price;

	switch (signal->direction)
	{
	case Buy:
	{
		inputOrder.Direction = THOST_FTDC_D_Buy;
		inputOrder.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
		break;
	}
	case Sell:
	{
		inputOrder.Direction = THOST_FTDC_D_Sell;
		inputOrder.CombOffsetFlag[0] = THOST_FTDC_OF_Close;
		break;
	}
	case SellShort:
	{
		inputOrder.Direction = THOST_FTDC_D_Sell;
		inputOrder.CombOffsetFlag[0] = THOST_FTDC_OF_Open;
		break;
	}
	case BuyToCover:
	{
		inputOrder.Direction = THOST_FTDC_D_Buy;
		inputOrder.CombOffsetFlag[0] = THOST_FTDC_OF_Close;
		break;
	}
	default:
		break;
	}
	inputOrder.VolumeTotalOriginal = signal->qty;

	inputOrder.VolumeCondition = THOST_FTDC_VC_AV;
	inputOrder.MinVolume = 1; //最小成交手数，等同于目标手数（在上一项设为THOST_FTDC_VC_MV才有作用，这里起保护意义）
	inputOrder.CombHedgeFlag[0] = THOST_FTDC_HF_Speculation;
	inputOrder.ContingentCondition = THOST_FTDC_CC_Immediately;
	inputOrder.ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
	inputOrder.IsAutoSuspend = 0;
	inputOrder.UserForceClose = 0;
	/*
	Market = 0,
	Limit,
	IOC,
	Cancel,
	*/
	inputOrder.TimeCondition = THOST_FTDC_TC_GFD;
	inputOrder.OrderPriceType = THOST_FTDC_OPT_LimitPrice;

	switch (signal->orderType)
	{
	case Market:
	{
		inputOrder.OrderPriceType = THOST_FTDC_OPT_AnyPrice;
		break;
	}
	// 	case Limit:
	// 		{
	// 			break;
	// 		}
	case IOC:
	{
		inputOrder.TimeCondition = THOST_FTDC_TC_IOC;
		break;
	}
	// 	case Cancel:
	// 		{
	// 			break;
	// 		}
	default:
		break;
	}

	signal->currentMicroSec = GetElapsedTime(GetCurrentTick());
	get_curtime_l((char *)signal->orderTime);

	pTraderApi->ReqOrderInsert(&inputOrder, NewRequestID());

	return true;
}

bool TraderWrapper::CancelOrder(const char * instrumentid, const int & orderRef)
{
	if (pTraderApi == nullptr)
		return false;

	GEN_STRUCT(inputOrderAction, CThostFtdcInputOrderActionField);

	MY_STRCPY(inputOrderAction.UserID, username.c_str());
	MY_STRCPY(inputOrderAction.InvestorID, username.c_str());
	MY_STRCPY(inputOrderAction.BrokerID, brokerID.c_str());
	MY_STRCPY(inputOrderAction.InstrumentID, instrumentid);

	MY_SPRINTF(inputOrderAction.OrderRef, "%d", orderRef);
	inputOrderAction.FrontID = FRONT_ID;
	inputOrderAction.SessionID = SESSION_ID;
	inputOrderAction.ActionFlag = THOST_FTDC_AF_Delete;

	pTraderApi->ReqOrderAction(&inputOrderAction, NewRequestID());

	return true;
}

bool TraderWrapper::Init()
{
	isInited = true;
	pTraderApi->Init();
	FRONT_ID = 0;
	SESSION_ID = 0;
	iNextOrderRef = 0;
	return false;
}

void TraderWrapper::ReqUserLogin()
{
	if (pTraderApi)
	{
		GEN_STRUCT(field, CThostFtdcReqUserLoginField);

		MY_STRCPY(field.UserID, username.c_str());
		MY_STRCPY(field.Password, pwd.c_str());
		MY_STRCPY(field.BrokerID, brokerID.c_str());
		pTraderApi->ReqUserLogin(&field, NewRequestID());
	}
}

void TraderWrapper::OnFrontConnected()
{
	LcSetThreadAffinityMask(CTP_TRADER_CORE, GetCurrentThreadHandle());

	PushToQueue(QUERY_FIFO_ID, TRADER_ONFRONTCONNECTED, DUMMY_DATA, YIELD_TIME_INTERVAL);
	ReqUserLogin();
}

void TraderWrapper::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo,
	int nRequestID, bool bIsLast)
{
	LOGFILE(LOG_INFO, "...");

	FRONT_ID = pRspUserLogin->FrontID;
	SESSION_ID = pRspUserLogin->SessionID;

	OMS.Init(FRONT_ID, SESSION_ID);

	iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);

	if (pTraderApi)
	{
		GEN_STRUCT(field, CThostFtdcSettlementInfoConfirmField);

		MY_STRCPY(field.BrokerID, brokerID.c_str());
		MY_STRCPY(field.InvestorID, username.c_str());
		pTraderApi->ReqSettlementInfoConfirm(&field, NewRequestID());
	}
}

///投资者结算结果确认响应
void TraderWrapper::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (pTraderApi)
	{
		LOGFILE(LOG_INFO, __FUNCTION__);

		QuerySleep();

		GEN_STRUCT(field, CThostFtdcQryInstrumentField);

		if (instru_lst.size() > 0)
		{
			MY_STRCPY(field.InstrumentID, instru_lst[0].c_str());
		}

		pTraderApi->ReqQryInstrument(&field, NewRequestID());
		//--
	}
}

///请求查询投资者持仓响应
void TraderWrapper::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	// Tips: 
	//
	// YdPosition + OpenVolume - CloseVolume = Position
	// Position - (YdPosition > CloseVolume ? (YdPosition - CloseVolume) : 0) = TodayPosition

	positionMgr.UpdatePosition(pInvestorPosition, bIsLast);

	if (bIsLast)
	{

		//add query concern orders 

		vector<string>::iterator itor = this->instru_lst.begin();
		for (; itor != instru_lst.end(); itor++)
		{
			PBOOSTPOOL_ORDERED_MALLOC(pField, memoryMgr.instrument_pool, char, INSTRUMENT_SIZE);
			MY_STRCPY(pField, sizeof(char) * INSTRUMENT_SIZE, itor->c_str());
			PushToQueue(QUERY_FIFO_ID, TRADER_REQQRYORDER, pField, QUERY_TIME_INTERVAL);
		}

		PushToQueue(QUERY_FIFO_ID, TRADER_ONRSPQRYINVESTORPOSITION, DUMMY_DATA, QUERY_TIME_INTERVAL);

		LOGFILE(LOG_INFO, __FUNCTION__);
	}
}

void TraderWrapper::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (pOrder)
	//if (pOrder && pOrder->OrderStatus != THOST_FTDC_OST_AllTraded && pOrder->OrderStatus != THOST_FTDC_OST_Canceled)
	{

		PBOOSTPOOL_MALLOC(pField, memoryMgr.order_pool, CThostFtdcOrderFieldEx);

		// pField->currentMicroSec_in_queue = GetElapsedTime(GetCurrentTick());
		memcpy(&pField->field, pOrder, sizeof(CThostFtdcOrderField));

#ifdef LOCK_FREE_OMS
		PushToQueue(ORDER_FIFO_ID, TRADER_ONRSPQRYORDER, pField, YIELD_TIME_INTERVAL);
#else
		OMS.OMS_OnRtnOrder(pField);
#endif
		if (bIsLast)
		{

		}

		LOGFILE(LOG_WARN, __FUNCTION__);
	}
}

void TraderWrapper::ReqQryOrder(const std::string & instrumentid)
{
	if (pTraderApi)
	{
		GEN_STRUCT(field, CThostFtdcQryOrderField);
		MY_STRCPY(field.BrokerID, brokerID.c_str());
		MY_STRCPY(field.InvestorID, username.c_str());
		MY_STRCPY(field.InstrumentID, instrumentid.c_str());

		pTraderApi->ReqQryOrder(&field, NewRequestID());
	}

}

///请求查询资金账户响应
void TraderWrapper::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	LOGFILE(LOG_INFO, "OnRspQryTradingAccount");
	//	PushToQueue(QUERY_FIFO_ID, TRADER_ONRSPQRYTRADINGACCOUNT, pTradingAccount, YIELD_TIME_INTERVAL);
}

///请求查询合约响应
void TraderWrapper::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	dc.initItem(pInstrument);

	if (bIsLast)
	{
		ofstream fout("instrument.txt", ios::trunc);

		int count = dc.instruments.size();
		char ** pInstruments = new char *[count];
		boost::unordered_map<std::string, CThostFtdcInstrumentField>::iterator itor = dc.instruments.begin();
		int i = 0;
		stringstream result;

		result << "{\n\t\"instruments\" : \n\t[\n";
		int c = 0;
		for (; itor != dc.instruments.end(); itor++)
		{
			result << "\t\t{ \n"
				<< "\t\t\t\"Symbol\" : \"" << itor->first << "\",\n"
				<< "\t\t\t\"VolumeMultiple\" : \"" << itor->second.VolumeMultiple << "\",\n"
				<< "\t\t\t\"PriceTick\" : \"" << itor->second.PriceTick << "\"\n"
				<< "\t\t}";

			if (++c < dc.instruments.size())
			{
				result << ",\n";
			}
		}

		result << "\t\n\t]\n}";

		fout << result.str();

		fout.close();

		LOGFILE(LOG_INFO, __FUNCTION__);

		positionMgr.InitialPostions(dc.instrument_list);

		QuerySleep();

		GEN_STRUCT(field, CThostFtdcQryInvestorPositionField);

		MY_STRCPY(field.InvestorID, username.c_str());
		MY_STRCPY(field.BrokerID, brokerID.c_str());
		pTraderApi->ReqQryInvestorPosition(&field, NewRequestID());

		PushToQueue(QUERY_FIFO_ID, TRADER_ONRSPQRYINSTRUMENT, pInstrument, YIELD_TIME_INTERVAL);
	}
}

///请求查询投资者结算结果响应
void TraderWrapper::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///请求查询投资者持仓明细响应
void TraderWrapper::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///请求查询结算信息确认响应
void TraderWrapper::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

///错误应答
void TraderWrapper::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	LOGFILE(LOG_INFO, __FUNCTION__);
}

///报单通知
void TraderWrapper::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
	if (pOrder != NULL)
	{
		PBOOSTPOOL_MALLOC(pField, memoryMgr.order_pool, CThostFtdcOrderFieldEx);

		pField->currentMicroSec_in_queue = GetElapsedTime(GetCurrentTick());
		memcpy(&pField->field, pOrder, sizeof(CThostFtdcOrderField));

#ifdef LOCK_FREE_OMS
		PushToQueue(ORDER_FIFO_ID, TRADER_ONRTNORDER, pField, YIELD_TIME_INTERVAL);
#else
		OMS.OMS_OnRtnOrder(pField);
#endif

	}
	else
	{
		LOGFILE(LOG_WARN, "pOrder == NULL");
	}
}

///成交通知
void TraderWrapper::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
	if (pTrade != NULL)
	{
		PBOOSTPOOL_MALLOC_CPY(pField, pTrade, memoryMgr.trade_pool, CThostFtdcTradeField);

#ifdef LOCK_FREE_OMS
		PushToQueue(ORDER_FIFO_ID, TRADER_ONRTNTRADE, pField, YIELD_TIME_INTERVAL);
#else
		OMS.OMS_OnRtnTrade(pField);
#endif
	}
	else
	{
		LOGFILE(LOG_WARN, "pTrade == NULL");
	}

}

///报单录入请求响应 CTP
void TraderWrapper::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (pInputOrder != NULL)
	{
		PBOOSTPOOL_MALLOC(pField, memoryMgr.orderaction_pool, CThostFtdcInputOrderFieldEx2);
		memcpy(&pField->field, pInputOrder, sizeof(CThostFtdcInputOrderField));
		memcpy(&pField->pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));

#ifdef LOCK_FREE_OMS
		PushToQueue(ORDER_FIFO_ID, TRADER_ONRSPORDERINSERT, pField, YIELD_TIME_INTERVAL);
#else
		OMS.OMS_OnRspOrderInsert(pField);
#endif

	}
	else
	{
		LOGFILE(LOG_WARN, "pInputOrder == NULL");
	}

}

///报单录入错误回报 exchange
void TraderWrapper::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo)
{
	if (pInputOrder != NULL)
	{
		PBOOSTPOOL_MALLOC(pField, memoryMgr.orderaction_pool, CThostFtdcInputOrderFieldEx2);
		memcpy(&pField->field, pInputOrder, sizeof(CThostFtdcInputOrderField));
		memcpy(&pField->pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));

#ifdef LOCK_FREE_OMS
		PushToQueue(ORDER_FIFO_ID, TRADER_ONERRRTNORDERINSERT, pField, YIELD_TIME_INTERVAL);
#else
		OMS.OMS_OnErrRtnOrderInsert(pField);
#endif

	}
	else
	{
		LOGFILE(LOG_WARN, "pInputOrder == NULL");
	}

}

///报单操作请求响应 CTP
void TraderWrapper::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{

	if (pInputOrderAction != NULL)
	{
		PBOOSTPOOL_MALLOC(pField, memoryMgr.orderaction_pool, CThostFtdcInputOrderActionFieldEx2);
		memcpy(&pField->field, pInputOrderAction, sizeof(CThostFtdcInputOrderActionField));
		memcpy(&pField->pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));

#ifdef LOCK_FREE_OMS
		PushToQueue(ORDER_FIFO_ID, TRADER_ONRSPORDERACTION, pField, YIELD_TIME_INTERVAL);
#else
		OMS.OMS_OnRspOrderAction(pField);
#endif
	}
	else
	{
		LOGFILE(LOG_WARN, "pInputOrderAction == NULL");
	}

}

///报单操作错误回报 exchange
void TraderWrapper::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo)
{

	if (pOrderAction != NULL)
	{
		PBOOSTPOOL_MALLOC(pField, memoryMgr.orderaction_pool, CThostFtdcOrderActionFieldEx2);
		memcpy(&pField->field, pOrderAction, sizeof(CThostFtdcOrderActionField));
		memcpy(&pField->pRspInfo, pRspInfo, sizeof(CThostFtdcRspInfoField));

#ifdef LOCK_FREE_OMS
		PushToQueue(ORDER_FIFO_ID, TRADER_ONERRRTNORDERACTION, pField, YIELD_TIME_INTERVAL);
#else
		OMS.OMS_OnErrRtnOrderAction(pField);
#endif
	}
	else
	{
		LOGFILE(LOG_WARN, "pOrderAction == NULL");
	}

}