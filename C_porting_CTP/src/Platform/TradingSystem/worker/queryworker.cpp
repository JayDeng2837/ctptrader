//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     queryworker.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/16
//////////////////////////////////////////////////////////////////////////
// self header
#include "queryworker.h"

// c header

// c++ header

// third library header
#include <boost/thread.hpp>

// inner header
#include "fifo_hpq.h"
#include "lctslog.h"
#include "global_variables.h"

#include "MDWrapper.h"
#include "TraderWrapper.h"
#include "strategy.h"

using namespace std;

QueryWorker::QueryWorker(MDWrapper * pMd, TraderWrapper * pTrader, IStrategy * pStrategy) 
	: pMd(pMd), pTrader(pTrader), pStrategy(pStrategy)
{}

QueryWorker::~QueryWorker()
{}

void QueryWorker::stop()
{
	Worker::stop();
	//m_condTaskQueue.notify_all();
}

void QueryWorker::ProcessQueryQueue()
{
	while (isRun)
	{
		GEN_STRUCT(elem, FIFO_ELEM);
		int res = extract_hpq(global_queue + QUERY_FIFO_ID, &elem);
		if (res == SUCCESS)
		{
			lc_scoped_lock lock(m_exeMutex);

			switch (elem.type)
			{
			case MD_INIT:
				LOGFILE(LOG_INFO, "MD_INIT");
				break;
			case MD_ONFRONTCONNECTED:
				LOGFILE(LOG_INFO, "MD_ONFRONTCONNECTED");
				break;
			case MD_ONRSPUSERLOGIN:
				LOGFILE(LOG_INFO, "MD_ONRSPUSERLOGIN");
				break;
				//-------------------------------
			case TRADER_INIT:
				LOGFILE(LOG_INFO, "TRADER_INIT");
				break;
			case TRADER_ONFRONTCONNECTED:
				LOGFILE(LOG_INFO, "TRADER_ONFRONTCONNECTED");
				break;
			case TRADER_ONFRONTDISCONNECTED:
				LOGFILE(LOG_INFO, "TRADER_ONFRONTDISCONNECTED");
				break;
			case TRADER_ONRSPUSERLOGIN:
				LOGFILE(LOG_INFO, "TRADER_ONRSPUSERLOGIN");
				break;
			case TRADER_REQQRYORDER:
			{
				LOGFILE(LOG_WARN, "TRADER_REQQRYORDER");
				char * pInstrument = (char *)elem.data;
				if (pTrader)
				{
					pTrader->ReqQryOrder(pInstrument);
				}
				break;
			}
			case TRADER_ONRSPQRYINVESTORPOSITION:
			{
				LOGFILE(LOG_INFO, "TRADER_ONRSPQRYINVESTORPOSITION");
				pStrategy->OnInit();
				pMd->Init();

				isRun = false;
				// m_condTaskQueue.wait(lock);
				break;
			}
			case TRADER_ONRSPQRYTRADINGACCOUNT:
			{
				break;
			}
			case TRADER_ONRSPQRYINSTRUMENT:
			{
				LOGFILE(LOG_INFO, "TRADER_ONRSPQRYINSTRUMENT");
				break;
			}
			default:
				break;
			}
		}

		_sleep();
	}
}