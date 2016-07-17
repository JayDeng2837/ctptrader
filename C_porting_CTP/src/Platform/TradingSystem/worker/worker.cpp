//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     worker.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/24
//////////////////////////////////////////////////////////////////////////
// self header
#include "worker.h"

// c header

// c++ header

// third library header
#include <boost/thread.hpp>

// inner header

void Worker::stop()
{
	isRun = false;
}

void Worker::_sleep(long us)
{
	boost::this_thread::sleep(boost::posix_time::microseconds(us));
}

void Worker::_yield()
{
	//_sleep(YIELD_TIME_INTERVAL);
	//boost::this_thread::yield(); 
}