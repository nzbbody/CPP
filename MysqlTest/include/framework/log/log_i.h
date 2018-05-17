/**
 * 	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:log_i.h
 *
 * 	@brief:  xxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 *
 * 	@author:ning_shuanglong 2013-1-6
 * 
 * 	@note:
 */

#ifndef _LOG_I_H
#define _LOG_I_H

#include <errno/error_i.h>
#include <string/string_i.h>

#define LOG_INFO		1<<1
#define LOG_DEBUG		1<<2
#define LOG_API			1<<3
#define LOG_WARNING		1<<4
#define LOG_ERR			1<<5
#define LOG_FOTAL		1<<6
#define LOG_FATAL		1<<6	//以前写错了，这里弥补一下

#define LOG_FRAMEINFO	1<<9
#define LOG_FRAMEDEB	1<<10

#ifdef WIN32
#define _func_ __FUNCTION__
#else
#define _func_ __FUNCTION__
#endif

#define  MSG_MAX 512
class DLL_EXPORT logI
{
public:
	logI();
	virtual ~logI();

public:
	t_int32 regMod(t_int8 *mod_name);
	t_int32 unregMod(t_int8 *mod_name);
	
	//////////////////////////////////针对文件输出
	//所支持的文件输出日志等级
	t_int32 getFileLevel();
	void	setFileLevel(t_int32 levelBit);
	void	clrFileLevel(t_int32 levelBit);

	//所支持的文件输出日志模块
	t_int32 getFileModStat(t_int8* modName);
	void	setFileMod(t_int8* modName);
	void	clrFileMod(t_int8* modName);

	//文件输出的日志配置项
	t_int32 enFileTimestampOutput();
	t_int32 disFileTimestampOutput();
	t_int32 enFileModOutput();
	t_int32 disFileModOutput();
	t_int32 enFileCodeOutput();
	t_int32 disFileCodeOutput();
	t_int32 enFileLevelOutput();	
	t_int32 disFileLevelOutput();

	//////////////////////////////////针对标准输出
	//所支持的标准输出日志等级
	t_int32 getStdoutLevel();
	void	setStdoutLevel(t_int32 levelBit);
	void	clrStdoutLevel(t_int32 levelBit);

	//所支持的标准输出日志模块
	t_int32 getStdoutModStat(t_int8* modName);
	void	setStdoutMod(t_int8* modName);
	void	clrStdoutMod(t_int8* modName);

	//标准输出的日志配置项
	t_int32 enStdoutTimestampOutput();
	t_int32 disStdoutTimestampOutput();
	t_int32 enStdoutModOutput();
	t_int32 disStdoutModOutput();
	t_int32 enStdoutCodeOutput();
	t_int32 disStdoutCodeOutput();
	t_int32 enStdoutLevelOutput();	
	t_int32 disStdoutLevelOutput();
		
public:

	static t_int32 logInfo(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, ...);

	static t_int32 logDebug(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, ...);
	
	static t_int32 logApi(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, ...);

	static t_int32 logWarning(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, ...);
	
	static t_int32 logErr(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, ...);

	static t_int32 logFatal(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, ...);
};

#define LogInfo(modname, fmt, ...) do\
{\
	logI::logInfo((t_int8 *)modname, __FILE__, _func_, __LINE__, fmt, ##__VA_ARGS__);\
}while(0)

#define LogDebug(modname, fmt, ...) do\
{\
	logI::logDebug((t_int8 *)modname, __FILE__, _func_, __LINE__, fmt, ##__VA_ARGS__);\
}while(0)

#define LogApi(modname, fmt, ...) do\
{\
	logI::logApi((t_int8 *)modname, __FILE__, _func_, __LINE__, fmt, ##__VA_ARGS__);\
}while(0)

#define LogWarning(modname, fmt, ...) do\
{\
	logI::logWarning((t_int8 *)modname, __FILE__, _func_, __LINE__, fmt, ##__VA_ARGS__);\
}while(0)

#define LogErr(modname, fmt, ...) do\
{\
	logI::logErr((t_int8 *)modname, __FILE__, _func_, __LINE__, fmt, ##__VA_ARGS__);\
}while(0)

#define LogFatal(modname, fmt, ...) do\
{\
	logI::logFatal((t_int8 *)modname, __FILE__, _func_, __LINE__, fmt, ##__VA_ARGS__);\
}while(0)


#endif

