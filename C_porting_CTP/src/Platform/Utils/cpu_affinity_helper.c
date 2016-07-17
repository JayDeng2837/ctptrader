//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     cpu_affinity_helper.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/4/3
//////////////////////////////////////////////////////////////////////////
// self header
#include "cpu_affinity_helper.h"

// c header

// c++ header

// third library header

// inner header
#include "Base.h"

#ifdef WIN32
#include <windows.h>
#else
#endif

unsigned long GetCoreNum()
{
	unsigned long cpu_core_num = 0;

#ifdef WIN32
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	cpu_core_num = info.dwNumberOfProcessors;
#else
#endif
	
	return cpu_core_num;
}

LC_HANDLE GetCurrentThreadHandle()
{

#ifdef WIN32
	return GetCurrentThread();
#else
#endif;

	return 0;
}

LC_BOOL LcSetThreadAffinityMask(int cpu_core, LC_HANDLE handle)
{
	return FALSE;

#ifdef WIN32
	SetThreadAffinityMask(handle, cpu_core);
#else
#endif;

	return TRUE;
}