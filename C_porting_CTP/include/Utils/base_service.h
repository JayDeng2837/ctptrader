//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      base_service.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/21
//////////////////////////////////////////////////////////////////////////

#ifndef _H_BASE_SERVICE_H_
#define _H_BASE_SERVICE_H_

// c++ header
#include <string>

// third library header

// inner header

#define ZMQ_NB 1
#define ZMQ_SM 2

#define ZMQ_PUB_NEW 1
#define ZMQ_REP_NEW 4

// classname: BaseService
// brief:
class BaseService
{
public:
    BaseService();
    virtual ~BaseService();

public:

	bool InitService(const char * path, int mode = ZMQ_PUB_NEW);

	int SendMsg(const std::string & str, int flag = ZMQ_NB);

	std::string RecvMsg();

protected:

	char * s_recv(void * socket);

	int s_send(void *socket, std::string _string, int flag = ZMQ_NB);

private:

	void * ctx;
	
	void * pub;

protected:

	bool isInit;

};

#endif