/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
*
*	@file	:			time_i.h
* 	@brief	:			���ļ���Ҫ�ṩ����ʱ�����ز��������ȡ��ǰʱ�䣬����ϵͳʱ���
* 	@author	:         
*	@note	:	
*	@modify	:			 hehairan addע��ͷ
 */

#ifndef _TIME_I_H 
#define _TIME_I_H

#include <data_types.h>
#include <string/string_i.h>
#include <errno/error_i.h>
#include <datetime_i.h>

class DLL_EXPORT timeI
{
public:
	static t_int32 datetimeUpdate();///��ϵͳʱ����µ�framework


public:
	static datetime_t *datetime(void);///��ȡϵͳʱ��
	static t_int32 datetime(datetime_t *datetime);///����ϵͳʱ��

	static t_int32 hwclock_set(void);///����rtcʱ��
public:
	static const t_int8 *datetimeLiteral(void);///��ʽ��ʱ��(Fri Aug 19 09:38:33 2011)
	static const t_int8 *datetimeDigit(void);///��ʽ��ʱ��(2011-08-19 09:37:33 W(5))
	static const t_int8 *datetimeSample(void);///��ʽ��ʱ��(2011/08/19 09:37:33)
	static const t_int8 *datetimeUtc(void);///��ʽ��ʱ��(20110819T093733Z)
public:
	static t_int32 getTimeOfDay(timeval_t *tv);
	static datetime_compare datetimeCompare(datetime_t *dt1, datetime_t *dt2);


public:
	static t_int32 sec2datetime(t_uint32 time, datetime_t *datetime);
	static t_int32 datetime2sec(t_uint32 &time, datetime_t *datetime);

public:
	
	/** 
	* 	func name	:		getTimeZone
	*	@brief		:	    ��ȡϵͳʱ��
	*	@param		��		void
	*	@return		:		��ǰ��ϵͳʱ��
	*	@author		:	    zhang_xusheng
	*	@note		:		Ŀǰ��֧��linux(2015-1-16)
	*/
	static t_int32 getTimeZone();

	/** 
	* 	func name	:		setTimeZone
	*	@brief		:	    ����ϵͳʱ��
	*	@param		��		ϵͳʱ��(��Чֵ��-12����+12)
	*	@return		:		E_OK�����óɹ���E_FAIL������ʧ��
	*	@author		:	    zhang_xusheng
	*	@note1		:		Ŀǰ��֧��linux(2015-1-16)
	*	@note2		��		�ú�����Ҫ�ڳ����û�Ȩ����ʹ��
	*/
	static t_int32 setTimeZone(t_int32 timeZone);
	
};


#endif
