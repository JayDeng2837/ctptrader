//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      TestOrderRtnTime.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/24
//////////////////////////////////////////////////////////////////////////

#ifndef _H_TESTORDERRTNTIME_H_
#define _H_TESTORDERRTNTIME_H_

// c++ header

// third library header

// inner header
#include "hft_strategy.h"

// classname: TestOrderRtnTime
// brief:
class TestOrderRtnTime : public HFTStrategyBase
{
public:
	TestOrderRtnTime();
	virtual ~TestOrderRtnTime();

public:

	virtual void OnTick(MarketData * marketdata);

	virtual void OnIdle();
	
	virtual void OnInit();

public:

	virtual void NotifyOrderPlacing(LCLONGLONG signal_id, std::string local_orderid);

	virtual void NotifyOrderCancelling(LCLONGLONG signal_id, std::string system_id);

	virtual void OnOrderCancelled(LCLONGLONG signal_id, std::string local_orderid);

private:

	int m;

	LCLONGLONG id;

	LCLONGLONG id2;

	int MMM;

};

#endif