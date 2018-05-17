/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _MODULES_INIT_H
#define _MODULES_INIT_H

#include <data_types.h>
#include <modules/modules_i.h>
#include <modules/modules_manager_i.h>
#include <environment_base.h>


/**
 *  模块管理器初始化
 * \author zhangsb
 * \date 2012-04-05
 * \param envBase 系统运行环境, 需要获取动态组件存放路径
 * \see moduleExit()
 *
 */
t_int32 DLL_EXPORT modulesInit(environmentBase &envBase);

/**
 *  运行自启动模块组件
 * \author zhangsb
 * \date 2012-04-05
 * \param envBase 系统运行环境
 * 
 *
 */
t_int32 DLL_EXPORT modulesRun();

/**
 *  模块管理器退出,注销所有的模块组件
 * \author zhangsb
 * \date 2012-04-05
 * \param envBase 系统运行环境
 * \see moduleInit()
 *
 */
t_int32 DLL_EXPORT modulesExit(environmentBase &envBase);

/**
 *  创建组件实例
 * \author zhangsb
 * \date 2012-04-05
 * \param mid 模块ID
 * \param result 返回组件实例
 *
 */
t_int32 DLL_EXPORT modulesCreateInstance(const mIID &mid, void **result);

/**
 *  创建组件不同的实例
 * \author zhangsb
 * \date 2012-04-05
 * \param envBase 系统运行环境
 * \param qid 查询接口ID
 * \param result 返回组件实例
 *
 */
t_int32 DLL_EXPORT modulesCreateInstanceByQid(const mIID &mid, const qIID &qid, void **result);

#endif

