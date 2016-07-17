//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      DateTime.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/9
//////////////////////////////////////////////////////////////////////////

#ifndef _H_DATETIME_H_
#define _H_DATETIME_H_

// c++ header

// third library header

// inner header

#ifndef DATEBUF_SIZE
# define DATEBUF_SIZE 256
#endif

/** @file DateTime.h Time and Date Routines */
BEGIN_EXTERN_C

long long GetFrequency();

long long GetCurrentTick();

long long GetElapsedTime(long long tick);

/** Get current time string in format yyyy-mm-dd HHMMSS.uuu
 *  @param sTime - char sTime[20]
 */
void get_curtime_l(char * sTime);

/** Get current time string in format HHMMSS.uuu
 *  @param sTime - char sTime[20]
 */
void get_curtime_s(char * sTime);

/** Get current time string in format yyyy-mm-dd HH:MM:SS
 *  @param sTime - char sTime[20]
 */
void get_curtime_f(char * sTime);

/** Get current date string in format yyyymmdd
 *  @param szDate - char szDate[20]
 */
void get_curdate_s(char * szDate);

END_EXTERN_C

#endif /* _UTILS_DATETIME_H_ */
