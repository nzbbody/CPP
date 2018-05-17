#ifndef THREAD_POOL_I_H
#define THREAD_POOL_I_H

#include <data_types.h>
#include <threadpool/thread_job_i.h>
#include <mutex_i.h>
#include <condition_i.h>
#include <common_inc.h>

class threadPool
{
friend class workerThread;

public:
	threadPool();
	threadPool(t_int32 initnum);
	virtual ~threadPool();

public:
	void    setMaxNum(t_int32 maxnum);
	t_int32 getMaxNum(void);
	void    setAvailLowNum(t_int32 minnum);
	t_int32 getAvailLowNum(void);
	void    setAvailHighNum(t_int32 highnum);
	t_int32 getAvailHighNum(void);
	t_int32 getActualAvailNum(void);
	t_int32 getAllNum(void);
	t_int32	getBusyNum(void);
	void    setInitNum(t_int32 initnum);
	t_int32     getInitNum(void);

	void    terminateAll(void);
	void    run(threadJob* job, void* jobdata);

protected:
	workerThread* getIdleThread(void);

	void    appendToIdleList(workerThread* jobthread);
	void    moveToBusyList(workerThread* idlethread);
	void    moveToIdleList(workerThread* busythread);

	void    deleteIdleThread(t_int32 num);
	void    createIdleThread(t_int32 num);

public:
	mutexI	m_busyMutex;    //when visit busy list,use m_BusyMutex to lock and unlock
	mutexI	m_idleMutex;    //when visit idle list,use m_IdleMutex to lock and unlock
	mutexI	m_jobMutex;	//when visit job list,use m_JobMutex to lock and unlock
	mutexI	m_varMutex;

	conditionI	m_busyCond; //m_BusyCond is used to sync busy thread list
	conditionI	m_idleCond; //m_IdleCond is used to sync idle thread list
	conditionI	m_idleJobCond;  //m_JobCond is used to sync job list
	conditionI	m_maxNumCond;

	vector<workerThread*>   m_threadList;//记录所有线程的队列
	vector<workerThread*>   m_busyList;  //工作队列
	vector<workerThread*>   m_idleList;  //空闲队列

private:
	t_uint32 m_maxNum;   //线程池中最大线程数
	t_uint32 m_availLow; //空闲队列的最小值
	t_uint32 m_availHigh;//空闲队列的最大值
	t_uint32 m_availNum; //空闲队列的正常值
	t_uint32 m_initNum;  //初始化线程池线程个数;

};

#endif