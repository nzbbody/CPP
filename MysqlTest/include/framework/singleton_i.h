/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _SINGLETON_I_H
#define _SINGLETON_I_H
#include <memory_i.h>
#include <mutex_i.h>

template <class T>
class singletonI
{
public:
	static T *instance()//创建并一个类的实例，并返回指向这个类的实例的指针
	{
		if (mInstance == 0)
		{
			m_lock.acquire();
			
			if(mInstance == 0)
			{
				mInstance = os_new(T);
			}

			m_lock.release();
		}
		
		return mInstance;
	}

	static void uninstance()//销毁单件类
	{
		if(mInstance != 0)
		{
			os_delete(mInstance);
			mInstance = 0;
		}
	}
	
protected:
	singletonI();
	virtual ~singletonI();

private:
	static T *mInstance;
	static mutexI m_lock;
};

template <class T>
T * singletonI<T>::mInstance = 0;
template <class T>
mutexI singletonI<T>::m_lock;

#endif

