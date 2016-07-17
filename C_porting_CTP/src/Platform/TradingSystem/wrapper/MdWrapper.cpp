//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     MdWrapper.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/16
//////////////////////////////////////////////////////////////////////////
// self header
#include "MdWrapper.h"

// c header

// c++ header
#include <fstream>

// third library header
#include <boost/filesystem.hpp>
#include "lctslog.h"
#include "ctp_cmessage.h"

// inner header
#include "queue_helper.h"
#include "global_variables.h"

using namespace std;

MDWrapper::MDWrapper(const string username, const string pwd, const string front_addr, const std::string brokerID) 
	:AbsWrapper(username, pwd, front_addr, brokerID)
{
	string con_path = folder_path + "/md_";
	create_directories(boost::filesystem::path(folder_path));
	pMdApi = CThostFtdcMdApi::CreateFtdcMdApi(con_path.c_str(), true, false);
	pMdApi->RegisterSpi(this);
	pMdApi->RegisterFront((char *)front_addr.c_str());
}

MDWrapper::~MDWrapper()
{
	if (pMdApi)
	{
		pMdApi->RegisterSpi(nullptr);
		if (isInited)
			pMdApi->Release();
		pMdApi = nullptr;
	}
}

bool MDWrapper::Init()
{
	isInited = true;
	pMdApi->Init();
	return false;
}

void MDWrapper::OnFrontConnected()
{
	LcSetThreadAffinityMask(CTP_MD_CORE, GetCurrentThreadHandle());
	PushToQueue(QUERY_FIFO_ID, MD_ONFRONTCONNECTED, DUMMY_DATA, YIELD_TIME_INTERVAL);
	ReqUserLogin();
}

void MDWrapper::ReqUserLogin()
{
	if (pMdApi)
	{
		GEN_STRUCT(field, CThostFtdcReqUserLoginField);
		MY_STRCPY(field.UserID, username.c_str());
		MY_STRCPY(field.Password, pwd.c_str());
		MY_STRCPY(field.BrokerID, brokerID.c_str());
		pMdApi->ReqUserLogin(&field, NewRequestID());
	}
}

void MDWrapper::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, 
							   int nRequestID, bool bIsLast)
{
	PushToQueue(QUERY_FIFO_ID, MD_ONRSPUSERLOGIN, pRspUserLogin, YIELD_TIME_INTERVAL);
	SubInstruments(dc.instrument_list);
};

void MDWrapper::SubInstrument(string instrument)
{
	if (pMdApi)
	{
		char * pInstrument = (char *)instrument.data();
		char ** ppInstr = &pInstrument;
		pMdApi->SubscribeMarketData(ppInstr, 1);
	}
}

void MDWrapper::SubInstruments(list<string> instruments)
{
	if (pMdApi)
	{
		int count = instruments.size();
		char ** pInstruments = new char * [count];
		list<string>::iterator itor = instruments.begin();
		int i = 0;
		for(;itor != instruments.end(); itor++)
		{
			pInstruments[i++] = (char *)itor->c_str(); 
		}

		pMdApi->SubscribeMarketData(pInstruments, count);
		delete [] pInstruments;
	}
}

void MDWrapper::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	LOGFILE(LOG_INFO, "OnRspSubMarketData");
}

void fmtNumber(double & val, const double default_val)
{
	if (val == DBL_MAX || val == DBL_MIN)
	{
		val = default_val;
	}
}

void MDWrapper::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	PBOOSTPOOL_MALLOC(pMarketData, memoryMgr.marketdata_pool, MarketData);

	//cpy 2 marketData
	MY_STRCPY(pMarketData->Symbol, pDepthMarketData->InstrumentID);
	MY_STRCPY(pMarketData->TradingDay, pDepthMarketData->TradingDay);
	MY_STRCPY(pMarketData->UpdateTime, pDepthMarketData->UpdateTime);
	pMarketData->UpdateMillisec = pDepthMarketData->UpdateMillisec;

	pMarketData->PreClosePrice = pDepthMarketData->PreClosePrice;
	pMarketData->PreSettlementPrice = pDepthMarketData->PreSettlementPrice;
	pMarketData->PreOpenInterest = pDepthMarketData->PreOpenInterest;

	pMarketData->LastPrice = pDepthMarketData->LastPrice;
	fmtNumber(pMarketData->LastPrice, 0);

	pMarketData->accTurnover = pDepthMarketData->Turnover;
	pMarketData->accVolume = pDepthMarketData->Volume;
	pMarketData->OpenInterest = pDepthMarketData->OpenInterest;

	pMarketData->UpperLimitPrice = pDepthMarketData->UpperLimitPrice;
	pMarketData->LowerLimitPrice = pDepthMarketData->LowerLimitPrice;

	pMarketData->AskPrice = pDepthMarketData->AskPrice1;
	fmtNumber(pMarketData->AskPrice, 0);
	pMarketData->AskVolume = pDepthMarketData->AskVolume1;
	pMarketData->BidPrice = pDepthMarketData->BidPrice1;
	fmtNumber(pMarketData->BidPrice, 0);
	pMarketData->BidVolume = pDepthMarketData->BidVolume1;
	pMarketData->AveragePrice = pDepthMarketData->AveragePrice;

	PushToQueue(MARKET_DATA_FIFO_ID, MD_ONRTNDEPTHMARKETDATA, pMarketData, YIELD_TIME_INTERVAL);
}