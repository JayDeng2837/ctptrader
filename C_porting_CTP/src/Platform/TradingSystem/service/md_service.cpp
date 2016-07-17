//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     md_service.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/4/21
//////////////////////////////////////////////////////////////////////////
// self header
#include "md_service.h"

// c header

// c++ header
#include <string>
#include <iostream>
#include <fstream>

// third library header
#include "market_data.pb.h"

// inner header

#define MAX_SIZE 4096

using namespace std;

MarketDataService::MarketDataService()
{
}

MarketDataService::~MarketDataService()
{
}

void MarketDataService::GenMarketData(MarketData * marketdata)
{
	if (isInit)
	{
		MarketDataMsg msg;
		msg.set_symbol(marketdata->Symbol);  // 1
		msg.set_tradingday(marketdata->TradingDay);  // 2

		msg.set_updatetime(marketdata->UpdateTime);  // 3
		msg.set_updatemillisec(marketdata->UpdateMillisec);  // 4

		msg.set_lastprice(marketdata->LastPrice);  // 5

		msg.set_openinterest(marketdata->OpenInterest);  // 6
		
		msg.set_deltaopeninsterest(marketdata->deltaOpenInsterest);  // 7
		msg.set_upperlimitprice(marketdata->UpperLimitPrice);  // 8
		msg.set_lowerlimitprice(marketdata->LowerLimitPrice);  // 9
		
		msg.set_volume(marketdata->Volume);  // 10
		
		msg.set_accvolume(marketdata->accVolume);  // 11
		msg.set_turnover(marketdata->Turnover);  // 12
		msg.set_accturnover(marketdata->accTurnover);  // 13
		msg.set_askprice(marketdata->AskPrice);  // 14
		msg.set_askvolume(marketdata->AskVolume);  // 15
		msg.set_bidprice(marketdata->BidPrice);  // 16
		msg.set_bidvolume(marketdata->BidVolume);  // 17
		msg.set_avgpriceintick(marketdata->AvgPriceInTick);  // 18
		msg.set_precloseprice(marketdata->PreClosePrice);  // 19
		msg.set_presettlementprice(marketdata->PreSettlementPrice);  // 20
		msg.set_preopeninterest(marketdata->PreOpenInterest);  // 21
		msg.set_averageprice(marketdata->AveragePrice);  // 22
			
		const string & temp = msg.SerializeAsString();
		
		SendMsg(marketdata->Symbol, ZMQ_SM);
		SendMsg(temp);
		
	}
}