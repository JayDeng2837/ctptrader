//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     base_service.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/4/21
//////////////////////////////////////////////////////////////////////////
// self header
#include "base_service.h"

// c header

// c++ header
#include <iostream>

// third library header

#include "zmq.h"
#include "zmq_utils.h"

// inner header

using namespace std;

BaseService::BaseService() : isInit(false), ctx(nullptr), pub(nullptr)
{
}

BaseService::~BaseService()
{
	if (pub)
	{
		zmq_close(pub);
		pub = nullptr;
	}

	if (ctx)
	{
		zmq_term(ctx);
		ctx = nullptr;
	}
}

bool BaseService::InitService(const char * path, int mode)
{
	isInit = true;
	ctx = zmq_init(1);
	pub = zmq_socket(ctx, mode);
	int ret = zmq_bind(pub, path);
	return true;
}

int BaseService::SendMsg(const string & str, int flag)
{
	return s_send(pub, str, flag);
}

std::string BaseService::RecvMsg()
{
	return s_recv(pub);
}

char * BaseService::s_recv(void * socket) {
	zmq_msg_t message;
	zmq_msg_init(&message);
	if (zmq_msg_recv(&message, socket, 0))
		exit(1);           //  Context terminated, exit

	int size = zmq_msg_size(&message);
	char * _string = (char *)malloc(size + 1);
	memcpy(_string, zmq_msg_data(&message), size);
	zmq_msg_close(&message);
	_string[size] = 0;
	return (_string);
}

int BaseService::s_send(void *socket, string _string, int flag) 
{
	int rc;
	zmq_msg_t message;
	int len = _string.size();
	zmq_msg_init_size(&message, len);
	memcpy(zmq_msg_data(&message), _string.c_str(), len);
	rc = zmq_msg_send(&message, socket, flag); //ZMQ_SNDMORE
	//assert (!rc);
	zmq_msg_close(&message);
	return (rc);
}