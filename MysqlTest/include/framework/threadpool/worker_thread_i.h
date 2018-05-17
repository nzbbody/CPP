#ifndef WORKER_THREAD2_I_H
#define WORKER_THREAD2_I_H
#include <threadpool/thread_impl.h>
#include <threadpool/thread_job_i.h>
#include <threadpool/thread_pool_i.h>
#include <event_notify_i.h>

class workerThreadI:public threadImpl
{
public:
	workerThreadI();
	virtual ~workerThreadI();

public:
	virtual void run();	//线程运行函数
	virtual void stop();//线程停止函数
	void    setJob(jobI* job,void* jobdata);	//将任务塞入工作线程去运行
	jobI*   getJob(void);	//获取当前线程正在处理的任务
	void    setThreadPool(threadPoolI* thrpool);	//设置当前线程所处的线程池
	threadPoolI* getThreadPool(void);	//获取线程池指针

public:
	t_int32 onEvent();
	t_int32 stopInside();
	static t_int32 jobNotifyCb(void*);
	static t_int32 stopNotifyCb(void*);

public:
	mutexI	m_workMutex;

private:
	threadPoolI*	m_threadPool;
	jobI*		m_job;
	void*	m_jobData; 

	eventNotifyI	m_notify;
	mutexI	m_varMutex;
	eventNotifyI	m_stopNotify;
private:
	t_int32 m_threadState;
};

#endif
