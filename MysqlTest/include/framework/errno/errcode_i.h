/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file	:			edp_errcode.h
 * 	@brief	:			edp_errcode.h定义了errCode类，完成多当前错误码的处理；
 * 	@author	:			ning_shuanglong 
 *	@note	:	
 *	@modify	:			hehairan add 注释
 */

#ifndef _ERRCODE_I_H_
#define _ERRCODE_I_H_

 #include <thread/os_thread_i.h>
/** 
 *
 *	class:		errcode
 * 	@brief:		errcode完成对当前错误码的处理，其中包括三个方法:instance方法、重载int方法、重载=操作符方法	
 * 	@author:	ning_shuanglong
 *	@date:		2012-08-08
 *	@note:	
 */
class DLL_EXPORT errCode
{
public:
	errCode();
	

public:
	/** 
	*
	* 	func name	:	instance
	*	@brief		:	将当前errnoKey实例化
	*	@param		:	file---当前代码所在的文件;
	*	@param		:	func---当前代码所在的函数;
	*	@param		:	line---当前代码所在的行数;
	*	@return		:	errCode指针
	*	@author		:	ning_shuanglong
	*	@note:			
	*
	*/
	static errCode* instance(const char *file, const char*func,  int line);
	static t_int32 lastError();
public:
	operator int(void) const;
	int operator=(int);


	
public:
	thread_key_t errnoKey;		/** 当前线程的键值 */
	
	const char *mfile;			/** 当前程序所在的文件名 */
	const char *mfunc;			/** 当前代码所在的函数名 */
	int mline;					/** 当前代码所在的行数 */
};

#define platErrno (* (errCode::instance(__FILE__,__FUNCTION__, __LINE__)))



#endif
