//////////////////////////////////////////////////////////////////////////
///  Copyright, (c) Leo Chan     2015
///  All rights reserved.
///
///  \Author:   leochan007@163.com
///
///  \File:     dll_manager.cpp
///  \Brief:   
///
///  \Version   1.0
///  \Date      2015/4/8
//////////////////////////////////////////////////////////////////////////
// self header
#include "dll_manager.h"

// c header

// c++ header

// third library header

// inner header
#include "strategy_macros.h"

using namespace std;

typedef boost::unordered_map<string, DLLInfo>::iterator DLL_ITOR;

DLLManager::DLLManager()
{}

DLLManager::~DLLManager()
{
	for (DLL_ITOR iter = m_mapLoadedDLL.begin();
		iter != m_mapLoadedDLL.end(); iter++)
	{
		DLLClose(iter->second.dllHandle);
	}
	m_mapLoadedDLL.clear();
}

bool DLLManager::LoadStrategyDLLByName(const string & sStategyName,
                   const string & sStrategyDLLPath)
{
    DLLInfo info;
    if(!GetDLL(sStrategyDLLPath, info))
    {
        return false;
    }

    if(info.dllHandle == NULL)
    {
        return false;
    }

    m_mapStrategyDLL[sStategyName] = info;
    return true;
}

IStrategy * DLLManager::CreateStrategyInstance(const string & sStategyName)
{
    DLL_HANDLE DllHandler = NULL;
    DLL_ITOR itor = m_mapStrategyDLL.find(sStategyName);
    if(itor == m_mapStrategyDLL.end())
    {
        return NULL;
    }
    else
    {
        DllHandler = m_mapStrategyDLL[sStategyName].dllHandle;
    }

	const string & DLLName = m_mapStrategyDLL[sStategyName].DLLName;

    const string & sStrategyCreatorName = GetStrategyCreatorName(DLLName);

    StrategyCreatorType pCreator = 
        (StrategyCreatorType)DLLGetFunByName(DllHandler, sStrategyCreatorName.c_str());

    if(NULL == pCreator)
	{
        // TODO
		char p[100];
		DLLGetLastErrorMsg(p, 100);
        return NULL;
    }

    return (IStrategy *)(pCreator());
}

void DLLManager::ReleaseDLLByName(const string & sDLLName)
{
	DLL_ITOR itor = m_mapLoadedDLL.find(sDLLName);
	if(itor == m_mapLoadedDLL.end()) 
	{
		return;
	}
    DLLClose(itor->second.dllHandle);
	m_mapLoadedDLL.erase(itor);
}

bool DLLManager::GetDLL(const string & sStrategyDLLPath, DLLInfo & info)
{
    size_t pos1 = sStrategyDLLPath.find_last_of("/");
    size_t pos2 = sStrategyDLLPath.find_last_of("\\");

    if(pos1 == string::npos && pos2 == string::npos)
    {   // 没有路径符号,说明;
        pos1 = 0;
    }
    else if (pos1 != string::npos && pos2 != string::npos)
    {
        pos1 = (pos1 > pos2) ? pos1 : pos2;
    }
    else if(pos1 == string::npos)
    {   // 选择最后一位
        pos1 = pos2;
    }
    else if (pos2 == string::npos)
    {
    }
    string sDllName = sStrategyDLLPath.substr(pos1 + 1, sStrategyDLLPath.size());

    DLL_HANDLE DllHandler = NULL;
    DLL_ITOR itor = m_mapLoadedDLL.find(sDllName);
    if(itor == m_mapLoadedDLL.end())
    {
        DllHandler = DLLLoader(sStrategyDLLPath.c_str());
        if (NULL == DllHandler)
        {
            printf("[EtDLLManager] DllName:%s   DllHandler:0", sDllName.c_str());
            return false;
        }

#ifndef WIN32
        size_t iFirst = sDllName.find("lib") + 3;
        size_t iEnd = sDllName.find(".so");
        sDllName = sDllName.substr(iFirst, iEnd - iFirst);
        printf("[EtDLLManager] DllName:%s   DllHandler:0", sDllName.c_str());
#endif

        m_mapLoadedDLL[sDllName].DLLName = sDllName;
        m_mapLoadedDLL[sDllName].dllHandle = DllHandler;
        info = m_mapLoadedDLL[sDllName];
        return true;
    }
    else
    {
        info = itor->second;
        return true;
    }
}
