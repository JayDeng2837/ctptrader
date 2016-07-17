//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      ITrader.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/18
//////////////////////////////////////////////////////////////////////////

#ifndef _H_ITRADER_H_
#define _H_ITRADER_H_

// c++ header
#include <string>

// third library header

// inner header
#include "strategy_defs.h"

// classname: ITrader
// brief:
class ITrader
{

public:

	virtual void GetLocalID(std::string & localID, int & orderRef) = 0;

	virtual bool PlaceOrder(Signal * signal, const int & orderRef) = 0;

	virtual bool CancelOrder(const char * instrumentid, const int & orderRef) = 0;

};

#endif