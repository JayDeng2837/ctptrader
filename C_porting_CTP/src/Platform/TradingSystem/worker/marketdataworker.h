  //////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      marketdataworker.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/17
//////////////////////////////////////////////////////////////////////////

#ifndef _H_MARKETDATAWORKER_H_
#define _H_MARKETDATAWORKER_H_

// c++ header

// third library header

// inner header
#include "worker.h"
#include "strategy.h"

class IPricingSource;

// classname: MarketDataWorker
// brief:
class MarketDataWorker : public Worker
{
public:
    MarketDataWorker(IStrategy * strategy);

	virtual ~MarketDataWorker();

public:

	void InitPricingSource(IPricingSource * ps);

	void ProcessMarketDataQueue();

private:

	IPricingSource * pPricingSource;
	
	IStrategy * strategy;

};

#endif