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
	virtual t_int32 createInstance(const mIID &mid, void **result) = 0;							///�����ӿ�
	virtual t_int32 createInstanceByQid(const mIID &mid, const qIID &qid, void **result) = 0;	///ͨ��qId�����ӿ�
	virtual t_int32 newModulesImpl(modulesInfoObject *mObject, modulesI **result) = 0;			///����ģ��ʵ�ֶ���
	virtual t_int32 registerModulesFactory(const modulesInfo *info) = 0;						///ע��ģ�鹤��
	virtual t_int32 autoRunModules(void) = 0;													///�Զ�ע��ģ��
	
public:												
	
	DECLARE_MODULE_IID(MODULES_MANAGER_I_MID)
};

DEFINE_MODULE_IID(modulesManagerI, MODULES_MANAGER_I_MID)

#endif


