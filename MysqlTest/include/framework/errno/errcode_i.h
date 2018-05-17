/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file	:			edp_errcode.h
 * 	@brief	:			edp_errcode.h������errCode�࣬��ɶ൱ǰ������Ĵ���
 * 	@author	:			ning_shuanglong 
 *	@note	:	
 *	@modify	:			hehairan add ע��
 */

#ifndef _ERRCODE_I_H_
#define _ERRCODE_I_H_

 #include <thread/os_thread_i.h>
/** 
 *
 *	class:		errcode
 * 	@brief:		errcode��ɶԵ�ǰ������Ĵ������а�����������:instance����������int����������=����������	
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
	*	@brief		:	����ǰerrnoKeyʵ����
	*	@param		:	file---��ǰ�������ڵ��ļ�;
	*	@param		:	func---��ǰ�������ڵĺ���;
	*	@param		:	line---��ǰ�������ڵ�����;
	*	@return		:	errCodeָ��
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
	thread_key_t errnoKey;		/** ��ǰ�̵߳ļ�ֵ */
	
	const char *mfile;			/** ��ǰ�������ڵ��ļ��� */
	const char *mfunc;			/** ��ǰ�������ڵĺ����� */
	int mline;					/** ��ǰ�������ڵ����� */
};

#define platErrno (* (errCode::instance(__FILE__,__FUNCTION__, __LINE__)))



#endif
