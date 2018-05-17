#ifndef _THREAD_POOL2_I_H_
#define _THREAD_POOL2_I_H_
#include <list_i.h>
#include <data_types.h>
#include <threadpool/thread_job_i.h>

#include <mutex_i.h>
#include <event_timer_i.h>
#include <event_notify_i.h>

typedef struct
{
	jobI*		m_pJob;
	void*		m_jobData;

}jobStruct;

class workerThreadI;

class threadPoolI
{
public:
	threadPoolI();
	threadPoolI(t_int32 threadNum);
	virtual ~threadPoolI();

public:
	t_int32 start();	//线程池启动接口
	t_int32 run(jobI* pJob, void* jobData);	//调用run接口，将任务加入到线程池中
	t_int32 stop();		//线程池停止接口

public:
	t_int32 startInside();	//线程池启动处理函数
	t_int32 timerInside();	//线程池定时器处理函数
	t_int32 stopInside();	//线程池停止处理函数

public:
	static void* threadFunc(void* args);	//线程池启动回调函数
	static t_int32 poolTimerCb(void* args);	//线程池中定时器回调函数
	static t_int32 stopNotifyCb(void* args);//线程池停止回调函数

public:
	t_int32 appendToIdleList(workerThreadI*);	//将工作线程加入到空闲队列中
	t_int32 moveToIdleList(workerThreadI*);		//移动工作线程到空闲队列中
	t_int32 moveToBusyList(workerThreadI*);		//移动工作线程到忙碌队列中

private:
	void freeAllJob();		//释放任务队列中任务
	void freeAllThread();	//释放所有线程

private:
	mutexI		m_threadPoolLock;	//管理线程锁，避免当主线程启动时，上层用户发送停止命令

private:
	std::list<jobStruct*>	m_jobList;
	mutexI				m_jobListLock;

	std::list<workerThreadI*>   m_threadList;	//总的线程列表
	std::list<workerThreadI*>   m_busyList;		//工作列表
	std::list<workerThreadI*>   m_idleList;		//空闲列表
	mutexI				m_threadLock;
	mutexI				m_busyLock;
	mutexI				m_idleLock;
private:
	hthread_t	m_handle;
	t_int32		m_threadNum;	//线程池中线程总数
	t_int32		m_busyNum;		//线程池中忙碌线程数
	t_int32		m_idleNum;		//线程池中空闲线程数

private:
	eventTimerI	m_timer;	//线程池定时器，定时查看任务列表里面有没有任务
	eventNotifyI	m_notify;//线程池通知，用于关闭线程池
};	



#endif


