/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
*
*	@file	:			time_i.h
* 	@brief	:			本文件主要提供关于时间的相关操作，如获取当前时间，设置系统时间等
* 	@author	:         
*	@note	:	
*	@modify	:			 hehairan add注释头
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
	static t_int32 datetimeUpdate();///将系统时间更新到framework


public:
	static datetime_t *datetime(void);///获取系统时间
	static t_int32 datetime(datetime_t *datetime);///设置系统时间

	static t_int32 hwclock_set(void);///设置rtc时间
public:
	static const t_int8 *datetimeLiteral(void);///格式化时间(Fri Aug 19 09:38:33 2011)
	static const t_int8 *datetimeDigit(void);///格式化时间(2011-08-19 09:37:33 W(5))
	static const t_int8 *datetimeSample(void);///格式化时间(2011/08/19 09:37:33)
	static const t_int8 *datetimeUtc(void);///格式化时间(20110819T093733Z)
public:
	static t_int32 getTimeOfDay(timeval_t *tv);
	static datetime_compare datetimeCompare(datetime_t *dt1, datetime_t *dt2);


public:
	static t_int32 sec2datetime(t_uint32 time, datetime_t *datetime);
	static t_int32 datetime2sec(t_uint32 &time, datetime_t *datetime);

public:
	
	/** 
	* 	func name	:		getTimeZone
	*	@brief		:	    获取系统时区
	*	@param		：		void
	*	@return		:		当前的系统时区
	*	@author		:	    zhang_xusheng
	*	@note		:		目前仅支持linux(2015-1-16)
	*/
	static t_int32 getTimeZone();

	/** 
	* 	func name	:		setTimeZone
	*	@brief		:	    设置系统时区
	*	@param		：		系统时区(有效值：-12——+12)
	*	@return		:		E_OK：设置成功，E_FAIL：设置失败
	*	@author		:	    zhang_xusheng
	*	@note1		:		目前仅支持linux(2015-1-16)
	*	@note2		：		该函数需要在超级用户权限下使用
	*/
	static t_int32 setTimeZone(t_int32 timeZone);
	
};


#endif
