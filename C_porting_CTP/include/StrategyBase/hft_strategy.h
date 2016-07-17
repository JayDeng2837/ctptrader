//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      hft_strategy.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/18
//////////////////////////////////////////////////////////////////////////

#ifndef _H_HFT_STRATEGY_H_
#define _H_HFT_STRATEGY_H_

// c++ header
#include <map>

// third library header
#include <tbb/concurrent_unordered_map.h>

// inner header
#include "strategy.h"
#include "ITraderProxy.h"

// classname: HFTStrategy
// brief:
class HFTStrategyBase : public IStrategy
{
public:

	LC_API_API HFTStrategyBase();
	LC_API_API virtual ~HFTStrategyBase();

protected:

	//marketdata callback
public:

	LC_API_API void RegTraderProxy(ITraderProxy * proxy);

	LC_API_API virtual void OnTick(MarketData * marketdata);

	LC_API_API virtual void OnIdle() {};

	LC_API_API virtual void OnInit() {};

	LC_API_API virtual void OnSuspend() {};

	LC_API_API virtual void OnRestart() {};

	LC_API_API virtual void OnExit() {};

	//OMS callback
public:

	LC_API_API virtual void NotifyOrderPlacing(LCLONGLONG signal_id, std::string local_orderid);

	LC_API_API virtual void NotifyOrderCancelling(LCLONGLONG signal_id, std::string system_id);

	LC_API_API virtual void OnOrderCancelled(LCLONGLONG signal_id, std::string local_orderid);
	
	LC_API_API void RegLogService(LogService * logService);

private:

	ITraderProxy * proxy;

	LogService * logService;

	volatile StrategyStatus status;

protected:

	tbb::concurrent_unordered_map<LCLONGLONG, std::string> local_orders;

protected:

	LC_API_API LC_BOOL log(int pri, const char * fmt, ...);

	LC_API_API ITraderProxy * GetProxy() const
	{
		return proxy;
	}

	LC_API_API void ChangeStatusTo(StrategyStatus newStatus);

	LC_API_API const StrategyStatus GetStatus() const
	{
		return status;
	}

	LC_API_API std::string getName() 
	{
		return "HFTStrategy";
	}

};

#endif