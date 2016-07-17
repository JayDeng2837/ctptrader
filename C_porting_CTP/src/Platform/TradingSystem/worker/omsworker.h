//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      OMSWorker.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/18
//////////////////////////////////////////////////////////////////////////

#ifndef _H_OMSWORKER_H_
#define _H_OMSWORKER_H_

// c++ header

// third library header

// inner header
#include "worker.h"
#include "ITrader.h"

// classname: OMSWorker
// brief:
class OMSWorker : public Worker
{
public:
    OMSWorker(ITrader * trader);
	virtual ~OMSWorker();

	void ProcessOrderQueue();
private:
	ITrader * trader;
};

#endif