//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      memory_mgr.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/25
//////////////////////////////////////////////////////////////////////////

#ifndef _H_MEMORY_MGR_H_
#define _H_MEMORY_MGR_H_

// c++ header

// third library header
#include <boost/pool/pool.hpp>

// inner header
#include "lcts_defs.h"

// classname: MemoryMgr
// brief:
struct MemoryMgr
{
public:
	MemoryMgr();
	virtual ~MemoryMgr();

	boost::pool<> * marketdata_pool;

	boost::pool<> * InstrumentTickInfo_pool;

	boost::pool<> * signal_pool;

	boost::pool<> * inputorder_pool;

	boost::pool<> * inputorderaction_pool;

	boost::pool<> * orderaction_pool;

	boost::pool<> * order_pool;

	boost::pool<> * trade_pool;

	boost::pool<> * errRspInfo_pool;

	//---

	boost::pool<> * int_pool;

	boost::pool<> * double_pool;

	//new
	boost::pool<> * instrument_pool;

private:

	void deletePool(boost::pool<> * pPool);

};

#endif