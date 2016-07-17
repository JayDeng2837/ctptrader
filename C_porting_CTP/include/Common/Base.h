/*
 * $Id: Base.h,v 1.5 2005/03/15 21:03:46 xiaofeng Exp $
 *
 * Global definitions
 *
 * Copyright (c) 2004-2006. All rights reserved.
 *
 * $Log: Base.h,v $
 *
 */

#ifndef _UTILS_GLOBAL_H_
#define _UTILS_GLOBAL_H_

/** @file Base.h Global Definitions */

#ifdef WIN32
#ifdef DLL_EXPORT
#define LC_API_API __declspec(dllexport)
#else
#define LC_API_API __declspec(dllimport)
#endif
#define CALL_METHOD __cdecl
#else
#define LC_API_API
#define CALL_METHOD
#endif

#ifdef __cplusplus
# include <cstdlib>
# include <cassert>
# include <cerrno>
# if defined(__GNUC__) && __GNUC__ >= 3
#  define LC_INTERFACE           struct
# elif defined(WIN32)
#  define LC_INTERFACE           __interface
# elif defined(P_HPUX)
# endif

#ifdef __cplusplus
#define BEGIN_EXTERN_C   extern "C"		{
#else
#define BEGIN_EXTERN_C   {
#endif
#define END_EXTERN_C      }

# ifndef EXTERN_C
#  define EXTERN_C            extern "C"
# endif
# define PUBLIC               public:
# define PROTECTED            protected:
# define PRIVATE              private:
#else /* !__cplusplus */
# include <stdlib.h>
# include <assert.h>
# include <errno.h>
# define INTERFACE            struct
# if defined(__GNUC__)
#  include <stdint.h>
#  define INLINE              static inline
# elif defined(WIN32)
#  define INLINE              _inline
# elif defined(P_HPUX)
#  include <sys/_inttypes.h>
# else
#  include <sys/types.h>
# endif /* __GNUC__ */
# define BEGIN_EXTERN_C
# define END_EXTERN_C
# ifndef EXTERN_C
#  define EXTERN_C            extern
# endif
# define PUBLIC
# define PROTECTED
# define PRIVATE
#endif /* __cplusplus */

#ifndef TRUE
# define TRUE                 1
# define FALSE                0

typedef int LC_BOOL;

#endif /* TRUE */

#ifndef INLINE
# define INLINE               __inline
#endif

#ifndef  IN
# define IN
# define OUT
# define INOUT
#endif /* IN */

#define GET_ARRAY_SIZE(a)     (sizeof(a) / sizeof(a[0]))

#ifndef SAFE_FREE
# define SAFE_FREE(obj)        if (NULL != obj) { free((void*)obj); obj = NULL; }
# define SAFE_FREE2(obj, cmd)  if (NULL != obj) { cmd((void*)obj);  obj = NULL; }
#endif

#ifdef WIN32
#define MY_VSNPRINTF _vsnprintf
#define MY_SNPRINTF _snprintf
#define MY_GETCH _getch
#define MY_STRCPY strcpy_s
#define MY_SPRINTF sprintf_s
#else
#define MY_VSNPRINTF vsnprintf
#define MY_SNPRINTF snprintf
#define MY_GETCH getch
#define MY_STRCPY strcpy
#define MY_SPRINTF sprintf
#endif

#define NEW_STRUCT(var, _type) _type * var = new _type; memset(var, 0, sizeof(_type))

#define NEW_STRUCT_WITHOUT_DEF(pVar, _type) var = new _type; memset(pVar, 0, sizeof(_type))

#define GEN_STRUCT(var, _type) _type var; memset(&var, 0, sizeof(_type))

#define GEN_STRUCT_WITHOUT_DEF(var, _type) memset(&var, 0, sizeof(_type))

#define NEW_ARRAY(pVar, _type, _length) _type * pVar = new _type[_length]; memset(pVar, 0, sizeof(_type) * _length)

#define NEW_ARRAY_WITHOUT_DEF(pVar, _type, _length) pVar = new _type[_length]; memset(pVar, 0, sizeof(_type) * _length)

#define GEN_ARRAY(var, _type, _length) _type var[_length]; memset(var, 0, sizeof(_type) * _length)

#define GEN_ARRAY_WITHOUT_DEF(var, _type, _length) memset(var, 0, sizeof(_type) * _length);

#ifndef DEL_PTR
#define DEL_PTR(ptr)    do      \
 {                                   \
 if(NULL != ptr)     \
 {                    \
 delete ptr;      \
 ptr = NULL;     \
 }                 \
 } while(0)
#endif

#endif /* _UTILS_GLOBAL_H_ */

