//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      pricing_source.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/21
//////////////////////////////////////////////////////////////////////////

#ifndef _H_PRICING_SOURCE_H_
#define _H_PRICING_SOURCE_H_

// c++ header

// third library header

// inner header
#include "strategy_defs.h"

// classname: IPricingSource
// brief:
class IPricingSource
{

public:

	virtual void GenMarketData(MarketData * marketdata) = 0;

};

#endif