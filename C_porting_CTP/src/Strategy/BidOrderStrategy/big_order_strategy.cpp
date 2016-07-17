//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     big_order_strategy.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/24
//////////////////////////////////////////////////////////////////////////
// self header
#include "big_order_strategy.h"
#include "strategy_macros.h"

// c header

// c++ header

// third library header

// inner header

DECLARE_STRATEGY_CREATOR(BigOrderStrategy);

void BigOrderStrategy::OnTick(MarketData * marketdata)
{
	HFTStrategyBase::OnTick(marketdata);
	//strategy calculation	

	//end of strategy
}

void BigOrderStrategy::OnIdle()
{

}

void BigOrderStrategy::OnInit() 
{
	kRatio = 6;
}

void BigOrderStrategy::NotifyOrderPlacing(LCLONGLONG signal_id, std::string local_orderid)
{
	HFTStrategyBase::NotifyOrderPlacing(signal_id, local_orderid);
}

void BigOrderStrategy::NotifyOrderCancelling(LCLONGLONG signal_id, std::string system_id)
{
	HFTStrategyBase::NotifyOrderCancelling(signal_id, system_id);
}

void BigOrderStrategy::OnOrderCancelled(LCLONGLONG signal_id, std::string system_id)
{
	HFTStrategyBase::OnOrderCancelled(signal_id, system_id);
}