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
 *  ģ���������ʼ��
 * \author zhangsb
 * \date 2012-04-05
 * \param envBase ϵͳ���л���, ��Ҫ��ȡ��̬������·��
 * \see moduleExit()
 *
 */
t_int32 DLL_EXPORT modulesInit(environmentBase &envBase);

/**
 *  ����������ģ�����
 * \author zhangsb
 * \date 2012-04-05
 * \param envBase ϵͳ���л���
 * 
 *
 */
t_int32 DLL_EXPORT modulesRun();

/**
 *  ģ��������˳�,ע�����е�ģ�����
 * \author zhangsb
 * \date 2012-04-05
 * \param envBase ϵͳ���л���
 * \see moduleInit()
 *
 */
t_int32 DLL_EXPORT modulesExit(environmentBase &envBase);

/**
 *  �������ʵ��
 * \author zhangsb
 * \date 2012-04-05
 * \param mid ģ��ID
 * \param result �������ʵ��
 *
 */
t_int32 DLL_EXPORT modulesCreateInstance(const mIID &mid, void **result);

/**
 *  ���������ͬ��ʵ��
 * \author zhangsb
 * \date 2012-04-05
 * \param envBase ϵͳ���л���
 * \param qid ��ѯ�ӿ�ID
 * \param result �������ʵ��
 *
 */
t_int32 DLL_EXPORT modulesCreateInstanceByQid(const mIID &mid, const qIID &qid, void **result);

#endif

