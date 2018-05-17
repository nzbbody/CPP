/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 * 平台框架操作类，使用平台从这里开始
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
	*	@brief:			设置平台的Name
	*	@param:			平台Name
	*	@return:		设置成功返回E_OK，错误返回E_FAIL
	*	@author:		zhangsb
	*	@modify:		zhangxs(2013-3-26)--init by path,no parsepath(path)
	*	@note:			
	*
	*/
	t_int32 setApplicationName(t_int8 *name);
	/** 
	*
	* 	func name:		getApplicationName
	*	@brief:			获取平台的Name
	*	@param:			平台Name
	*	@return:		设置成功返回E_OK，错误返回E_FAIL
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
	*	@brief:	        平台初始化
	*	@param:			argc，argv
	*	@return:		初始化成功返回E_OK，错误返回E_FAIL
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
	*	@brief:	        退出平台
	*	@param:			NULL
	*	@return:		成功退出返回E_OK，错误返回E_FAIL
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
	*	@brief:	        平台启动
	*	@param:		NULL
	*	@return:		启动成功返回E_OK，错误返回E_FAIL
	*	@author:	    unknown
	*	@modify:		zhangxs(2013-3-26)--init by path,no parsepath(path)
	*	@note:			
	*
	*/
	t_int32 run();
	
private:
	environmentBase envBase;	//平台的配置环境
	
};

//为了给上层用户提供获取配置路径的接口，add by zhangxs on 2013-10-10
/** 
*
* 	func name:		getApplicationConfigPath
*	@brief:			获取平台的配置路径
*	@param:			平台Name
*	@return:		设置成功返回E_OK，错误返回E_FAIL
*	@author:		zhangxs
*	@note:			
*
*/
stringI DLL_EXPORT getApplicationConfigPath();

t_int32 signalCatch();

void signalProcess(t_int32 signalNum);

#endif

