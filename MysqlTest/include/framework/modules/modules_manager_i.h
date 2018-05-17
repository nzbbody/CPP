/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _MODULES_MANAGER_I_H
#define _MODULES_MANAGER_I_H

#include <modules/support_i.h>

#include <data_types.h>
#include <modules/modules_i.h>

#define MODULES_MANAGER_I_NAME "modules manager interface name"
#define MODULES_MANAGER_I_MID {"modules manager interface mid",}

class modulesManagerI : public supportI
{
public:
	virtual t_int32 createInstance(const mIID &mid, void **result) = 0;							///创建接口
	virtual t_int32 createInstanceByQid(const mIID &mid, const qIID &qid, void **result) = 0;	///通过qId创建接口
	virtual t_int32 newModulesImpl(modulesInfoObject *mObject, modulesI **result) = 0;			///创建模块实现对象
	virtual t_int32 registerModulesFactory(const modulesInfo *info) = 0;						///注册模块工厂
	virtual t_int32 autoRunModules(void) = 0;													///自动注册模块
	
public:												
	
	DECLARE_MODULE_IID(MODULES_MANAGER_I_MID)
};

DEFINE_MODULE_IID(modulesManagerI, MODULES_MANAGER_I_MID)

#endif


