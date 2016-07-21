//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      OrderMgr.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/19
//////////////////////////////////////////////////////////////////////////

#ifndef _H_ORDERMGR_H_
#define _H_ORDERMGR_H_

// c++ header
#include <string>

// third library header
#include <tbb/concurrent_unordered_map.h>
#include <boost/unordered_map.hpp>
#include "ThostFtdcUserApiStruct.h"

// inner header
#include "lcts_defs.h"

#include "recordable.h"

struct LocalKey
{
	int orderRef;
	std::string localOrderId;
};

// classname: OrderMgr
// brief:
class OrderMgr : public IRecordable
{
public:
	OrderMgr() :FRONT_ID(0), SESSION_ID(0) {};
	virtual ~OrderMgr() {};

	void Init(int FRONT_ID, int SESSION_ID);

	void OMS_OnRspQryOrder(CThostFtdcOrderFieldEx * pOrder);

	void OMS_OnRtnOrder(CThostFtdcOrderFieldEx * pOrder);

	void OMS_OnRtnTrade(CThostFtdcTradeField * pTrade);

	void OMS_OnErrRtnOrderInsert(CThostFtdcInputOrderFieldEx2 * pInputOrder);

	void OMS_OnErrRtnOrderAction(CThostFtdcOrderActionFieldEx2 * pOrderAction);

	void OMS_OnRspOrderInsert(CThostFtdcInputOrderFieldEx2 * pInputOrder);

	void OMS_OnRspOrderAction(CThostFtdcInputOrderActionFieldEx2 * pInputOrderAction);

	void OMS_OrderInsert(LCLONGLONG pSignal_Addr, std::string local_orderid, int orderRef);

	bool OMS_InputOrderAction(LCLONGLONG pSignal_ptr, std::string & localOrderId, int & orderRef);

public:

	void WriteToDisk(const std::string & path);

private:

#ifdef LOCK_FREE_OMS

	typedef boost::unordered_map<LCLONGLONG, LocalKey>::iterator SIGNAL_ORDER_ITOR;

	typedef boost::unordered_map<std::string, LCLONGLONG>::iterator ORDER_SIGNAL_ITOR;

	typedef boost::unordered_map<std::string, CThostFtdcOrderFieldEx *>::iterator ORDER_ITOR;

	typedef boost::unordered_map<std::string, std::list<CThostFtdcOrderFieldEx *> >::iterator ORDER_LIST_ITOR;

	typedef boost::unordered_map<std::string, std::list<CThostFtdcTradeField *> >::iterator TRADE_ITOR;

	boost::unordered_map<LCLONGLONG, LocalKey> pSignal_orderId_Map;

	boost::unordered_map<std::string, LCLONGLONG> orderId_pSignal_Map;

	boost::unordered_map<std::string, CThostFtdcOrderFieldEx *> orderCenter;

	boost::unordered_map<std::string, std::list<CThostFtdcOrderFieldEx *> > exchangeOrderCenter;

	boost::unordered_map<std::string, std::list<CThostFtdcTradeField *> > tradeCenter;
	
#else

	typedef tbb::concurrent_unordered_map<LCLONGLONG, LocalKey>::iterator SIGNAL_ORDER_ITOR;

	typedef tbb::concurrent_unordered_map<std::string, LCLONGLONG>::iterator ORDER_SIGNAL_ITOR;

	typedef tbb::concurrent_unordered_map<std::string, CThostFtdcOrderFieldEx *>::iterator ORDER_ITOR;

	typedef tbb::concurrent_unordered_map<std::string, std::list<CThostFtdcTradeField *> >::iterator TRADE_ITOR;

	tbb::concurrent_unordered_map<LCLONGLONG, LocalKey> pSignal_orderId_Map;

	tbb::concurrent_unordered_map<std::string, LCLONGLONG> orderId_pSignal_Map;

	tbb::concurrent_unordered_map<std::string, CThostFtdcOrderFieldEx *> orderCenter;

	tbb::concurrent_unordered_map<std::string, std::list<CThostFtdcTradeField *> > tradeCenter;

#endif

	int FRONT_ID;

	int SESSION_ID;

	std::string getKey(int frontId, int sessionId, const char * orderRef);

private:
	
	void refreshSignal(CThostFtdcOrderField * pOrder, const std::string & key);
};

#endif