//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     hft_strategy.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/18
//////////////////////////////////////////////////////////////////////////
// self header
#include "hft_strategy.h"

// c header
#include <signal.h>

// c++ header

// third library header

// inner header
#include "Base.h"
#include "Log.h"
#include "DateTime.h"

#include "log_service.h"
#include "log_info.pb.h"

using namespace std;

static const char * aPriNameShort[] = {
	"EMRG",
	"ALRT",
	"CRIT",
	"ERR ",
	"WARN",
	"NOTC",
	"INFO",
	"DBUG",
	"DSTK",
	"DOP ",
	"DHB ",
	0
};

HFTStrategyBase::HFTStrategyBase() : status(Idle), proxy(nullptr), logService(nullptr)
{
}

HFTStrategyBase::~HFTStrategyBase()
{
	log(LOG_ALERT, "HFTStrategyBase::~HFTStrategyBase() %d", 123);
	log(LOG_ALERT, "HFTStrategyBase::~HFTStrategyBase() %d", 456);
	log(LOG_ALERT, "HFTStrategyBase::~HFTStrategyBase() %d", 789);
}

void HFTStrategyBase::ChangeStatusTo(StrategyStatus newStatus)
{
	status = newStatus;
}

void HFTStrategyBase::RegTraderProxy(ITraderProxy * proxy)
{
	this->proxy = proxy;
}

void HFTStrategyBase::RegLogService(LogService * _logService)
{
	this->logService = _logService;
}

void HFTStrategyBase::OnTick(MarketData * marketdata)
{
	if (marketdata)
	{
		log(LOG_ALERT, "HFTStrategyBase::OnTick \n%s %s %d LastPrice:%f [Ask %f:%d / %d:%f Bid]",
			marketdata->Symbol, marketdata->UpdateTime, marketdata->UpdateMillisec, marketdata->LastPrice,
			marketdata->AskPrice, marketdata->AskVolume, marketdata->BidVolume, marketdata->BidPrice);
	}
}

void HFTStrategyBase::NotifyOrderPlacing(LCLONGLONG signal_id, std::string local_orderid)
{
	local_orders[signal_id] = local_orderid;
	ChangeStatusTo(PlacingOrder);
}

void HFTStrategyBase::OnOrderCancelled(LCLONGLONG signal_id, std::string local_orderid)
{
	local_orders[signal_id] = local_orderid;
	ChangeStatusTo(OrderCancelled);
}

void HFTStrategyBase::NotifyOrderCancelling(LCLONGLONG signal_id, std::string system_id)
{
	ChangeStatusTo(CancellingOrder);
}

LC_BOOL HFTStrategyBase::log(int pri, const char * fmt, ...)
{

	if (nullptr != logService)
	{
		va_list argList;
		va_start(argList, fmt);

		int i;
		char aDateBuf[DATEBUF_SIZE];
		char buf[1024];
		get_curtime_l(aDateBuf);
		i = sprintf(buf, "%s %s: ",
			aDateBuf, aPriNameShort[pri]);
		vsnprintf(&buf[i], sizeof(buf) - i, fmt, argList);

		_log_impl2_vargs(pri, fmt, argList);
		va_end(argList);

		LogInfo li;
		li.set_log_str(buf);
		li.set_pri(pri);

		char temp[5];

		MY_SPRINTF(temp, "%d", pri);

		logService->SendMsg(temp, ZMQ_SM);
		logService->SendMsg(li.SerializeAsString(), ZMQ_NB);

	}
	return TRUE;
}