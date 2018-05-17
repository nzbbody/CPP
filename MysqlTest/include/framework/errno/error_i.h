/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _ERROR_I_H
#define _ERROR_I_H

#include <data_types.h>
#include <errno/errno_i.h>

#define E_OK 					0

#undef E_FAIL
#define E_FAIL					-1

/** 
	错误码1类:

*/
#define E_NOIMPL				0x1000
#define E_NOIFR					0x1001
#define E_INVALPTR				0x1002
#define E_PARA					0x1003
#define E_NOMEM					0x1004
#define E_SYMBOL				0x1005
#define E_LIBFUNC				0x1006
#define E_DOWN					0x1007
#define E_SYSAPI				0x1008
/**
	错误码2类:
	以下错误码表示中间过程,
	可以视为不是错误
	
*/
#define E_WAIT					0x2000
#define E_IGNORE				0x2001


static inline t_int32 E_FAILED(t_int32 result)
{
	return (result == -1);
}
static inline t_int32 E_SUCCESSED(t_int32 result)
{
	return !(result);
}


#include <errno/errcode_i.h>

#endif

