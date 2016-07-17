//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      indicator.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/21
//////////////////////////////////////////////////////////////////////////

#ifndef _H_INDICATOR_H_
#define _H_INDICATOR_H_

// c++ header

// third library header

// inner header
#include "Base.h"

// classname: 
// brief:

#define MAX(a, b) (a > b ? a : b)

#define MIN(a, b) (a < b ? a : b)

#define _ZERO (1e-6)

#define        MEMBER_OFFSET(type, member)     ((unsigned long)(&((type*)0)->member))

#define		  GetIntData(data, offset) (*((int *)((char *)data + offset)))

#define		  GetDoubleData(data, offset) (*((double *)((char *)data + offset)))

enum FieldType
{
	None = 0,
	Last,
	Open,
	High,
	Low,
	Close,
	Volume,
	TurnOver,
	_Double,
	_Integer,
};

BEGIN_EXTERN_C

LC_API_API bool CALL_METHOD str_Eq(const char * val1, const char * val2);

LC_API_API bool CALL_METHOD str_GT(const char * val1, const char * val2);

LC_API_API bool CALL_METHOD str_LT(const char * val1, const char * val2);

LC_API_API bool CALL_METHOD str_GE(const char * val1, const char * val2);

LC_API_API bool CALL_METHOD str_LE(const char * val1, const char * val2);

//----------------------------------------------------------------------

LC_API_API bool CALL_METHOD Eq(double val1, double val2);

LC_API_API bool CALL_METHOD GT(double val1, double val2);

LC_API_API bool CALL_METHOD LT(double val1, double val2);

LC_API_API bool CALL_METHOD GE(double val1, double val2);

LC_API_API bool CALL_METHOD LE(double val1, double val2);

LC_API_API double CALL_METHOD formatPrice(double price, double priceTick);

LC_API_API double CALL_METHOD Summation(double * data, const int startPos, const int endPos);

LC_API_API double CALL_METHOD Highest(void * data, const int start, const int length, FieldType type = Close);

LC_API_API double CALL_METHOD Lowest(void * data, const int start, const int length, FieldType type = Close);
	
LC_API_API double CALL_METHOD Average(void * data, const int start, const int length, FieldType type = Close);

LC_API_API double CALL_METHOD TickAverage(void * data, const int start, const int length, FieldType type = Volume);

LC_API_API bool CALL_METHOD CrossAboveSerial(void * data, double * datas2, FieldType type = Close);

LC_API_API bool CALL_METHOD CrossAboveVal(void * data, double datas2, FieldType type = Close);

LC_API_API bool CALL_METHOD CrossUnderSerial(void * data, double * datas2, FieldType type = Close);

LC_API_API bool CALL_METHOD CrossUnderVal(void * data, double datas2, FieldType type = Close);

LC_API_API double CALL_METHOD TR(void * data);

LC_API_API double CALL_METHOD ATR0(double * tr, int start_pos, const int n);

LC_API_API double CALL_METHOD ATR(double prevATR, double tr, const int n);

LC_API_API double CALL_METHOD StandardDev(void * data, const int n, const FieldType type = Close, const int calc_func = 1);

END_EXTERN_C

#endif