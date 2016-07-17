//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      md_service.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/21
//////////////////////////////////////////////////////////////////////////

#ifndef _H_MD_SERVICE_H_
#define _H_MD_SERVICE_H_

// c++ header

// third library header

// inner header
#include "base_service.h"
#include "pricing_source.h"

// classname: MarketDataService
// brief:
class MarketDataService : public BaseService, public IPricingSource
{

public:
    MarketDataService();
	virtual ~MarketDataService();

public:

	void GenMarketData(MarketData * marketdata);
};

#endif