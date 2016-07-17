  //////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     AbsWrapper.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/3/17
//////////////////////////////////////////////////////////////////////////
// self header
#include "AbsWrapper.h"

// c header

// c++ header

// third library header
#include <boost/thread.hpp>
#include "queue_helper.h"

// inner header

using std::string;

AbsWrapper::AbsWrapper(const string username, const string pwd, const string front_addr, string brokerID) 
	: username(username), pwd(pwd), front_addr(front_addr), brokerID(brokerID), isInited(false)
{
	folder_path = "cons/" + brokerID + "/" + username;
};

int AbsWrapper::NewRequestID()
{
	return RequestID++;
}

void AbsWrapper::QuerySleep()
{
	boost::this_thread::sleep(boost::posix_time::microseconds(QUERY_TIME_INTERVAL));
}