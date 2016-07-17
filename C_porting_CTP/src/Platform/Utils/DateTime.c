/*
 * $Id: DateTime.c,v 1.2 2005/03/01 02:32:06 xiaofeng Exp $
 *
 * Implemention of time and date routines
 *
 * Copyright (c) 2004-2006. All rights reserved.
 *
 * $Log: DateTime.c,v $
 *
 */

#include "Base.h"
#include "DateTime.h"
#include "TimeType.h"

#include <stdio.h>
#include <time.h>

#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif

// bypass warnings in VS 8.0 
#if (_MSC_VER > 1200)
#pragma warning(disable:4996)
#endif

long long GetFrequency()
{
#ifdef WIN32
	LARGE_INTEGER litmp;
	QueryPerformanceFrequency(&litmp);
	return litmp.QuadPart;
#else
	return 1;
#endif
}

#define MULTI 1e6

long long GetCurrentTick()
{

#ifdef WIN32
	//CPU晶振计数;
	LARGE_INTEGER begin_time;
	QueryPerformanceCounter(&begin_time);
	return  begin_time.QuadPart;
#else
	// 微秒数;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	//秒数* 1000000 + 微秒数;
	return tv.tv_sec * MULTI + tv.tv_usec;
#endif

}

long long GetElapsedTime(long long tick)
{

#ifdef WIN32
	return (long long) (tick * MULTI / GetFrequency());
#else
	return tick;
#endif

}

void get_curtime_l(char * sTime)
{
#ifdef WIN32
    SYSTEMTIME tm;
    GetLocalTime(&tm);
    sprintf(sTime, "%4d%02d%02d %02d%02d%02d.%3.3ld",
            tm.wYear, tm.wMonth, tm.wDay, tm.wHour, tm.wMinute, 
            tm.wSecond, tm.wMilliseconds);
#else
    struct timeval tv;
    struct tm * ptm;

    gettimeofday(&tv, NULL);
    ptm = localtime((const time_t *)&(tv.tv_sec));

    sprintf(sTime, "%4d%02d%02d %02d%02d%02d.%3.3ld",
            ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday,
            ptm->tm_hour, ptm->tm_min, ptm->tm_sec, tv.tv_usec / 1000L);
#endif
}

void get_curtime_s(char * sTime)
{
#ifdef WIN32
    SYSTEMTIME tm;
    GetLocalTime(&tm);
    sprintf(sTime, "%02d%02d%02d.%3.3ld",
            tm.wHour, tm.wMinute, tm.wSecond, tm.wMilliseconds);
#else
    struct timeval tv;
    struct tm * ptm;

    gettimeofday(&tv, NULL);
    ptm = localtime((const time_t *)&(tv.tv_sec));

    sprintf(sTime, "%02d%02d%02d.%3.3ld",
            ptm->tm_hour, ptm->tm_min, ptm->tm_sec, tv.tv_usec / 1000L);
#endif
}

void get_curtime_f(char * sTime)
{
	time_t t;
	struct tm * tm_buf;
	t = time(0);
	tm_buf = localtime(&t);
	sprintf(sTime, "%04d-%02d-%02d %02d:%02d:%02d",
            tm_buf->tm_year + 1900,
            tm_buf->tm_mon + 1,
            tm_buf->tm_mday,
            tm_buf->tm_hour,
            tm_buf->tm_min,
            tm_buf->tm_sec);
}

void get_curdate_s(char * szDate)
{
	time_t t;
	struct tm * tm_buf;
	t = time(0);
	tm_buf = localtime(&t);
	sprintf(szDate, "%04d%02d%02d",
            tm_buf->tm_year + 1900,
            tm_buf->tm_mon + 1,
            tm_buf->tm_mday);
}

