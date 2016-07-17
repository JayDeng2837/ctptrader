//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      ring_queue.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/30
//////////////////////////////////////////////////////////////////////////

#ifndef _H_RING_QUEUE_H_
#define _H_RING_QUEUE_H_

// c++ header

// third library header

// inner header

// classname: RingQueue
// brief:
template<class T>
class RingQueue
{
public:

    RingQueue(const int & Size)
	{
		QueueSize = Size;
		data = new T[QueueSize];
		Head = Tail = 0;
	}

	virtual ~RingQueue()
	{
		if (data)
		{
			delete []data;
		}
	}

public:

	bool IsFull()
	{
		return Head == (Tail + 1) % QueueSize;
	}

	bool IsEmpty()
	{
		return Head == Tail;
	}

	bool EnQueue(T t)
	{
		if (IsFull())
		{
			return false;
		}

		data[Tail++] = T;

		Tail %= QueueSize;

	}

	bool DeQueue(T & t)
	{
		if (IsEmpty())
		{
			return false;
		}

		t = data[Head++];

		Head %= QueueSize;
	}

private:

	int QueueSize;

	int Head;

	int Tail;

	T * data;
};

#endif