//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     LcTraderProxy.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/4/8
//////////////////////////////////////////////////////////////////////////
// self header
#include "LcTraderProxy.h"

// c header

// c++ header
#include <string>

// third library header

// inner header
#include "lcts_defs.h"
#include "global_variables.h"
#include "strategy.h"

#include "queue_helper.h"

#include "DateTime.h"

using namespace std;

LcTraderProxy::LcTraderProxy(ITrader * trader) : pTrader(trader)
{
}

LCLONGLONG LcTraderProxy::PlaceOrder(void * strategy, const char * instrumentid, double price, 
									 int qty, Direction direction, OrderType type)
{
	PBOOSTPOOL_MALLOC(pSignal, memoryMgr.signal_pool, Signal);
	pSignal->price = price;
	pSignal->qty = qty;
	pSignal->direction = direction;
	pSignal->orderType = type;
	pSignal->strategy_ptr = strategy;
	pSignal->currentMicroSec_in_queue = GetElapsedTime(GetCurrentTick());
	MY_STRCPY(pSignal->InstrumentID, instrumentid);

#ifdef LOCK_FREE_OMS
	PushToQueue(ORDER_FIFO_ID, TRADER_REQORDERINSERT, pSignal, YIELD_TIME_INTERVAL);
#else
	if (pTrader)
	{
		string LocalOrderID;
		int orderRef;
		pTrader->GetLocalID(LocalOrderID, orderRef);

		OMS.OMS_OrderInsert((LCLONGLONG)pSignal, LocalOrderID, orderRef);

		IStrategy * pStrategy = (IStrategy *) strategy;
		if (pStrategy)
		{
			pStrategy->NoticeOrderInsert((LCLONGLONG)pSignal, LocalOrderID);
		}

		pTrader->PlaceOrder(pSignal, orderRef);
	}
#endif

	return (LCLONGLONG) pSignal;

}

void LcTraderProxy::CancelExternalOrder(const char * instrumentid, const int & orderRef)
{
}

void LcTraderProxy::CancelAllExternalOrders(const char * instrumentid)
{
}

void LcTraderProxy::CancelOrder(void * strategy, const char * instrumentid, LCLONGLONG signal_id)
{
	PBOOSTPOOL_MALLOC(pSignal, memoryMgr.signal_pool, Signal);

	pSignal->orderType = Cancel;
	pSignal->signal_id = signal_id;
	pSignal->strategy_ptr = strategy;
	MY_STRCPY(pSignal->InstrumentID, instrumentid);

#ifdef LOCK_FREE_OMS
	PushToQueue(ORDER_FIFO_ID, TRADER_REQORDERACTION, pSignal, YIELD_TIME_INTERVAL);
#else
	if (pTrader)
	{
		string localOrderId;
		int orderRef = 0;
		bool got = OMS.OMS_InputOrderAction(pSignal->signal_id, localOrderId, orderRef);
		
		IStrategy * pStrategy = (IStrategy *) strategy;
		if (pStrategy)
		{
			pStrategy->NoticeOrderAction((LCLONGLONG)pSignal, localOrderId);
		}

		if (got && orderRef > 0)
		{
			pTrader->CancelOrder(pSignal->InstrumentID, orderRef);
		}
	}
#endif
}