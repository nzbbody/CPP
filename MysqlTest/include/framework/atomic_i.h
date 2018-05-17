/**
 * 	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:Atomic_i.h
 *
 * 	@brief:  ���ļ�������ָ���м������ʵ��
 *
 * 	@author:  chenjiang modify
 * 
 *	@date:		2012-12-21
 *
 * 	@note:
 */

#ifndef _ATOMIC_I_H
#define _ATOMIC_I_H

#include <data_types.h>
#include <mutex_i.h>
#include <memory_i.h>

/** 
 *
 *	class:		fw_atomic_t
 * 	@brief:		fw_atomic_tΪ������ļ����࣬���ü���ֵΪint��֧���������ü������������ü���
 * 	@author:	chenjiang modify
 *	@date:		2012-12-21
 *	@note:	
 */
typedef struct fw_atomic_t
{
	volatile t_int32 counter;//����һ�������ı���
	mutexI _mutex;

	fw_atomic_t()//���캯������atomic_t����ʱcounter=0
	{
		counter = 0;
		
	}

	virtual ~fw_atomic_t()//����atomic_t����ʱ��counter = 0
	{
		counter = 0;
	}

	t_int32 add_return(t_int32 count)//counter ���� count
	{
		volatile t_int32 mCount = 0;
		_mutex.acquire();
		counter += count;
		mCount = counter;
		_mutex.release();
	

		return mCount;
	}


	t_int32 sub_return(t_int32 count)//counter����count
	{
		return add_return(-count);
	}
}fw_atomic_t;


/** 
 *
 *	class:		atomicI
 * 	@brief:		atomicIΪ������ļ����࣬���ü���ֵΪvoid*�͵�ָ�룬֧���������ü������������ü���
 * 	@author:	 modify
 *	@date:		2012-12-21
 *	@note:	
 */
class DLL_EXPORT atomicI
{
public:
	atomicI();
	
	
	virtual ~atomicI();

public:
	t_bool ref();//��������1�����ü�������0������true�����ü���С��0������false
	

	t_bool deref();//��������1�����ü���С�ڵ���0������true�����ü�������0������false


private:
	void  *_value;//mValueָ�����ü�����
	
};

#endif

