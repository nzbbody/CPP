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
	virtual void run();	//�߳����к���
	virtual void stop();//�߳�ֹͣ����
	void    setJob(jobI* job,void* jobdata);	//���������빤���߳�ȥ����
	jobI*   getJob(void);	//��ȡ��ǰ�߳����ڴ��������
	void    setThreadPool(threadPoolI* thrpool);	//���õ�ǰ�߳��������̳߳�
	threadPoolI* getThreadPool(void);	//��ȡ�̳߳�ָ��

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
