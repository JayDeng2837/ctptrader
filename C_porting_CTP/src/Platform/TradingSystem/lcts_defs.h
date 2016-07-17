//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      common_macros.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/24
//////////////////////////////////////////////////////////////////////////

#ifndef _H_LCTS_MACROS_H_
#define _H_LCTS_MACROS_H_

// c++ header

// third library header
#include "ThostFtdcUserApiStruct.h"

// inner header
#include "strategy_defs.h"

#define QUERY_TIME_INTERVAL (1000000)

#define YIELD_TIME_INTERVAL (1)

#define MAX_DATA_SIZE 40000

#define CPU_STEP 2

#define INSTRUMENT_SIZE 31

enum CPU_CORE_ALLOC
{
	OMS_CORE = 1,
	MD_PROCESSOR_CORE = OMS_CORE + CPU_STEP,
	CTP_MD_CORE = MD_PROCESSOR_CORE + CPU_STEP,
	CTP_TRADER_CORE = CTP_MD_CORE + CPU_STEP,
};

#define PBOOSTPOOL_MALLOC(var_name, pool_name, _type) _type * var_name = (_type *)pool_name->malloc(); \
	memset(var_name, 0, sizeof(_type))

#define PBOOSTPOOL_ORDERED_MALLOC(var_name, pool_name, _type, _size) _type * var_name = \
    (_type *)pool_name->ordered_malloc(_size); \
	memset(var_name, 0, _size * sizeof(_type))

#define PBOOSTPOOL_MALLOC_2(var_name, pool_name, _type) var_name = (_type *)pool_name->malloc(); \
	memset(var_name, 0, sizeof(_type))

#define PBOOSTPOOL_MALLOC_CPY(var_name, pSrc, pool_name, _type) _type * var_name = (_type *)pool_name->malloc(); \
	memcpy(var_name, pSrc, sizeof(_type))

#define NEW_BOOSTPOOL(var, _type) var = new boost::pool<>(sizeof(_type))

#define STR_EQ(a, b) (strcmp(a, b) == 0)

extern char * d_arr[];

extern char * ot_arr[];

#define GenStuctWithTickRecord(field_name_new, field_name) struct field_name_new: TickRecord { struct field_name field; }
#define GenStuctWithRspInfoAndTickRecord(field_name_new, field_name) struct field_name_new: TickRecord \
																		{ \
																			struct field_name field; \
																			struct CThostFtdcRspInfoField pRspInfo; \
																		}

struct InstrumentTickInfo
{
	int counter;
	MarketData * data_ptr[MAX_DATA_SIZE];
	int volumes[MAX_DATA_SIZE]; // int
	double avg_price_per_tick[MAX_DATA_SIZE]; // double
};

GenStuctWithTickRecord(CThostFtdcOrderFieldEx, CThostFtdcOrderField);

GenStuctWithRspInfoAndTickRecord(CThostFtdcInputOrderFieldEx2, CThostFtdcInputOrderField);
GenStuctWithRspInfoAndTickRecord(CThostFtdcInputOrderActionFieldEx2, CThostFtdcInputOrderActionField);
GenStuctWithRspInfoAndTickRecord(CThostFtdcOrderActionFieldEx2, CThostFtdcOrderActionField);

#endif