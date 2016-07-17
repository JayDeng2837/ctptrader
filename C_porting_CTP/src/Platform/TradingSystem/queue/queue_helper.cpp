  //////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     queue_helper.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/16
//////////////////////////////////////////////////////////////////////////
// self header
#include "queue_helper.h"

// c header

// c++ header

// third library header

// inner header

void PushToQueue(int queue_id, int type, void * data, int time_interval)
{
	FIFO_ELEM elem;
	elem.type = type;
	elem.time_interval = time_interval;
	elem.data = data;
		/*
	if (data == nullptr)
	{
		int no_data = -1;
		elem.data = (void *)(&no_data);
	}
	else
	{
		elem.data = data;
	}*/
	insert_hpq(global_queue + queue_id, elem);
}