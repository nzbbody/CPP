/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _DATA_TYPES_H
#define _DATA_TYPES_H

typedef char t_int8;
typedef short t_int16;
typedef int t_int32;
typedef long t_long;
typedef long long t_int64;
typedef t_int32 t_bool;

typedef unsigned char t_uint8;
typedef unsigned short t_uint16;
typedef unsigned int t_uint32;
typedef unsigned long t_ulong;
typedef unsigned long long t_uint64;

typedef float t_float32;
typedef double t_float64;

typedef unsigned long t_pointer;
typedef unsigned long t_handler;


#define TRUE 1
#define FALSE 0

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#ifdef WIN32

#pragma warning(disable:4996)
#pragma warning(disable:4129)
#pragma warning(disable:4251)
#pragma	warning(disable:4311)								
#pragma warning(disable:4312)								
#endif

#ifdef WIN32
typedef t_int32 socklen_t;
#endif

typedef struct sockaddr sockaddr_t;

typedef struct sockaddr_in6 sockaddr6_t;

typedef t_int32 iohandle_t;

#ifndef WIN32 
#define prosessId pid_t
#else
#define prosessId USHORT
#endif

#ifdef WIN32 
//#ifdef FRAMEWORK
#define DLL_EXPORT __declspec(dllexport)
//#else
//#define DLL_EXPORT __declspec(dllimport)
//#endif
#else
#define DLL_EXPORT 
#endif


//#include <key_value_i.h>
#include <common_inc.h>
//#include <singleton_i.h>

#endif
