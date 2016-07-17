//////////////////////////////////////////////////////////////////////////
///  Copyright, (c)  Leo Chan     2015
///  All rights reserved.
///
///  \Author    leochan007@163.com
///
///  \File      strategy_macros.h
///  \Brief    
///
///  \Version   1.0
///  \Change    revised by yf.chan
///  \Date      2015/4/9
//////////////////////////////////////////////////////////////////////////

#ifndef _H_STRATEGY_MACROS_H_
#define _H_STRATEGY_MACROS_H_

// c++ header

// third library header

// inner header

#include "Base.h"

// 策略端要定义这个宏，并且写ETIGER_STRATEGY_CREATOR_FUN_NAME来定义dll入口

#define STRATEGY_CREATOR_FUN_NAME(STRATEGY_CLASS_NAME)   STRATEGY_CLASS_NAME##Factory
#define STRATEGY_CREATOR_FUN_NAME_STRING(STRATEGY_CLASS_NAME)    #STRATEGY_CLASS_NAME"Factory"

#ifdef STRATEGY_INTERNAL

#define DECLARE_STRATEGY_CREATOR(STRATEGY_CLASS_NAME)    \
	BEGIN_EXTERN_C   \
	LC_API_API void* STRATEGY_CREATOR_FUN_NAME(STRATEGY_CLASS_NAME)()   \
	{   \
	return (void*)(new STRATEGY_CLASS_NAME());  \
	}   \
	END_EXTERN_C
#endif

// 策略使用端，要定义下面这个宏，并且通过函数"EtGetStrategyCreatorName"来获得dll
#ifdef STRATEGY_EXTERNAL

#include <string>

typedef void* (* StrategyCreatorType)();

// \brief: use strategy class name to combine the strategy-creator name
std::string GetStrategyCreatorName(const std::string & StrategyClassName)
{
    std::string sRes(StrategyClassName);
    return (sRes + "Factory");
}

#endif

#endif