//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      TraderProxy.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/8
//////////////////////////////////////////////////////////////////////////

#ifndef _H_TRADERPROXY_H_
#define _H_TRADERPROXY_H_

// c++ header

// third library header

// inner header
#include "Base.h"

#include "strategy_defs.h"

// classname: TraderProxy
// brief:
class ITraderProxy
{
public:
	LC_API_API ITraderProxy() {}
	LC_API_API virtual ~ITraderProxy() {}

public:

	LC_API_API virtual LCLONGLONG PlaceOrder(void * strategy, const char * instrumentid, double price, 
		int qty, Direction direction, OrderType type) = 0;

	LC_API_API virtual void CancelOrder(void * strategy, const char * instrumentid, LCLONGLONG signal_id) = 0;

	LC_API_API virtual void CancelExternalOrder(const char * instrumentid, const int & orderRef) = 0;

	LC_API_API virtual void CancelAllExternalOrders(const char * instrumentid) = 0;

};

#endif