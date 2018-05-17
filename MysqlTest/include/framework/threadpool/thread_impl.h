#ifndef THREAD_IMPL_H
#define THREAD_IMPL_H
#include <thread/thread_i.h>


class threadImpl
{
public:
	threadImpl();
	virtual ~threadImpl();

public:
	t_int32 create();	//创建线程
	t_int32 kill();		//销毁线程	
	
	t_int32 start();
	t_int32 stop();

	t_int32 join();
	t_int32 resume (hthread_t);	//恢复线程
	t_int32 suspend (hthread_t);//挂起线程
	
	virtual void run();

	static void* threadProc(void*);
	hthread_t getThreadID();

private:
	hthread_t	m_threadId;
};
#endif
