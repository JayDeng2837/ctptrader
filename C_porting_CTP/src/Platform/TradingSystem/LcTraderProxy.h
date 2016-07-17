//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      LcTraderProxy.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/8
//////////////////////////////////////////////////////////////////////////

#ifndef _H_LCTRADERPROXY_H_
#define _H_LCTRADERPROXY_H_

// c++ header

// third library header

// inner header
#include "ITraderProxy.h"
#include "ITrader.h"

// classname: LcTraderProxy
// brief:
class LcTraderProxy : public ITraderProxy
{
public:
    LcTraderProxy(ITrader * trader);
	virtual ~LcTraderProxy() {};

	virtual LCLONGLONG PlaceOrder(void * strategy, const char * instrumentid, double price, 
		int qty, Direction direction, OrderType type);

	virtual void CancelOrder(void * strategy, const char * instrumentid, LCLONGLONG signal_id);

	virtual void CancelExternalOrder(const char * instrumentid, const int & orderRef);

	virtual void CancelAllExternalOrders(const char * instrumentid);

private:
	ITrader * pTrader;
};

#endif