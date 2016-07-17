//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     indicator.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/4/15
//////////////////////////////////////////////////////////////////////////
// self header
#include "indicator.h"

// c header

// c++ header
#include <iostream>

#include <cmath>

#include "strategy_defs.h"

typedef double (* bar_calc_func)(BarData * barData, const int offset, const int start, const int length);

typedef double (* tick_calc_func)(MarketData * barData, const int offset, const int start, const int length);

// third library header
BEGIN_EXTERN_C

bool str_Eq(const char * val1, const char * val2)
{
	if (val1 == NULL || val2 == NULL)
	{
		return false;
	}

	return strcmp(val1, val2) == 0;
}

bool str_GT(const char * val1, const char * val2)
{
	if (val1 == NULL || val2 == NULL)
	{
		return false;
	}

	return strcmp(val1, val2) > 0;
}

bool str_LT(const char * val1, const char * val2)
{
	if (val1 == NULL || val2 == NULL)
	{
		return false;
	}

	return strcmp(val1, val2) < 0;
}

bool str_GE(const char * val1, const char * val2)
{
	if (val1 == NULL || val2 == NULL)
	{
		return false;
	}

	return strcmp(val1, val2) >= 0;
}

bool str_LE(const char * val1, const char * val2)
{
	if (val1 == NULL || val2 == NULL)
	{
		return false;
	}

	return strcmp(val1, val2) <= 0;
}

//--------------------------------------------------------

bool Eq(double val1, double val2)
{
	if (std::abs(val1 - val2) <= _ZERO)
	{
		return true;
	}
	return false;
}

bool GT(double val1, double val2)
{
	if (val1 > val2 + _ZERO)
	{
		return true;
	}
	return false;
}

bool LT(double val1, double val2)
{
	if (val1 < val2 - _ZERO)
	{
		return true;
	}
	return false;
}

bool GE(double val1, double val2)
{
	if (val1 > val2 - _ZERO)
	{
		return true;
	}
	return false;
}

bool LE(double val1, double val2)
{
	if (val1 < val2 + _ZERO)
	{
		return true;
	}
	return false;
}

double round(double r)
{
	return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

double formatPrice(double price, double priceTick)
{

	if (priceTick <= 0)
	{
		return -1;
	}

	return round(price / priceTick) * priceTick;

}

int _getTickOffset(FieldType type)
{

	int offset = -1;

	switch(type)
	{
	case Volume:
		{
			offset = MEMBER_OFFSET(MarketData, Volume);
			break;
		}
	default:
		break;
	}

	return offset;
}

int _getBarOffset(FieldType type)
{

	int offset = -1;

	switch(type)
	{
	case Open:
		{
			offset = MEMBER_OFFSET(BarData, dOpenPrice);
			break;
		}
	case High:
		{
			offset = MEMBER_OFFSET(BarData, dHighestPrice);
			break;
		}
	case Low:
		{
			offset = MEMBER_OFFSET(BarData, dLowestPrice);
			break;
		}
	case Close:
		{
			offset = MEMBER_OFFSET(BarData, dClosePrice);
			break;
		}
	case Volume:
		{
			offset = MEMBER_OFFSET(BarData, iVolume);
			break;
		}
	default:
		break;
	}

	return offset;
}

bool _CrossAbove(BarData * currTick, BarData * prevTick, int offset, double prevVal, double currVal, FieldType type = Close)
{
	if (Eq(prevVal, 0) || Eq(currVal, 0))
	{
		return false;
	}

	double val_1 = 0;
	double val_2 = 0;

	switch(type)
	{
	case Volume:
		{
			val_1 = GetIntData(currTick, offset);
			val_2 = GetIntData(prevTick, offset);
			break;
		}
	default:
		{
			val_1 = GetDoubleData(currTick, offset);
			val_2 = GetDoubleData(prevTick, offset);
			break;
		}
	}

	if (Eq(val_1, 0) || Eq(val_2, 0))
	{
		return false;
	}

	if ((val_1 - prevVal) < 0 && (val_2 - currVal) > 0)
	{
		return true;
	}

	return false;
}

bool _CrossUnder(BarData * currTick, BarData * prevTick, int offset, double prevVal, double currVal, FieldType type = Close)
{
	if (Eq(prevVal, 0) || Eq(currVal, 0))
	{
		return false;
	}

	double val_1 = 0;
	double val_2 = 0;

	switch(type)
	{
	case Volume:
		{
			val_1 = GetIntData(currTick, offset);
			val_2 = GetIntData(prevTick, offset);
			break;
		}
	default:
		{
			val_1 = GetDoubleData(currTick, offset);
			val_2 = GetDoubleData(prevTick, offset);
			break;
		}
	}

	if (Eq(val_1, 0) || Eq(val_2, 0))
	{
		return false;
	}

	if ((val_1 - prevVal) > 0 && (val_2 - currVal) < 0)
	{
		return true;
	}

	return false;
}

bool CrossAboveSerial(void * data, double * datas2, FieldType type)
{
	if (data == NULL || datas2 == NULL)
	{
		return false;
	}

	BarData * currTick = (BarData *)data;

	BarData * prevTick = ((BarData *)data) - 1;
	
	return _CrossAbove(currTick, prevTick, _getBarOffset(type), *datas2, *(datas2 - 1));
}

bool CrossAboveVal(void * data, double datas2, FieldType type)
{
	if (data == NULL || datas2 == NULL)
	{
		return false;
	}

	BarData * currTick = (BarData *)data;

	BarData * prevTick = ((BarData *)data) - 1;

	return _CrossAbove(currTick, prevTick, _getBarOffset(type), datas2, datas2);
}

bool CrossUnderSerial(void * data, double * datas2, FieldType type)
{

	if (data == NULL || datas2 == NULL)
	{
		return false;
	}

	BarData * currTick = (BarData *)data;

	BarData * prevTick = ((BarData *)data) - 1;

	return _CrossUnder(currTick, prevTick, _getBarOffset(type), *datas2, *(datas2 - 1));
}

bool CrossUnderVal(void * data, double datas2, FieldType type)
{
	if (data == NULL || datas2 == NULL)
	{
		return false;
	}

	BarData * currTick = (BarData *)data;

	BarData * prevTick = ((BarData *)data) - 1;

	return _CrossUnder(currTick, prevTick, _getBarOffset(type), datas2, datas2);
}

double Summation(double * data, const int startPos, const int endPos)
{
	if (data == NULL)
	{
		return -1;
	}

	double sum = 0;

	for (int k = startPos; k <= endPos; k++)
	{
		sum += *(data + k);
	}

	return sum;
}

double _BarHighest(BarData * barData, const int offset, const int start, const int length)
{
	if (length <= 0)
		return -1;

	double high = GetDoubleData(&barData[start], offset);

	for (int i = 0; i < length; i++)
	{
		BarData * currTick = &barData[start + i];

		double val = GetDoubleData(currTick, offset);

		if (val > high)
		{
			high = val;
		}
	}

	return high;
}

double _BarLowest(BarData * barData, const int offset, const int start, const int length)
{

	if (length <= 0)
		return -1;

	double low = GetDoubleData(&barData[start], offset);

	for (int i = 0; i < length; i++)
	{
		BarData * currTick = &barData[start + i];

		double val = GetDoubleData(currTick, offset);

		if (val < low)
		{
			low = val;
		}
	}

	return low;
}

double _TickAverage(MarketData * pData, const int offset, const int start, const int length)
{

	if (length <= 0)
		return -1;

	double sum = 0;

	for (int i = 0; i < length; i++)
	{
		MarketData * currTick = &pData[start + i];

		double val = GetDoubleData(currTick, offset);

		sum += val;

	}

	return sum / length;
}

double _BarAverage(BarData * barData, const int offset, const int start, const int length)
{

	if (length <= 0)
		return -1;

	double sum = 0;

	for (int i = 0; i < length; i++)
	{
		BarData * currTick = &barData[start + i];

		double val = GetDoubleData(currTick, offset);

		sum += val;

	}

	return sum / length;
}

double _DAvgVol(double * data, const int start, const int length)
{

	if (length <= 0)
		return -1;

	double sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += *(data + i);
	}

	return sum / length;
}

double _IAvgVol(int * data, const int start, const int length)
{

	if (length <= 0)
		return -1;

	double sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += *(data + i);
	}

	return sum / length;
}

double _TickAvgVol(MarketData * tickData, const int start, const int length, const int offset)
{

	if (length <= 0)
		return -1;

	double sum = 0;

	for (int i = 0; i < length; i++)
	{
		MarketData * currTick = & tickData[start + i];

		int val = GetIntData(currTick, offset);

		sum += val;

	}

	return sum / length;
}

double _BarAvgVol(BarData * barData, const int start, const int length, const int offset)
{

	if (length <= 0)
		return -1;

	double sum = 0;

	for (int i = 0; i < length; i++)
	{
		BarData * currTick = & barData[start + i];

		int val = GetIntData(currTick, offset);

		sum += val;

	}

	return sum / length;
}

double CalcBarViaSpecifiedMethod(bar_calc_func funcPtr, void * data, const int start, const int length, FieldType type)
{
	return funcPtr((BarData *)data, _getBarOffset(type), start, length);
}

double CalcTickViaSpecifiedMethod(tick_calc_func funcPtr, void * data, const int start, const int length, FieldType type)
{
	return funcPtr((MarketData *)data, _getTickOffset(type), start, length);
}

//--------------------------------------------------------------

LC_API_API double CALL_METHOD Highest(void * data, const int start, const int length, FieldType type)
{

	if (data == NULL || start < 0 || length <= 0)
		return -1;

	return CalcBarViaSpecifiedMethod(_BarHighest, data, start, length, type);
}

LC_API_API double CALL_METHOD Lowest(void * data, const int start, const int length, FieldType type)
{

	if (data == NULL || start < 0 || length <= 0)
		return -1;

	return CalcBarViaSpecifiedMethod(_BarLowest, data, start, length, type);
}

LC_API_API double CALL_METHOD TickAverage(void * data, const int start, const int length, FieldType type)
{

	if (data == NULL || start < 0 || length <= 0)
		return -1;

	switch(type)
	{
	case Volume:
		{
			return _TickAvgVol((MarketData *)data, start, length, _getTickOffset(Volume));
		}
	default:
		{
			return CalcTickViaSpecifiedMethod(_TickAverage, data, start, length, type);
		}
	}

}

LC_API_API double CALL_METHOD Average(void * data, const int start, const int length, FieldType type)
{

	if (data == NULL || start < 0 || length <= 0)
		return -1;

	switch(type)
	{
	case Volume:
		{
			return _BarAvgVol((BarData *)data, start, length, _getBarOffset(Volume));
		}
	case _Double:
		{
			return _DAvgVol((double *)data, start, length);
		}
	case _Integer:
		{
			return _IAvgVol((int *)data, start, length);
		}
	default:
		{
			return CalcBarViaSpecifiedMethod(_BarAverage, data, start, length, type);
		}
	}
	
}

LC_API_API double CALL_METHOD TR(void * data)
{

	if (data == NULL)
	{
		return -1;
	}

	BarData * _data = (BarData *)data;

	BarData * _prevData = _data - 1;

	double trueHigh = MAX(_data->dHighestPrice, _prevData->dClosePrice);

	double trueLow = MIN(_data->dLowestPrice, _prevData->dClosePrice);
	
	return trueHigh - trueLow;
}

LC_API_API double CALL_METHOD ATR0(double * tr, int start_pos, const int n)
{
	if (tr == NULL || start_pos < 0 || n <= 0)
	{
		return -1;
	}

	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += tr[start_pos + i];
	}
	return sum / n;
}

LC_API_API double CALL_METHOD ATR(double prevATR, double tr, const int n)
{
	if (n <= 0)
		return -1;

	return (prevATR * (n - 1) + tr) / n;
}

LC_API_API double CALL_METHOD StandardDev(void * data, const int n, const FieldType type, const int calc_func)
{

	if (data == NULL)
		return -1;

	int len = calc_func == 1 ? n : n - 1;

	double sum = 0;
	BarData * data_ = (BarData *) data;

	if (data_ - n + 1 == NULL)
		return -1;

	if (type == Volume)
	{
		for(int i = 0; i < n; i++)
		{
			sum += (data_ - i)->iVolume;
		}
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			sum += (data_ - i)->dClosePrice;
		}
	}

	double mean = sum / len;

	double sum_sqr = 0;

	if (type == Volume)
	{
		for(int i = 0; i < n; i++)
		{
			double val = (data_ - i)->iVolume - mean;
			sum_sqr += val * val;
		}
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			double val = (data_ - i)->dClosePrice - mean;
			sum_sqr += val * val;
		}
	}

	return sum_sqr > 0 ? sqrt(sum_sqr) : 0;

}

END_EXTERN_C

// inner header
