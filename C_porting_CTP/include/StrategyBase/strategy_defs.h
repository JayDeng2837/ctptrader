//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      strategy_defs.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/8
//////////////////////////////////////////////////////////////////////////

#ifndef _H_STRATEGY_DEFS_H_
#define _H_STRATEGY_DEFS_H_

// c++ header

// third library header

// inner header

// classname: 
// brief:

typedef char LcInstrumentIDType[31];

typedef char LcFtdcDateType[9];

typedef char LcFtdcTimeType[9];

typedef char LcFtdcBarTimeType[6];

typedef long long LCLONGLONG;

struct MarketData
{
	LcInstrumentIDType	Symbol;

	LcFtdcDateType		TradingDay;
	LcFtdcTimeType		UpdateTime;
	int					UpdateMillisec;

	double				PreClosePrice;
	double				PreSettlementPrice;
	double				PreOpenInterest;

	double				LastPrice;
	double              OpenInterest;
	int  				deltaOpenInsterest;

	double				UpperLimitPrice;
	double				LowerLimitPrice;

	int					Volume;
	int					accVolume;

	double				Turnover;
	double				accTurnover;

	double				AskPrice;
	int					AskVolume;
	double				BidPrice;
	int					BidVolume;

	double				AvgPriceInTick;
	double              AveragePrice;
};

enum BarType
{
	NoneType = 0,
	Sec_Five,
	Sec_Ten,
	Sec_Twenty,
	Sec_Thirty,
	Min_One,
	Min_Two,
	Min_Three,
	Min_Five,
	Min_15,
	Daily_Bar_Type,
};

struct BarData
{
	BarType eBarPeriod;     //bar������;
	LcInstrumentIDType cSymbol;       //bar�ĺ�Լ��;
	LcFtdcDateType    cDay;       //bar �Ľ�������;
	LcFtdcBarTimeType    cTime;      //bar ��ʱ��;

	int     iSymbolIndex;   //��Լ�Զ�������;

	int  iBarIndex;            //Bar ���ݵ����;

	int     iVolume; //bar �ɽ���;
	double  dOpenInt; //δƽ����;
	int     iBeginVolume; //

	double  dOpenPrice;   //bar�Ŀ��̼�;
	double  dClosePrice;  //bar�����̼�;
	double  dHighestPrice; //bar����߼�;
	double  dLowestPrice;  //bar����ͼ�;

	bool    endOfSector;
};

enum StrategyStatus
{
	Idle = 0,
	PlacingOrder,
	OrderReceived,
	OrderPartialFilled,
	OrderFilled,
	CancellingOrder,
	OrderCancelled,
	BeforeTradingTime,
	TradingForbidden,
	TradingEnd,
};

struct TickRecord
{
	LCLONGLONG currentMicroSec_in_queue;
	LCLONGLONG currentMicroSec;
};

enum Direction
{
	Buy = 0,
	Sell,
	SellShort,
	BuyToCover,
};

enum OrderType
{
	Market = 0,
	Limit,
	IOC,
	Cancel,
};

struct Signal : TickRecord
{
	LcInstrumentIDType	InstrumentID;
	double price;
	int qty;
	Direction direction;
	OrderType orderType;
	char orderTime[20];
	char orderRtnTime[20];
	LCLONGLONG orderRtnMicroSec;
	LCLONGLONG signal_id;
	void * strategy_ptr;
};

#endif