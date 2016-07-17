//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      big_order_strategy.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/24
//////////////////////////////////////////////////////////////////////////

#ifndef _H_BIG_ORDER_STRATEGY_H_
#define _H_BIG_ORDER_STRATEGY_H_

// c++ header

// third library header

// inner header
#include "hft_strategy.h"

#include "ring_queue.h"

// classname: BigOrderStrategy
// brief:
class BigOrderStrategy : public HFTStrategyBase
{
public:
	BigOrderStrategy() {};
	virtual ~BigOrderStrategy() {};

public:

	virtual void OnTick(MarketData * marketdata);

	virtual void OnIdle();
	
	virtual void OnInit();

public:

	virtual void NotifyOrderPlacing(LCLONGLONG signal_id, std::string local_orderid);

	virtual void NotifyOrderCancelling(LCLONGLONG signal_id, std::string system_id);

	//from CTP
	virtual void OnOrderCancelled(LCLONGLONG signal_id, std::string local_orderid);

private:

	int kRatio;

	double average_vb;

};

#endif