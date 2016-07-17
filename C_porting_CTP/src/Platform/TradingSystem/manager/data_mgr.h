//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      data_mgr.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/19
//////////////////////////////////////////////////////////////////////////

#ifndef _H_DATACENTER_H_
#define _H_DATACENTER_H_

// c++ header
#include <string>
#include <list>

// third library header
#include <boost/unordered_map.hpp>
#include "ThostFtdcUserApiStruct.h"

// inner header

struct MarketData;

struct InstrumentTickInfo;

// classname: DataMgr
// brief:

struct DataMgr
{
public:
	DataMgr() {};
	virtual ~DataMgr() {};

	void StoreData(MarketData * marketData);

	void initItem(CThostFtdcInstrumentField * pInstrument);

	boost::unordered_map<std::string, CThostFtdcInstrumentField> instruments;

	std::list<std::string> instrument_list;

	boost::unordered_map<std::string, InstrumentTickInfo *> ticks;
};

#endif