/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _MODULES_IMPL_H
#define _MODULES_IMPL_H



#include <modules/modules_i.h>

class modulesImpl : public modulesI
{
	DECLARE_SUPPORTI
public:
	/**
		register component self
		@mgr: module manager
		@file: the associated dynamic library
	*/
	virtual t_int32 registerSelf(modulesManagerI *mgr, fileI *file);
	/**
		unregister component self
		@mgr: module manager
		@file: the associated dynamic library
	*/
	virtual t_int32 unregisterSelf(modulesManagerI *mgr, fileI *file);
	
public:
	modulesImpl();
	modulesImpl(const t_int8 *modulesName, 
		t_uint32 modulesCount, 
		const modulesInfo *modulesInfo);
	virtual ~modulesImpl();

private:
	const t_int8 *mModulesName;/// �������������
	t_uint32 mModulesCount;///������ǰģ��������Ŀ
	const modulesInfo *mModulesInfo;///���������������Ϣ
};


#endif


