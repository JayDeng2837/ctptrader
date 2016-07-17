//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     dll_loader.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/4/8
//////////////////////////////////////////////////////////////////////////
// self header
#include "dll_loader.h"

// c header

// c++ header

// third library header
#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

// inner header
using namespace std;

DLL_HANDLE DLLLoader(const char * plname)
{
#ifdef WIN32
	//fixed bug,can not load DLL in windows 2003 serve, because 
	//this Win2003S did not support ./ and ../ structure, so use full path
	//replace relative path.   
	SetLastError(0);
	DLL_HANDLE pHandle= LoadLibraryA(plname);

	if (GetLastError() == NOTFINDDLL)
	{
		SetLastError(0);
		printf("[����Dll] ���·�����ִ��󣬳���ȫ·������\n");
		char parentDir[MAX_DIRECTORLEN];
		GetCurrentDirectoryA(MAX_DIRECTORLEN, parentDir);

		int iLenOfParentDir = strlen(parentDir);
		char * pPositionNeedCopy = parentDir + iLenOfParentDir;
		int iLenOfChildDir = strlen(plname);
		if (iLenOfParentDir + iLenOfChildDir >= MAX_DIRECTORLEN)
		{
			printf("[����Dll] Dll ��·�����ȴ��� 250. \n");
			return NULL;
		}
		strcpy(pPositionNeedCopy, plname + 1);
		char* pDir = parentDir;

		pHandle = NULL;
		pHandle = LoadLibraryA(pDir);
		if(NULL == pHandle)
		{
			printf("[����Dll] ���ܴ�DLL ·��[%s]\n", pDir);
		}
	}
	int iLastError = GetLastError();
	SetLastError(0);
	if(iLastError != LOADEDDLL)
	{
		printf("[����Dll] ���ܼ���ָ��DLL��·��Ϊ [%s]  Error  %d", plname, iLastError);
	}
	return pHandle;
#else
	DLL_HANDLE h = dlopen( plname, RTLD_NOW|RTLD_GLOBAL);
	printf("[Et_dll_loader] load dll, last err [%s], %d", dlerror(),h);
	return h;
#endif

}

void DLLClose(DLL_HANDLE h)
{
	if(NULL != h)
	{
#ifdef WIN32
		FreeLibrary(h);
#else
		dlclose (h);
#endif
	}
}

void* DLLGetFunByName(DLL_HANDLE h, const char * pfname)
{
	if(NULL != h)
	{
#ifdef WIN32
		return (void *)GetProcAddress(h, pfname);
#else
		return dlsym(h, pfname);
#endif
	}
	return NULL;
}

void DLLGetLastErrorMsg(char * p, int size)
{
	if (NULL == p)
		return;
#ifdef WIN32
	DWORD err = GetLastError();
#endif
	//MY_SPRINTF(p, "dll error(%u)\n", GetLastError());
}