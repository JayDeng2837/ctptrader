  //////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      queryworker.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/16
//////////////////////////////////////////////////////////////////////////

#ifndef _H_QUERYWORKER_H_
#define _H_QUERYWORKER_H_

// c++ header

// third library header

// inner header
#include "worker.h"
class MDWrapper;
class TraderWrapper;
class IStrategy;

// classname: QueryWorker
// brief:
class QueryWorker : public Worker
{
public:
	QueryWorker(MDWrapper * pMd, TraderWrapper * pTrader, IStrategy * pStrategy);
    virtual ~QueryWorker();

	void ProcessQueryQueue();

	void stop();

private:
	
	MDWrapper * pMd;

	TraderWrapper * pTrader;

	IStrategy * pStrategy;
};

#endif