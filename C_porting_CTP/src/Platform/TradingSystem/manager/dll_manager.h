//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      dll_manager.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/8
//////////////////////////////////////////////////////////////////////////

#ifndef _H_DLL_MANAGER_H_
#define _H_DLL_MANAGER_H_

// c++ header
#include <string>

// third library header
#include <boost/unordered_map.hpp>

// inner header

// classname: 
// brief:

// head file
#include "dll_loader.h"

// forward declaration
class IStrategy;

struct DLLInfo
{
    std::string DLLName;
    DLL_HANDLE dllHandle;
};

// classname: DLLManager
// brief:
class DLLManager
{
 public:
    DLLManager();
    virtual ~DLLManager();

	//////////////////////////////////////////////////////////////////////////
	// brief	load dll and get the instance of certain strategy
	// arg1:	sStrategyDLLName	dll name,不要加".dll"后缀
	//		\note: this dll-name must be the same as the strategy class name
	//////////////////////////////////////////////////////////////////////////
    bool LoadStrategyDLLByName(const std::string & sStrategyName, const std::string & sStrategyDLLPath);

    IStrategy * CreateStrategyInstance(const std::string & sStategyName);

    void ReleaseDLLByName(const std::string & sStategyName);

    bool GetDLL(const std::string & sStrategyDLLPath, DLLInfo & info);

private:
    //<DLL路径名字，DLL句柄>
    boost::unordered_map<std::string, DLLInfo>	m_mapLoadedDLL;
    
    //<策略名，DLL句柄>
    boost::unordered_map<std::string, DLLInfo>	m_mapStrategyDLL;

};

#endif