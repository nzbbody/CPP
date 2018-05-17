/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */


#ifndef _MODULES_MANAGER_IMPL_H
#define _MODULES_MANAGER_IMPL_H

#include <data_types.h>

#include <modules/modules_manager_i.h>
#include <modules/modules_register_i.h>
#include <modules/modules_loader_i.h>
#include <modules/factory_i.h>
#include <file_i.h>
#include <hash_table_i.h>  

class modulesManagerImpl : public modulesManagerI //public modulesRegisterI
{
	DECLARE_SUPPORTI

public:
	virtual t_int32 createInstance(const mIID &mid, void **result);
	virtual t_int32 createInstanceByQid(const mIID &mid, const qIID &qid, void **result);
	virtual t_int32 newModulesImpl(modulesInfoObject *mObject, modulesI **result);
	virtual t_int32 registerModulesFactory(const modulesInfo *info);
	virtual t_int32 autoRunModules(void);

	t_int32 autoRegister(fileI *dirFile);
	t_int32 autoUnregister(fileI *dirFile);
	t_int32 autoRegisterImpl(fileI *dirFile);
	t_int32 autoUnregisterImpl(fileI *dirFile);
	t_int32 autoRegisterDirectory(fileI *dirFile);
	t_int32 autoUnregisterDirectory(fileI *dirFile);
	t_int32 autoRegisterModule(fileI *fModule);
	t_int32 autoUnregisterModule(fileI *fModule);
	t_int32 autoRegisterByConfig(stringI configPath);
	t_int32 autoUnregisterConfig(stringI configPath);

	virtual t_int32 registerFactory(const mIID &mid, const t_int8 *className, factoryI *factory);
	virtual t_int32 unregisterFactory(const mIID &mid, factoryI *factory);

	virtual t_int32 getFactoryEntry(const mIID &mid, void **result);

public:
	modulesManagerImpl();
	virtual ~modulesManagerImpl();


	/**
	* 模块管理器初始化
	* \author zhangsb
	* \date 2012-04-07
	*
	*/
	t_int32 init(void);
	t_int32 exit(void);
	


private:
	modulesLoaderI *mModulesLoader;
	fileI *mModulesDir;
	hashTableI mFactories;

};


struct factoryhashTableIEntry : public hashTableIEntry
{
	factoryhashTableIEntry(const mIID &mid, const t_int8 *className, factoryI *factory) :
	mID(mid), mClassName(className), mFactory(factory)
	{
	}

	~factoryhashTableIEntry();

	

	mIID mID;
	const t_int8 *mClassName;
	factoryI *mFactory;

	factoryhashTableIEntry *parent;

	factoryI *getFactory() { return mFactory; }

};


#endif
