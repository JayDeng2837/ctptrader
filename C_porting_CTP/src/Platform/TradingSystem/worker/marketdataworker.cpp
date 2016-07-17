//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     marketdataworker.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/17
//////////////////////////////////////////////////////////////////////////
// self header
#include "marketdataworker.h"

// c header

// c++ header

// third library header
#include <boost/thread.hpp>
#include "ThostFtdcUserApiStruct.h"

// inner header
#include "fifo_hpq.h"
#include "lcts_defs.h"
#include "lctslog.h"
#include "global_variables.h"

#include "pricing_source.h"

using namespace std;

MarketDataWorker::MarketDataWorker(IStrategy * strategy) : strategy(strategy), pPricingSource(nullptr)
{
}

MarketDataWorker::~MarketDataWorker()
{
}

void MarketDataWorker::InitPricingSource(IPricingSource * ps)
{
	pPricingSource = ps;
}

double step = 0;

//#define DEMO

void MarketDataWorker::ProcessMarketDataQueue()
{
	while (isRun)
	{
		FIFO_ELEM elem;
		int res = extract_hpq(global_queue + MARKET_DATA_FIFO_ID, &elem);
		if (res == SUCCESS)
		{
			switch (elem.type)
			{
			case MD_ONRTNDEPTHMARKETDATA:
			{
				if (elem.data != nullptr)
				{
					MarketData * marketdata = (MarketData *)elem.data;

					dc.StoreData(marketdata);

					LOGFILE(LOG_INFO, "marketdata: %s %d %f %d", marketdata->UpdateTime, marketdata->UpdateMillisec,
						marketdata->LastPrice, marketdata->Volume);

					if (nullptr != strategy)
					{
						strategy->OnTick(marketdata);
					}

					if (nullptr != pPricingSource)
					{
						pPricingSource->GenMarketData(marketdata);
					}
				}

				break;
			}
			default:
				break;
			}
		}
		else
		{

#ifdef DEMO
			if (pPricingSource)
			{
				char * ins[4] = { "if1505", "if1506", "p1505", "o1508" };
				
				GEN_STRUCT(md1, MarketData);
				MY_STRCPY(md1.Symbol, ins[((int)(10 * step)) % 4]);
				MY_STRCPY(md1.TradingDay, "20150421");
				MY_STRCPY(md1.UpdateTime, "00:00:01");
				md1.UpdateMillisec = 120;

				step += 0.1;
				md1.LastPrice = (2.1 + step) / 1000;
				md1.Volume = ((int)(10 * step)) % 10000;
				md1.OpenInterest = 1 + (int)step;

				pPricingSource->GenMarketData(&md1);
			}

#endif

			strategy->OnIdle();
		}

#ifdef NO_TRADER
		_sleep(QUERY_TIME_INTERVAL);
#endif

		_yield();
	}
}
