/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _MODULES_FACTORY_IMPL_H
#define _MODULES_FACTORY_IMPL_H

#include <modules/modules_factory_i.h>

class modulesFactoryImpl : public modulesFactoryI
{
	DECLARE_SUPPORTI

public:
	/**
	* @fun name	: create() :创建模块工厂
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: sI:support接口
	* @param	: mid 模块ID
	* @param	: instancePtr 返回的模块工厂
	* @param	: E_OK:成功  E_NOMEN:无内存可用
	*
	*/
	static t_int32 create(supportI *sI, const mIID &mid, void **instancePtr);

	/**
	* @fun name	:createInstance()
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: sI: support接口
	* @param	: mid: 模块ID
	* @param	: result:输出值
	* @result	: E_OK
	* @note		: 通过模块工厂创建组件实例
	*/
	t_int32 createInstance(supportI *sI, const mIID &mid, void **result);

	/**
	* @fun name	: runSelf()
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: lock 运行锁
	* @result	: 
	* @note		: 通过模块工厂来运行组件自运行接口
	*/
	t_int32 runSelf(t_bool lock);

	/**
	* @fun name	: setModulesInfo()
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: info 模块信息
	* @result	: E_OK
	* @note		: 通过模块工厂设置模块信息
	*/
	t_int32 setModulesInfo(const modulesInfo *info);

	/**
	* @fun name	: getModulesInfo()
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: info 模块信息
	* @result	: E_OK
	* @note		: 获取模块工厂设置模块信息
	*/
	t_int32 getModulesInfo(const modulesInfo **info);
	

private:
	const modulesInfo *mInfo;
};

#endif

