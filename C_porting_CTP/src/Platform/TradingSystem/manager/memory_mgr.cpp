//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     memory_mgr.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/25
//////////////////////////////////////////////////////////////////////////
// self header
#include "memory_mgr.h"

// c header

// c++ header

// third library header

// inner header
#include "lcts_defs.h"

MemoryMgr::MemoryMgr()
{
	NEW_BOOSTPOOL(marketdata_pool, MarketData);
	NEW_BOOSTPOOL(InstrumentTickInfo_pool, InstrumentTickInfo);
	NEW_BOOSTPOOL(signal_pool, Signal);

	NEW_BOOSTPOOL(inputorder_pool, CThostFtdcInputOrderFieldEx2);
	NEW_BOOSTPOOL(inputorderaction_pool, CThostFtdcInputOrderActionFieldEx2);
	NEW_BOOSTPOOL(orderaction_pool, CThostFtdcOrderActionFieldEx2);

	NEW_BOOSTPOOL(order_pool, CThostFtdcOrderFieldEx);
	
	NEW_BOOSTPOOL(trade_pool, CThostFtdcTradeField);
	NEW_BOOSTPOOL(errRspInfo_pool, CThostFtdcRspInfoField);

	NEW_BOOSTPOOL(int_pool, TThostFtdcVolumeType);
	NEW_BOOSTPOOL(double_pool, TThostFtdcPriceType);

	//new
	NEW_BOOSTPOOL(instrument_pool, char);
}

void MemoryMgr::deletePool(boost::pool<> * pPool)
{
	if (pPool)
	{
		delete pPool;
		pPool = nullptr;
	}
}

MemoryMgr::~MemoryMgr() 
{
	deletePool(marketdata_pool);
	deletePool(InstrumentTickInfo_pool);
	deletePool(signal_pool);
	deletePool(inputorder_pool);
	deletePool(inputorderaction_pool);
	deletePool(orderaction_pool);
	deletePool(order_pool);
	deletePool(trade_pool);
	deletePool(errRspInfo_pool);

	deletePool(int_pool);
	deletePool(double_pool);
	
	//new
	deletePool(instrument_pool);
}