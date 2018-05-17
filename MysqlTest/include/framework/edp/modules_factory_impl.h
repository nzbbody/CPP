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
	* @fun name	: create() :����ģ�鹤��
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: sI:support�ӿ�
	* @param	: mid ģ��ID
	* @param	: instancePtr ���ص�ģ�鹤��
	* @param	: E_OK:�ɹ�  E_NOMEN:���ڴ����
	*
	*/
	static t_int32 create(supportI *sI, const mIID &mid, void **instancePtr);

	/**
	* @fun name	:createInstance()
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: sI: support�ӿ�
	* @param	: mid: ģ��ID
	* @param	: result:���ֵ
	* @result	: E_OK
	* @note		: ͨ��ģ�鹤���������ʵ��
	*/
	t_int32 createInstance(supportI *sI, const mIID &mid, void **result);

	/**
	* @fun name	: runSelf()
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: lock ������
	* @result	: 
	* @note		: ͨ��ģ�鹤����������������нӿ�
	*/
	t_int32 runSelf(t_bool lock);

	/**
	* @fun name	: setModulesInfo()
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: info ģ����Ϣ
	* @result	: E_OK
	* @note		: ͨ��ģ�鹤������ģ����Ϣ
	*/
	t_int32 setModulesInfo(const modulesInfo *info);

	/**
	* @fun name	: getModulesInfo()
	* @author	: zhangsb
	* @date		: 2012-04-09
	* @param	: info ģ����Ϣ
	* @result	: E_OK
	* @note		: ��ȡģ�鹤������ģ����Ϣ
	*/
	t_int32 getModulesInfo(const modulesInfo **info);
	

private:
	const modulesInfo *mInfo;
};

#endif

