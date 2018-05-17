/**
 * 	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:Atomic_i.h
 *
 * 	@brief:  此文件是智能指针中计数类的实现
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
 * 	@brief:		fw_atomic_t为最基本的计数类，引用计数值为int，支持增加引用计数，减少引用计数
 * 	@author:	chenjiang modify
 *	@date:		2012-12-21
 *	@note:	
 */
typedef struct fw_atomic_t
{
	volatile t_int32 counter;//定义一个计数的变量
	mutexI _mutex;

	fw_atomic_t()//构造函数创建atomic_t对象时counter=0
	{
		counter = 0;
		
	}

	virtual ~fw_atomic_t()//析构atomic_t对象时，counter = 0
	{
		counter = 0;
	}

	t_int32 add_return(t_int32 count)//counter 增加 count
	{
		volatile t_int32 mCount = 0;
		_mutex.acquire();
		counter += count;
		mCount = counter;
		_mutex.release();
	

		return mCount;
	}


	t_int32 sub_return(t_int32 count)//counter减少count
	{
		return add_return(-count);
	}
}fw_atomic_t;


/** 
 *
 *	class:		atomicI
 * 	@brief:		atomicI为升级版的计数类，引用计数值为void*型的指针，支持增加引用计数，减少引用计数
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
	t_bool ref();//计数器加1，引用计数大于0，返回true，引用计数小于0，返回false
	

	t_bool deref();//计数器减1，引用计数小于等于0，返回true，引用计数大于0，返回false


private:
	void  *_value;//mValue指向引用计数类
	
};

#endif

