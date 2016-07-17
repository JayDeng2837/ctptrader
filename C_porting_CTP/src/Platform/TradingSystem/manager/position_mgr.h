//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      position.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/20
//////////////////////////////////////////////////////////////////////////

#ifndef _H_POSITION_H_
#define _H_POSITION_H_

// c header
#include <signal.h>

// c++ header
#include <string>
#include <list>
#include <atomic>

// third library header
#include <boost/pool/pool.hpp>
#include <tbb/concurrent_unordered_map.h>

#include "ThostFtdcUserApiStruct.h"

// inner header
#include "recordable.h"

//#define INT std::atomic_int
#define LCINT int

// classname: Position
// brief:
struct Position
{
public:
	
	Position();

	virtual ~Position() {};

	TThostFtdcInstrumentIDType instumentid;

	LCINT  iYesterday;

	LCINT  iYesterdayLong;

	LCINT  iYesterdayShort;

	LCINT  iToday;

	LCINT  iTodayLong;

	LCINT  iTodayShort;

	LCINT  iTotalPos;

	LCINT  iTotalLong;

	LCINT  iTotalShort;

	void SumPosInfo();

	void ResetPosition();

	void UpdatePosition(CThostFtdcInvestorPositionField * pInvestorPosition, bool bIsLast);

	void CalcPosition(TThostFtdcDirectionType Direction, TThostFtdcCombOffsetFlagType CombOffsetFlag, int new_trade_count);
};

typedef tbb::concurrent_unordered_map<std::string, Position *>::iterator POSMAP_ITOR;

class PositionMgr : public IRecordable
{
private:

	tbb::concurrent_unordered_map<std::string, Position *> positionCenter;

	boost::pool<> * position_pool;

public:

	virtual void WriteToDisk(const std::string & path);

public:

	PositionMgr();

	virtual ~PositionMgr();

	void clearAllPositions();

	void InitialPostions(std::list<std::string> instruments);

	void UpdatePosition(CThostFtdcInvestorPositionField * pInvestorPosition, bool bIsLast);

	Position * GetPostion(const std::string & key);

	void CalcPosition(TThostFtdcInstrumentIDType InstrumentID, TThostFtdcDirectionType Direction, TThostFtdcCombOffsetFlagType CombOffsetFlag, int new_trade_count);

};

#endif