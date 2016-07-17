#pragma once

#include <stdlib.h>
#include <string>
#include "zmq.h"
using namespace std;

//  Receive 0MQ string from socket and convert into C string
//  Caller must free returned string. Returns NULL if the context
//  is being terminated.
static char *
s_recv (void *socket) {
    zmq_msg_t message;
    zmq_msg_init (&message);

	//lchan_todo
    //if (zmq_recv (socket, &message, 0))
    //    return (NULL);

    int size = zmq_msg_size (&message);
    char *string = (char*)malloc (size + 1);
    memcpy (string, zmq_msg_data (&message), size);
    zmq_msg_close (&message);
    string [size] = 0;
    return (string);
}

//  Convert C string to 0MQ string and send to socket
// 禁用，因为strlen对于Pb来说会出现字符截断， 一定要传入长度
static int
s_send (void *socket, const char *s) {
    int rc;
    zmq_msg_t message;
    zmq_msg_init_size (&message, strlen (s));
	memcpy(zmq_msg_data(&message), s, strlen(s));
	//lchan_todo
    //rc = zmq_send (socket, &message, ZMQ_NOBLOCK);
	if(rc!=0)
	{
		printf("Zmq send err, err=%s", zmq_strerror(zmq_errno()));
	}
    zmq_msg_close (&message);
    return (rc);
}

static int
	s_send (void *socket, string& s) {
		int rc;
		zmq_msg_t message;
		zmq_msg_init_size (&message,s.size());
		memcpy(zmq_msg_data(&message), s.c_str(), s.size());
		//lchan_todo
		//rc = zmq_send (socket, &message, ZMQ_NOBLOCK);
		//rc = zmq_send (socket, &message, 0);
		if(rc!=0)
		{
			printf("Zmq send err, err=%s", zmq_strerror(zmq_errno()));
		}
		zmq_msg_close (&message);
		return (rc);
}
//  Sends string as 0MQ string, as multipart non-terminal
static int
s_sendmore (void *socket, char *string) {
    int rc;
    zmq_msg_t message;
    zmq_msg_init_size (&message, strlen (string));
	memcpy(zmq_msg_data(&message), string, strlen(string));
	//lchan_todo
    //rc = zmq_send (socket, &message, ZMQ_SNDMORE);
    zmq_msg_close (&message);
    return (rc);
}
