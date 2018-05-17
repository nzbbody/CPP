/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *@file:log_file_i.h
 *
 * @description:
 *
 * @author:ning_shuanglong
 * 
 * @date:2013-01-11
 */
 
#ifndef _LOG_FILE_I_H
#define _LOG_FILE_I_H

#include <errno/error_i.h>
#include <trace/trace_i.h>
#include <string/string_i.h>
#include <log/log_mod_i.h>
#include <directory/directory_i.h>
#include <mutex_i.h>
#include <key_value_i.h>
#include <file_i.h>
#include <event_timer_i.h>

#define LOGPATHKEY "log_path"

typedef enum
{
	LOGFILE_UNINIT,
	LOGFILE_INIT,
	LOGFILE_OPEN,
}logFileState;
/** 
*
*	class:		logFileArri
* 	@brief:		日志文件策略类
* 	@author:	zhangxusheng
*	@date:		2013-12-26
*	@note:		该类包含framework的日志文件处理策略——目前实现每天一个日志模式
*/

t_int32 logFileArriTimerFunc(void* args);
class logFileArri
{
public:
	logFileArri();
	virtual ~logFileArri();

public:

	/** 
	*
	* 	func name	:		open/close
	*	@brief		:	    日志文件打开/关闭
	*	@param		：		void
	*	@return		:		E_OK：日志文件打开/关闭成功，E_FAIL:日志文件打开/关闭失败
	*	@author		:	    zhangxusheng
	*	@note:		:		
	*
	*/
	t_int32 open();
	t_int32 close();
	
	/** 
	*
	* 	func name	:		writeLog
	*	@brief		:	    往日志文件里写日志
	*	@param		：		void
	*	@return		:		E_OK：日志文件打开/关闭成功，E_FAIL:日志文件打开/关闭失败
	*	@author		:	    zhangxusheng
	*	@note:		:		
	*
	*/
	t_int32 writeLog(stringI& logMsg);

	/** 
	*
	* 	func name	:		setLogFilePath/getLogFilePath
	*	@brief		:	    设置/获取日志文件路径
	*	@param		：		日志文件路径
	*	@return		:		E_OK：设置成功，E_FAIL:设置失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setLogFilePath(const t_int8* logFilePath);
	const t_int8* getLogFilePath();

	/** 
	*
	* 	func name	:		setLogFileDate/getLogFileDate
	*	@brief		:	    设置/获取日志文件路径
	*	@param		：		日志文件路径
	*	@return		:		E_OK：设置成功，E_FAIL:设置失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setLogDate(const t_int8* logFileDate);
	const t_int8* getLogFileDate();

	/** 
	*
	* 	func name	:		getLogFileState
	*	@brief		:	    获取当前日志文件状态
	*	@param		：		void
	*	@return		:		日志文件状态
	*	@author		:	    zhangxusheng
	*	@note:		:		日志状态分为未初始化状态、初始化状态、打开状态、关闭状态
	*
	*/
	t_int32 getLogFileState();

public:
	t_int32 logFileSwitch(void *);

private:
	t_int32 getLogFile(stringI& logFile);				//获取要写入的日志文件
	t_int32 getLogDirectory(directoryI *dir);
	t_int32 searchLogFile(directoryI &logdir, stringI &logfile);

private:
	fileI		m_logFile;			//日志文件
	stringI		m_logDate;			//当前日志文件的日期
	logFileState	m_logFileState;	//当前日志文件的状态
	stringI		m_logFilePath;		//日志文件路径，在初始化的时候设置
	mutexI		m_mutex;			//日志写函数的互斥锁
	eventTimerI	m_logtimer;			//主要用于每天定时切换
};

class logFileI
{
public:
	logFileI();
	virtual ~logFileI();

public:
	t_int32 logInit(keyValueI &globalConfig);
	t_int32 logExit();

public:
	t_int32 info(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 debug(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 api(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 warning(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 err(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 fatal(t_int8 *modname, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);

	//对日志文件的模块操作
	t_int32 getModStat(t_int8 *modname);
	t_int32 getModStat(t_int32 modBit);

	//void	setMod(t_int32 modBit);
	//void	clrMod(t_int32 modBit);

	void	setMod(t_int8* modName);
	void	clrMod(t_int8* modNmae);
	
	t_int32 regFileLogMod(t_int8 *mod_name);
	t_int32 unregFileLogMod(t_int8 *modname);

private:
	t_int32 writeAppend(stringI msg);	
	t_int32 output(t_int8 *modname,const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, t_int8* levelName, const t_int8 *fmt, va_list va);

public:
	logFileArri m_logFile;		//日志文件
	t_int32 mlogLevel;			//支持日志等级
	t_int8  mmodFlag[20];		//支持的模块

	t_int32 mtimeStampFlg;		//时间戳标志位
	t_int32 mmodFlg;			//模块名标志位
	t_int32 mcodeFlg;			//代码位置名标志位
	t_int32 mlevelFlg;			//等级名标志位

	logModI mlogMod;			//日志模块策略
	mutexI	m_mutex;			//日志文件写枷锁
};

typedef singletonI<logFileI> logFileSingleton;

#endif



