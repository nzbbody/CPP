/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 *
 * @file:modules_fatory_i.h
 *
 * @description:ģ�鹤��ͷ�ļ�
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
	*	@brief		:	ͨ��ģ�鹤������ģ����Ϣ        
	*	@param		:	modulesInfo *info ģ����Ϣ	    
	*	@return		:	E_OK
	*	@author		:	zhangsb     
	*	@note:			
	*
	*/
	virtual t_int32 setModulesInfo(const modulesInfo *info) = 0;
	
	
	/** 
	*
	* 	func name	:	getNext
	*	@brief		:	ͨ��ģ�鹤����ȡģ����Ϣ        
	*	@output		:	modulesInfo *info ��ȡ��ģ����Ϣ	    
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
*	@brief		:	����ģ��ע����Ҫ�Ĺ���        
*	@input		:	modulesInfo *info ��ȡ��ģ����Ϣ	  
*	@output		:	���ص�ģ�鹤��
*	@return		:	E_OK
*	@author		:	zhangsb     
*	@note:			
*
*/
t_int32 newRegisterModulesFactory(modulesFactoryI **fact, const modulesInfo *info);




#endif

