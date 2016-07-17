//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      recordable.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/3/25
//////////////////////////////////////////////////////////////////////////

#ifndef _H_RECORDABLE_H_
#define _H_RECORDABLE_H_

// c++ header
#include <string>
#include <list>

// third library header

// inner header

// classname: IRecordable
// brief:

struct IRecordable
{
	virtual void WriteToDisk(const std::string & path) = 0;
};

class RecordMgr
{

public:

	virtual ~RecordMgr()
	{
	}

	void addRecord(std::string path, IRecordable * record)
	{
		RecordInfo r;
		r.path = path;
		r.pRecord = record;
		records.push_back(r);
	}

	void writeRecord()
	{
		std::list<RecordInfo>::iterator itor = records.begin();
		for (; itor != records.end(); itor++)
		{
			if (itor->pRecord)
			{
				itor->pRecord->WriteToDisk(itor->path);
			}
		}
	}

private:

	struct RecordInfo
	{
		IRecordable * pRecord;
		std::string path;
	};

	std::list<RecordInfo> records;
};

#endif