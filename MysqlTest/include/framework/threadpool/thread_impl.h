#ifndef THREAD_IMPL_H
#define THREAD_IMPL_H
#include <thread/thread_i.h>


class threadImpl
{
public:
	threadImpl();
	virtual ~threadImpl();

public:
	t_int32 create();	//�����߳�
	t_int32 kill();		//�����߳�	
	
	t_int32 start();
	t_int32 stop();

	t_int32 join();
	t_int32 resume (hthread_t);	//�ָ��߳�
	t_int32 suspend (hthread_t);//�����߳�
	
	virtual void run();

	static void* threadProc(void*);
	hthread_t getThreadID();

private:
	hthread_t	m_threadId;
};
#endif
