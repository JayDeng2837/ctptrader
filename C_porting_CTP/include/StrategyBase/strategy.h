//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      strategy.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/18
//////////////////////////////////////////////////////////////////////////

#ifndef _H_STRATEGY_H_
#define _H_STRATEGY_H_

// c++ header
#include <string>

// third library header

// inner header
#include "Base.h"
#include "strategy_defs.h"

class LogService;

// classname: IStrategy
// brief:
class IStrategy
{
public:
	LC_API_API IStrategy() {};
	LC_API_API virtual ~IStrategy() {};

	//marketdata callback
public:

	LC_API_API virtual void OnTick(MarketData * marketdata) = 0;

	LC_API_API virtual void OnIdle() = 0;

	LC_API_API virtual void OnInit() = 0;
	
	LC_API_API virtual void OnSuspend() = 0;

	LC_API_API virtual void OnRestart() = 0;

	LC_API_API virtual void OnExit() = 0;

	//OMS callback
public:

	LC_API_API virtual void NotifyOrderPlacing(LCLONGLONG signal_id, std::string local_orderid) = 0;

	LC_API_API virtual void NotifyOrderCancelling(LCLONGLONG signal_id, std::string system_id) = 0;

	//from CTP
	LC_API_API virtual void OnOrderCancelled(LCLONGLONG signal_id, std::string local_orderid) = 0;

public:
	//others

	LC_API_API virtual void RegLogService(LogService * logService) = 0;

	LC_API_API virtual std::string getName() = 0;

};

#endif