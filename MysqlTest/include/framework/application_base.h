/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 * ƽ̨��ܲ����࣬ʹ��ƽ̨�����￪ʼ
 */

#ifndef _APPLICATION_BASE_H
#define _APPLICATION_BASE_H

#include <data_types.h>
#include <environment_base.h>
#include <string/string_i.h>

class DLL_EXPORT applicationBase
{
public:
	applicationBase();
	virtual ~applicationBase();

public:
	/** 
	*
	* 	func name:		setApplicationName
	*	@brief:			����ƽ̨��Name
	*	@param:			ƽ̨Name
	*	@return:		���óɹ�����E_OK�����󷵻�E_FAIL
	*	@author:		zhangsb
	*	@modify:		zhangxs(2013-3-26)--init by path,no parsepath(path)
	*	@note:			
	*
	*/
	t_int32 setApplicationName(t_int8 *name);
	/** 
	*
	* 	func name:		getApplicationName
	*	@brief:			��ȡƽ̨��Name
	*	@param:			ƽ̨Name
	*	@return:		���óɹ�����E_OK�����󷵻�E_FAIL
	*	@author:		zhangsb
	*	@modify:		zhangxs(2013-3-26)--init by path,no parsepath(path)
	*	@note:			
	*
	*/
	t_int32 getApplicationName(t_int8 **name);
	
public:
	/** 
	*
	* 	func name:		initInstance
	*	@brief:	        ƽ̨��ʼ��
	*	@param:			argc��argv
	*	@return:		��ʼ���ɹ�����E_OK�����󷵻�E_FAIL
	*	@author:	    unknown
	*	@modify:		zhangxs(2013-3-26)--init by path,no parsepath(path)
	*	@note:			
	*
	*/
	t_int32 initInstance(t_int8* configFile);
	t_int32 initInstance(t_int32 argc, t_int8* argv[]);
	t_int32 initInstance();
	/** 
	*
	* 	func name:		exitInstance
	*	@brief:	        �˳�ƽ̨
	*	@param:			NULL
	*	@return:		�ɹ��˳�����E_OK�����󷵻�E_FAIL
	*	@author:	    unknown
	*	@modify:		zhangxs(2013-3-26)--init by path,no parsepath(path)
	*	@note:			
	*
	*/
	t_int32 exitInstance();	

public:
	/** 
	*
	* 	func name:	run
	*	@brief:	        ƽ̨����
	*	@param:		NULL
	*	@return:		�����ɹ�����E_OK�����󷵻�E_FAIL
	*	@author:	    unknown
	*	@modify:		zhangxs(2013-3-26)--init by path,no parsepath(path)
	*	@note:			
	*
	*/
	t_int32 run();
	
private:
	environmentBase envBase;	//ƽ̨�����û���
	
};

//Ϊ�˸��ϲ��û��ṩ��ȡ����·���Ľӿڣ�add by zhangxs on 2013-10-10
/** 
*
* 	func name:		getApplicationConfigPath
*	@brief:			��ȡƽ̨������·��
*	@param:			ƽ̨Name
*	@return:		���óɹ�����E_OK�����󷵻�E_FAIL
*	@author:		zhangxs
*	@note:			
*
*/
stringI DLL_EXPORT getApplicationConfigPath();

t_int32 signalCatch();

void signalProcess(t_int32 signalNum);

#endif

