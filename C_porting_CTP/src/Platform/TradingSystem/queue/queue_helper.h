  //////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      queue_helper.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/16
//////////////////////////////////////////////////////////////////////////

#ifndef _H_QUEUE_HELPER_H_
#define _H_QUEUE_HELPER_H_

// c++ header

// third library header

// inner header
#include "fifo_hpq.h"

#include "lcts_defs.h"

void PushToQueue(int queue_id, int type, void * data, int time_interval = QUERY_TIME_INTERVAL);

#endif