//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     datacenter.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/19
//////////////////////////////////////////////////////////////////////////
// self header
#include "data_mgr.h"

// c header

// c++ header
#include <string>

// third library header

// inner header
#include "Base.h"
#include "global_variables.h"

#include "lcts_defs.h"

using namespace std;

void DataMgr::StoreData(MarketData * marketData)
{
	InstrumentTickInfo * pTickInfo = ticks.at(marketData->Symbol);

	TThostFtdcVolumeType volume = 0;
	TThostFtdcPriceType av_price = 0;
	TThostFtdcPriceType turnover = 0;
	int deltaOI = 0;

	const int & counter = pTickInfo->counter;

	if (counter > 0)
	{
		MarketData * currMarketData = pTickInfo->data_ptr[counter - 1];
		volume = marketData->accVolume - currMarketData->accVolume;
		if (volume > 0)
		{
			turnover = currMarketData->accTurnover - currMarketData->accTurnover;
			av_price = turnover / volume;
		}
		deltaOI = (int)(marketData->OpenInterest - currMarketData->OpenInterest);
	}

	pTickInfo->data_ptr[counter] = marketData;
	pTickInfo->volumes[counter] = volume;
	pTickInfo->avg_price_per_tick[counter] = av_price;
	
	marketData->Volume = volume;
	marketData->Turnover = turnover;
	marketData->AvgPriceInTick = av_price;
	marketData->deltaOpenInsterest = deltaOI;
	
	pTickInfo->counter++;
}

void DataMgr::initItem(CThostFtdcInstrumentField * pInstrument)
{
	const string & Instrument = pInstrument->InstrumentID;
	instruments[Instrument] = *pInstrument;
	instrument_list.push_back(Instrument);
	PBOOSTPOOL_MALLOC(pInfo, memoryMgr.InstrumentTickInfo_pool, InstrumentTickInfo);
	ticks[Instrument] = pInfo;
}
