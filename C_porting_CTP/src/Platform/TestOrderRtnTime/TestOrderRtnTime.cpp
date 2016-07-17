//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     TestOrderRtnTime.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/24
//////////////////////////////////////////////////////////////////////////
// self header
#include "TestOrderRtnTime.h"
#include "strategy_macros.h"

// c header

// c++ header

// third library header
#include <boost/thread.hpp>

#include "Log.h"

// inner header

DECLARE_STRATEGY_CREATOR(TestOrderRtnTime);

TestOrderRtnTime::TestOrderRtnTime()
{
	m = 0;

	id = 0;

	id2 = 0;

	MMM = 4;
}

TestOrderRtnTime::~TestOrderRtnTime()
{
	log(LOG_INFO, "TestOrderRtnTime::~TestOrderRtnTime() %d", 123);
	log(LOG_INFO, "TestOrderRtnTime::~TestOrderRtnTime() %d", 456);
	log(LOG_INFO, "TestOrderRtnTime::~TestOrderRtnTime() %d", 789);
}

void TestOrderRtnTime::OnTick(MarketData * marketdata)
{

	if (marketdata)
	{
		HFTStrategyBase::OnTick(marketdata);

		return;

		switch (this->GetStatus())
		{
		case PlacingOrder:
		{
			break;
		}
		case OrderCancelled:
		{
			break;
		}
		case Idle:
		{
			GetProxy()->CancelAllExternalOrders(marketdata->Symbol);
			if (marketdata->AskPrice > marketdata->LowerLimitPrice && marketdata->AskPrice <= 56.7
				&& marketdata->AskVolume > 0)
			{
			}
			break;
		}
		default:
			break;
		}
	}

	return;

	if (strcmp(marketdata->Symbol, "fb1604") == 0)
	{
		//assert(!(marketdata->AskPrice < 0.05 && marketdata->AskVolume == 0));
		if (marketdata->AskPrice > marketdata->LowerLimitPrice && marketdata->AskPrice <= 56.7
			&& marketdata->AskVolume > 0)
		{
			GetProxy()->CancelAllExternalOrders(marketdata->Symbol);
			id = GetProxy()->PlaceOrder(this, marketdata->Symbol, marketdata->AskPrice, 1, BuyToCover, Limit);

			boost::this_thread::sleep(boost::posix_time::microseconds(2000000));

			LOGFILE(LOG_ALERT, "TestOrderRtnTime BuyToCover Order Placed!");

			assert(0);
		}
		else
		{
			assert(!(marketdata->AskPrice > 0.05 && marketdata->AskVolume > 0));
		}
	}

	//strategy calculation
	/*
	#ifdef USE_IOC
	id = GetProxy()->PlaceOrder(this, marketdata->Symbol, marketdata->UpperLimitPrice, 1, SellShort, IOC);
	#else
	if (m == 0)
	{
	id = GetProxy()->PlaceOrder(this, marketdata->Symbol, marketdata->LowerLimitPrice, 1, BuyToCover, Limit);
	id2 = GetProxy()->PlaceOrder(this, marketdata->Symbol, marketdata->UpperLimitPrice, 1, SellShort, Limit);
	}
	else if (m == MMM)
	{
	if (local_orders.find(id) != local_orders.end())
	{
	GetProxy()->CancelOrder(this, marketdata->Symbol, id);
	GetProxy()->CancelOrder(this, marketdata->Symbol, id2);
	}

	m = -MMM;
	}

	m++;
	#endif

	*/
	//end of strategy
}

void TestOrderRtnTime::OnIdle()
{
}

void TestOrderRtnTime::OnInit()
{
}

void TestOrderRtnTime::NotifyOrderPlacing(LCLONGLONG signal_id, std::string local_orderid)
{
	HFTStrategyBase::NotifyOrderPlacing(signal_id, local_orderid);
}

void TestOrderRtnTime::NotifyOrderCancelling(LCLONGLONG signal_id, std::string system_id)
{
	HFTStrategyBase::NotifyOrderCancelling(signal_id, system_id);
}

void TestOrderRtnTime::OnOrderCancelled(LCLONGLONG signal_id, std::string local_orderid)
{
	HFTStrategyBase::OnOrderCancelled(signal_id, local_orderid);
}