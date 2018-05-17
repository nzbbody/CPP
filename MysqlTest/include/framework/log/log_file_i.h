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
* 	@brief:		��־�ļ�������
* 	@author:	zhangxusheng
*	@date:		2013-12-26
*	@note:		�������framework����־�ļ�������ԡ���Ŀǰʵ��ÿ��һ����־ģʽ
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
	*	@brief		:	    ��־�ļ���/�ر�
	*	@param		��		void
	*	@return		:		E_OK����־�ļ���/�رճɹ���E_FAIL:��־�ļ���/�ر�ʧ��
	*	@author		:	    zhangxusheng
	*	@note:		:		
	*
	*/
	t_int32 open();
	t_int32 close();
	
	/** 
	*
	* 	func name	:		writeLog
	*	@brief		:	    ����־�ļ���д��־
	*	@param		��		void
	*	@return		:		E_OK����־�ļ���/�رճɹ���E_FAIL:��־�ļ���/�ر�ʧ��
	*	@author		:	    zhangxusheng
	*	@note:		:		
	*
	*/
	t_int32 writeLog(stringI& logMsg);

	/** 
	*
	* 	func name	:		setLogFilePath/getLogFilePath
	*	@brief		:	    ����/��ȡ��־�ļ�·��
	*	@param		��		��־�ļ�·��
	*	@return		:		E_OK�����óɹ���E_FAIL:����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setLogFilePath(const t_int8* logFilePath);
	const t_int8* getLogFilePath();

	/** 
	*
	* 	func name	:		setLogFileDate/getLogFileDate
	*	@brief		:	    ����/��ȡ��־�ļ�·��
	*	@param		��		��־�ļ�·��
	*	@return		:		E_OK�����óɹ���E_FAIL:����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setLogDate(const t_int8* logFileDate);
	const t_int8* getLogFileDate();

	/** 
	*
	* 	func name	:		getLogFileState
	*	@brief		:	    ��ȡ��ǰ��־�ļ�״̬
	*	@param		��		void
	*	@return		:		��־�ļ�״̬
	*	@author		:	    zhangxusheng
	*	@note:		:		��־״̬��Ϊδ��ʼ��״̬����ʼ��״̬����״̬���ر�״̬
	*
	*/
	t_int32 getLogFileState();

public:
	t_int32 logFileSwitch(void *);

private:
	t_int32 getLogFile(stringI& logFile);				//��ȡҪд�����־�ļ�
	t_int32 getLogDirectory(directoryI *dir);
	t_int32 searchLogFile(directoryI &logdir, stringI &logfile);

private:
	fileI		m_logFile;			//��־�ļ�
	stringI		m_logDate;			//��ǰ��־�ļ�������
	logFileState	m_logFileState;	//��ǰ��־�ļ���״̬
	stringI		m_logFilePath;		//��־�ļ�·�����ڳ�ʼ����ʱ������
	mutexI		m_mutex;			//��־д�����Ļ�����
	eventTimerI	m_logtimer;			//��Ҫ����ÿ�춨ʱ�л�
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

	//����־�ļ���ģ�����
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
	logFileArri m_logFile;		//��־�ļ�
	t_int32 mlogLevel;			//֧����־�ȼ�
	t_int8  mmodFlag[20];		//֧�ֵ�ģ��

	t_int32 mtimeStampFlg;		//ʱ�����־λ
	t_int32 mmodFlg;			//ģ������־λ
	t_int32 mcodeFlg;			//����λ������־λ
	t_int32 mlevelFlg;			//�ȼ�����־λ

	logModI mlogMod;			//��־ģ�����
	mutexI	m_mutex;			//��־�ļ�д����
};

typedef singletonI<logFileI> logFileSingleton;

#endif



