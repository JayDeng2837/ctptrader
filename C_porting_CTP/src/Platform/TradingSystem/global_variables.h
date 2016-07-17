  //////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      global_variables.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/17
//////////////////////////////////////////////////////////////////////////

#ifndef _H_GLOBAL_VARIABLES_H_
#define _H_GLOBAL_VARIABLES_H_

// c++ header
#include <string>
#include <list>
#include <vector>

// third library header
#include <boost/unordered_map.hpp>

#include <boost/thread.hpp>
#include <boost/thread/condition.hpp>

#include "ThostFtdcUserApiStruct.h"

#include "memory_mgr.h"
#include "data_mgr.h"
#include "order_mgr.h"
#include "position_mgr.h"

// inner header

typedef boost::mutex::scoped_lock lc_scoped_lock;

extern DataMgr dc;

extern OrderMgr OMS;

extern PositionMgr positionMgr;

extern MemoryMgr memoryMgr;

extern boost::condition	m_condTaskQueue;

extern boost::mutex		m_exeMutex;

extern boost::mutex		oms_Mutex;

#endif