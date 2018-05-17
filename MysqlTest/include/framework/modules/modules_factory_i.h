/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 *
 * @file:modules_fatory_i.h
 *
 * @description:模块工厂头文件
 *
 * @author:
 * 
 * @date:
 */


#ifndef _MODULES_FACTORY_I_H
#define _MODULES_FACTORY_I_H

#include <modules/factory_i.h>
#include <modules/modules_i.h>


#define MODULES_FACTORY_I_NAME "modules factory  interface name"
#define MODULES_FACTORY_I_MID {"modules factory interface mid",}


class modulesFactoryI : public factoryI
{
public:

	/** 
	*
	* 	func name	:	getNext
	*	@brief		:	通过模块工厂设置模块信息        
	*	@param		:	modulesInfo *info 模块信息	    
	*	@return		:	E_OK
	*	@author		:	zhangsb     
	*	@note:			
	*
	*/
	virtual t_int32 setModulesInfo(const modulesInfo *info) = 0;
	
	
	/** 
	*
	* 	func name	:	getNext
	*	@brief		:	通过模块工厂获取模块信息        
	*	@output		:	modulesInfo *info 获取的模块信息	    
	*	@return		:	E_OK
	*	@author		:	zhangsb     
	*	@note:			
	*
	*/
	virtual t_int32 getModulesInfo(const modulesInfo **info) = 0;

	DECLARE_MODULE_IID(MODULES_FACTORY_I_MID)
};

DEFINE_MODULE_IID(modulesFactoryI, MODULES_FACTORY_I_MID)


/** 
*
* 	func name	:	newRegisterModulesFactory
*	@brief		:	创建模块注册需要的工厂        
*	@input		:	modulesInfo *info 获取的模块信息	  
*	@output		:	返回的模块工厂
*	@return		:	E_OK
*	@author		:	zhangsb     
*	@note:			
*
*/
t_int32 newRegisterModulesFactory(modulesFactoryI **fact, const modulesInfo *info);




#endif

