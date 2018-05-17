/**
* Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
 *@file:threadpool.h
 *
 * @description:This file wrapped the trace function,
 * output printf infomation to terminal
 *
 * @author:ning_shuanglong
 * 
 * @date:2012-6-13
 */

  
#ifndef _TRACE_I_H
#define _TRACE_I_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <data_types.h>

#include <errno/errno_i.h>
#include <errno/errcode_i.h>

#include <errno.h>

#include <singleton_i.h>
#include <log/log_i.h>
#include <trace/traceData_i.h>

#define __FILENAME__        ((strrchr(__FILE__, '/') == NULL)?__FILE__:((strrchr(__FILE__, '/') + 1)))

#define BLACK         "\e[30;1m"//黑色字体
#define RED             "\e[31;1m"//红色字体
#define GREEN         "\e[32;1m"//绿色字体
#define YELLOW       "\e[33;1m"//黄色字体
#define BLUE      	    "\e[34;1m"//蓝色字体
#define PURPLE        "\e[35;1m"//紫色字体
#define DEEPGREEN "\e[36;1m"//深绿色字体
#define WHITE         "\e[37;1m"//白色字体

#define BLACKB       "\e[40;1m"//黑色背景
#define REDB           "\e[41;1m"//红色背景
#define GREENB       "\e[42;1m"//绿色背景
#define YELLOWB     "\e[43;1m"//黄色背景
#define BLUEB          "\e[44;1m"//蓝色背景
#define PURPLEB      "\e[45;1m"//紫色背景
#define DEEPGREENB   "\e[46;1m"//深绿色背景
#define WHITEB       "\e[47;1m"//白色背景

#define COLORLEN       7//颜色字节长度

#define INFO_STR         "%s,%s:%d Info: "
#define DEBUG_STR      "%s,%s:%d Debug: "
#define API_STR           "%s,%s:%d Api: "
#define WARNING_STR "%s,%s:%d Warning: "
#define ERR_STR          "%s,%s:%d Error: "
#define FATAL_STR       "%s,%s:%d Fatal: "

t_int32 print2log(const t_int8*, const t_int8*, const t_int8*, t_int32);

#define COLOR_INFO_BEGIN \
do\
{\
	if(DBG_FLAG_STDOUT & (getTraceFlag()))\
		printf(INFO_STR,__FILENAME__, __FUNCTION__, __LINE__);\
	if(DBG_FLAG_FILE & (getTraceFlag()))\
		print2log(INFO_STR, __FILENAME__, __FUNCTION__, __LINE__);\
}while(0)

#define COLOR_DEBUG_BEGIN \
do\
{\
	if(DBG_FLAG_STDOUT & (getTraceFlag()))\
		printf(DEBUG_STR,__FILENAME__, __FUNCTION__, __LINE__);\
	if(DBG_FLAG_FILE & (getTraceFlag()))\
		print2log(DEBUG_STR, __FILENAME__, __FUNCTION__, __LINE__);\
}while(0)

#define COLOR_API_BEGIN \
do\
{\
	if(DBG_FLAG_STDOUT & (getTraceFlag()))\
		printf(API_STR,__FILENAME__, __FUNCTION__, __LINE__);\
	if(DBG_FLAG_FILE & (getTraceFlag()))\
		print2log(API_STR, __FILENAME__, __FUNCTION__, __LINE__);\
}while(0)

#define COLOR_WARNING_BEGIN \
do\
{\
	if(DBG_FLAG_STDOUT & (getTraceFlag()))\
		printf(WARNING_STR,__FILENAME__, __FUNCTION__, __LINE__);\
	if(DBG_FLAG_FILE & (getTraceFlag()))\
		print2log(WARNING_STR,__FILENAME__, __FUNCTION__, __LINE__);\
}while(0)

#define COLOR_ERR_BEGIN \
do\
{\
	if(DBG_FLAG_STDOUT & (getTraceFlag()))\
		printf(ERR_STR,__FILENAME__, __FUNCTION__, __LINE__);\
	if(DBG_FLAG_FILE & (getTraceFlag()))\
		print2log(ERR_STR,__FILENAME__, __FUNCTION__, __LINE__);\
}while(0)

#define COLOR_FATAL_BEGIN \
do\
{\
	if(DBG_FLAG_STDOUT & (getTraceFlag()))\
		printf(FATAL_STR,__FILENAME__, __FUNCTION__, __LINE__);\
	if(DBG_FLAG_FILE & (getTraceFlag()))\
		print2log(FATAL_STR,__FILENAME__, __FUNCTION__, __LINE__);\
}while(0)

#define COLOR_END \
do\
{\
	if(DBG_FLAG_STDOUT & (getTraceFlag()))\
		printf("\e[0m");\
}while(0)

#if 0
//标准打印
#define PRINT_STD(fmt...)\
do\
{\
	va_list vars;\
	va_start(vars, fmt);\
	vprintf(fmt, vars);\
	fflush(stdout);\
	va_end(vars);\
}while(0)


//标准打印
#define PRINT_STD(fmt, ...)\
do\
{\
	va_list file_vars;\
	va_start(file_vars, fmt);\
	if(DBG_FLAG_FILE & (getTraceFlag()))\
	{\
		if(fmt[0]=='\e' && fmt[1]=='[' )\
		{\
			vfprintf (logFd,fmt+COLORLEN, file_vars);	\
		}\
		else\
		{\
			vfprintf(logFd,fmt,file_vars);\
		}\
	}\
	va_end(file_vars);\
	va_list out_vars;\
	va_start(out_vars, fmt);\
	if(DBG_FLAG_STDOUT & (getTraceFlag()))\
	{\
		vprintf(fmt, out_vars);\
		fflush(stdout);\
	}\
	va_end(out_vars);\
}while(0)
#endif

#define DBG_FLAG_INFO                    1<<1
#define DBG_FLAG_DEBUG                 1<<2
#define DBG_FLAG_API                      1<<3
#define DBG_FLAG_WARNING            1<<4
#define DBG_FLAG_ERR                     1<<5
#define DBG_FLAG_FATAL                  1<<6

#define DBG_FLAG_STDOUT               1<<7
#define DBG_FLAG_FILE                     1<<8

#define DBG_FLAG_FRAMEWORKINFO		1<<9
#define DBG_FLAG_FRAMEWORKDEB		1<<10

///remain 2 flag options

#if 0
#define traceInfoX(x,fmt, ...)\
do\
{\
	logSingleton::instance()->info(x,__FILENAME__, __FUNCTION__, __LINE__,fmt);\
}while(0)

#define traceDebugX(x,fmt, ...)\
do\
{\
	logSingleton::instance()->debug(x,__FILENAME__, __FUNCTION__, __LINE__,fmt);\
}while(0)

#define traceApiX(x,fmt, ...)\
do\
{\
	logSingleton::instance()->api(x,__FILENAME__, __FUNCTION__, __LINE__,fmt);\
}while(0)

#define traceWarningX(x,fmt, ...)\
do\
{\
	logSingleton::instance()->warning(x,__FILENAME__, __FUNCTION__, __LINE__,fmt);\
}while(0)

#define traceErrX(x,fmt, ...)\
do\
{\
	logSingleton::instance()->err(x,__FILENAME__, __FUNCTION__, __LINE__,fmt);\
}while(0)

#define traceFatalX(x,fmt, ...)\
do\
{\
	logSingleton::instance()->fatal(x,__FILENAME__, __FUNCTION__, __LINE__,fmt);\
}while(0)

#endif

DLL_EXPORT t_int32 traceI(const t_int8 *fmt, ...);

#ifdef WIN32


#define traceInfo(fmt, ...)\
do\
{\
	if(DBG_FLAG_INFO & (getTraceFlag()))\
{\
	traceI(fmt, ##__VA_ARGS__);\
}\
}while(0)

#define traceDebug(fmt, ...)\
do\
{\
	if(DBG_FLAG_DEBUG & (getTraceFlag()))\
{\
	traceI(fmt, ##__VA_ARGS__);\
}\
}while(0)

#define traceApi(fmt, ...)\
do\
{\
	if(DBG_FLAG_API & (getTraceFlag()))\
{\
	traceI(fmt, ##__VA_ARGS__);\
}\
}while(0)

#define traceWarning(fmt, ...)\
do\
{\
	if(DBG_FLAG_WARNING & (getTraceFlag()))\
{\
	traceI(fmt, ##__VA_ARGS__);\
}\
}while(0)

#define traceErr(fmt, ...)\
do\
{\
	if(DBG_FLAG_ERR & (getTraceFlag()))	\
{\
	traceI(fmt, ##__VA_ARGS__);\
}\
}while(0)

#define traceFatal(fmt, ...)\
do\
{\
	if(DBG_FLAG_FATAL & (getTraceFlag()))\
{\
	traceI(fmt, ##__VA_ARGS__);\
}\
}while(0)

#define traceFrameInfo(fmt, ...)\
	do\
{\
	if(DBG_FLAG_FRAMEWORKINFO & (getTraceFlag()))\
{\
	traceI(fmt, ##__VA_ARGS__);\
}\
}while(0)

#define traceFrameDebug(fmt, ...)\
	do\
{\
	if(DBG_FLAG_FRAMEWORKDEB & (getTraceFlag()))\
{\
	traceI(fmt, ##__VA_ARGS__);\
}\
}while(0)

#else

#define traceInfo(fmt, ...)\
do\
{\
	if(DBG_FLAG_INFO & (getTraceFlag()))\
	{\
		COLOR_INFO_BEGIN;\
		traceI(fmt, ##__VA_ARGS__);\
		COLOR_END;\
	}\
}while(0)

#define traceDebug(fmt, ...)\
do\
{\
	if(DBG_FLAG_DEBUG & (getTraceFlag()))\
	{\
		COLOR_DEBUG_BEGIN;\
		traceI(fmt, ##__VA_ARGS__);\
		COLOR_END;\
	}\
}while(0)

#define traceApi(fmt, ...)\
do\
{\
	if(DBG_FLAG_API & (getTraceFlag()))\
	{\
		COLOR_API_BEGIN;\
		traceI(fmt, ##__VA_ARGS__);\
		COLOR_END;\
	}\
}while(0)

#define traceWarning(fmt, ...)\
do\
{\
	if(DBG_FLAG_WARNING & (getTraceFlag()))\
	{\
		COLOR_WARNING_BEGIN;\
		traceI(fmt, ##__VA_ARGS__);\
		COLOR_END;\
	}\
}while(0)

#define traceErr(fmt, ...)\
do\
{\
	if(DBG_FLAG_ERR & (getTraceFlag()))	\
	{\
		COLOR_ERR_BEGIN;\
		traceI(fmt, ##__VA_ARGS__);\
		COLOR_END;\
	}\
}while(0)

#define traceFatal(fmt, ...)\
do\
{\
	if(DBG_FLAG_FATAL & (getTraceFlag()))\
	{\
		COLOR_FATAL_BEGIN;\
		traceI(fmt, ##__VA_ARGS__);\
		COLOR_END;\
	}\
}while(0)

#define traceFrameInfo(fmt, ...)\
	do\
{\
	if(DBG_FLAG_FRAMEWORKINFO & (getTraceFlag()))\
{\
	COLOR_INFO_BEGIN;\
	traceI(fmt, ##__VA_ARGS__);\
	COLOR_END;\
}\
}while(0)

#define traceFrameDebug(fmt, ...)\
	do\
{\
	if(DBG_FLAG_FRAMEWORKDEB & (getTraceFlag()))\
{\
	COLOR_DEBUG_BEGIN;\
	traceI(fmt, ##__VA_ARGS__);\
	COLOR_END;\
}\
}while(0)
#endif

#if 0
static t_int32 traceInfoEx(const t_int8 *file, const t_int8 *func, const t_int32 line, const t_int8 *fmt, ...)
{
	if(DBG_FLAG_INFO & (getTraceFlag()))
	{
	//	COLOR_INFO_BEGIN;
		traceI(INFO_STR, file, func, line);
		PRINT_STD(fmt);
	//	COLOR_END;
	}
}

static t_int32 traceDebugEx(const t_int8 *file, const t_int8 *func, const t_int32 line, const t_int8 *fmt, ...)
{
	if(DBG_FLAG_DEBUG & (getTraceFlag()))	
	{
	//	COLOR_DEBUG_BEGIN;
		traceI(DEBUG_STR, file, func, line);		
		PRINT_STD(fmt);
	//	COLOR_END;
	}
}
static t_int32 traceApiEx(const t_int8 *file, const t_int8 *func, const t_int32 line, const t_int8 *fmt, ...)
{
	if(DBG_FLAG_API & (getTraceFlag()))
	{
	//	COLOR_API_BEGIN;
		printf(API_STR, file, func, line);		
		PRINT_STD(fmt);
	//	COLOR_END;
	}
}

static t_int32 traceWarningEx(const t_int8 *file, const t_int8 *func, const t_int32 line, const t_int8 *fmt, ...)
{
	if(DBG_FLAG_WARNING & (getTraceFlag()))
	{
	//	COLOR_WARNING_BEGIN;
		traceI(WARNING_STR, file, func, line);		
		PRINT_STD(fmt);
	//	COLOR_END;
	}
}

static t_int32 traceErrEx(const t_int8 *file, const t_int8 *func, const t_int32 line, const t_int8 *fmt, ...)
{
	if(DBG_FLAG_ERR & (getTraceFlag()))	
	{
		//COLOR_ERR_BEGIN;
		traceI(ERR_STR, file, func, line);		
		PRINT_STD(fmt);
		//COLOR_END;
	}
}

static t_int32 traceFatalEx(const t_int8 *file, const t_int8 *func, const t_int32 line, const t_int8 *fmt, ...)
{
	if(DBG_FLAG_FATAL & (getTraceFlag()))
	{
		//COLOR_FATAL_BEGIN;
		traceI(FATAL_STR, file, func, line);		
		PRINT_STD(fmt);
		//COLOR_END;
	}
}

#endif

t_int32 logTraceInit(t_int8* file);	

//////////////////////zhang_sunbo remain start/////////////////////////////////

#define ESC 0x1b

/**
 * \name terminal attributes 
 */
#define ATTR_RESET	0
#define ATTR_BRIGHT	1
#define ATTR_DIM	2
#define ATTR_UNDER	4
#define ATTR_BLINK	5
#define ATTR_REVER	7
#define ATTR_HIDDEN	8


/**
 * \name terminal colors
 */

#define COLOR_BLACK 	30
#define COLOR_GRAY  	(30 | 128)
#define COLOR_RED		31
#define COLOR_BRRED	(31 | 128)
#define COLOR_GREEN	32
#define COLOR_BRGREEN	(32 | 128)
#define COLOR_BROWN	33
#define COLOR_YELLOW	(33 | 128)
#define COLOR_BLUE		34
#define COLOR_BRBLUE	(34 | 128)
#define COLOR_MAGENTA	35
#define COLOR_BRMAGENTA (35 | 128)
#define COLOR_CYAN         36
#define COLOR_BRCYAN    (36 | 128)
#define COLOR_WHITE       37
#define COLOR_BRWHITE   (37 | 128)



t_int8 *withColorI(t_int8 *outBuf, t_int32 outLen,t_int8 *inBuf, t_int32 foreGround=0, t_int32 backGround=0,t_int32 flashEn=0);

#if 0
static t_int32 debugI(const t_int8 *file, const t_int32 line, const t_int8 *fmt, ...)
{
	t_int8 tmpOut[100];
	t_int8 tmpIn[100];

	snprintf(tmpIn, sizeof(tmpIn), "File: %s, Line %d ", file, line);
	traceI("%s", withColorI(tmpOut, sizeof(tmpOut), tmpIn, COLOR_RED,COLOR_GREEN));

	va_list vars;
	va_start(vars, fmt);

	vprintf(fmt, vars);

	fflush(stdout);
	
	va_end(vars);

	return 0;
}

#define errorI( fmt, ...) do{ debugI(__FILE__, __LINE__, fmt, ##__VA_ARGS__); } while(0)


#define abortI(fmt, ...) do{ debugI(__FILE__, __LINE__, fmt, ##__VA_ARGS__); exit(0); } while(0)

#endif

/////////////////////////////zhang_sunbo remain end///////////////////////////////////

#endif



