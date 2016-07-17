//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      cpu_affinity_helper.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/3
//////////////////////////////////////////////////////////////////////////

#ifndef _H_CPU_AFFINITY_HELPER_H_
#define _H_CPU_AFFINITY_HELPER_H_

// c++ header

// third library header
#include "Base.h"

// inner header

#define LC_HANDLE void *

BEGIN_EXTERN_C

unsigned long GetCoreNum();

LC_HANDLE GetCurrentThreadHandle();

LC_BOOL LcSetThreadAffinityMask(int cpu_core, LC_HANDLE handle);

END_EXTERN_C

#endif