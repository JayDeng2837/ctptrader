  //////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      AbsWrapper.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/17
//////////////////////////////////////////////////////////////////////////

#ifndef _H_ABSWRAPPER_H_
#define _H_ABSWRAPPER_H_

// c++ header
#include <string>
#include <list>

// third library header

// inner header

#include "cpu_affinity_helper.h"

// classname: AbsWrapper
// brief:
class AbsWrapper
{
public:
	AbsWrapper(const std::string username, const std::string pwd, const std::string front_addr, std::string brokerID);
	virtual ~AbsWrapper() {};

protected:

	std::string folder_path;

	std::string username;

	std::string pwd;

	std::string front_addr;

	std::string brokerID;

	bool isInited;

	int RequestID;

	int NewRequestID();

	void QuerySleep();

};

#endif