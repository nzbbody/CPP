/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *@file:log_stdout_i.h
 *
 * @description:
 *
 * @author:ning_shuanglong
 * 
 * @date:2013-01-11
 */

#ifndef _LOG_STDOUT_I_H
#define _LOG_STDOUT_I_H

#include <errno/error_i.h>
#include <trace/trace_i.h>
#include <string/string_i.h>
#include <log/log_mod_i.h>

class logStdoutI
{
public:
	t_int32 mlogLevel;//֧����־�ȼ�
	t_int8   mmodFlag[20];//֧�ֵ�ģ��

	t_int32 mtimeStampFlg;//ʱ�����־λ
	t_int32 mmodFlg; //ģ������־λ
	t_int32 mcodeFlg;//����λ������־λ
	t_int32 mlevelFlg;//�ȼ�����־λ

	logModI mlogMod;//��־ģ�����

public:
	logStdoutI()
	{
		mlogLevel = (DBG_FLAG_INFO | DBG_FLAG_DEBUG | 
					DBG_FLAG_API | DBG_FLAG_WARNING |
					DBG_FLAG_ERR | DBG_FLAG_FATAL); 


		mtimeStampFlg = 1;
		mmodFlg = 1;
		mcodeFlg = 1;
		mlevelFlg = 1;
		memset(mmodFlag, 0x0, sizeof(mmodFlag));
	}
	
	
public:
	t_int32 info(t_int8 *modName, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 debug(t_int8 *modName, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 api(t_int8 *modName, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 warning(t_int8 *modName, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 err(t_int8 *modName, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);
	t_int32 fatal(t_int8 *modName, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, const t_int8 *fmt, va_list va);

	//����־�����ģ�����
	t_int32 getModStat(t_int8* modName);
	t_int32 getModStat(t_int32 modBit);
	//void setMod(t_int32 modBit);
	//void clrMod(t_int32 modBit);
	void	setMod(t_int8* modName);
	void	clrMod(t_int8* modNmae);
	//ģ��������
	t_int32 regStdoutLogMod(t_int8 *mod_name);
	t_int32 unregStdoutLogMod(t_int8 *mod_name);
	
private:
	t_int32 writeTimestamp();
	t_int32 writeModName(t_int8 *modName);
	t_int32 writeAppend(stringI msg);
	t_int32 writeContent(const t_int8 *fmt, ...);
	t_int32 output(t_int8 *modName, const t_int8* fileName, const t_int8* funcName, t_int32 lineNum, stringI levelName, const t_int8 *fmt, va_list va);

};

typedef singletonI<logStdoutI> logStdoutSingleton;

#endif



