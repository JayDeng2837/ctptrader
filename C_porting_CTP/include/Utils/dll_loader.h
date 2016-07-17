//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      dll_loader.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/8
//////////////////////////////////////////////////////////////////////////

#ifndef _H_DLL_LOADER_H_
#define _H_DLL_LOADER_H_

// c header
#include <stdio.h>

// third library header

// inner header
//#include "Base.h"

//----------------------------win32-------------------------------------
#ifdef WIN32
#include <windows.h>
typedef HMODULE DLL_HANDLE;

#define   NOTFINDDLL       126
#define   LOADEDDLL        0
#define   MAX_DIRECTORLEN   250

#else
typedef void *  DLL_HANDLE;
#endif

DLL_HANDLE DLLLoader(const char * plname);

void DLLClose(DLL_HANDLE h);

void * DLLGetFunByName(DLL_HANDLE h, const char * pfname);

void DLLGetLastErrorMsg(char * p, int size);

#endif	//end head_file
