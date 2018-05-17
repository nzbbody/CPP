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
	static T *instance()//������һ�����ʵ����������ָ��������ʵ����ָ��
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

	static void uninstance()//���ٵ�����
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

