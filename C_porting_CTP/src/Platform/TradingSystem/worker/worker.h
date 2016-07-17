  //////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      worker.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/17
//////////////////////////////////////////////////////////////////////////

#ifndef _H_WORKER_H_
#define _H_WORKER_H_

// c++ header

// third library header

// inner header
#include "lcts_defs.h"

// classname: Worker
// brief:
class Worker
{
public:
	Worker() : isRun(true) {};
	virtual ~Worker() {};

	void stop();

	void _sleep(long us = QUERY_TIME_INTERVAL);

	void _yield();

protected:
	bool isRun;
};

#endif