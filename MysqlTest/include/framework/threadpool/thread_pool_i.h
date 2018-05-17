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
	t_int32 start();	//�̳߳������ӿ�
	t_int32 run(jobI* pJob, void* jobData);	//����run�ӿڣ���������뵽�̳߳���
	t_int32 stop();		//�̳߳�ֹͣ�ӿ�

public:
	t_int32 startInside();	//�̳߳�����������
	t_int32 timerInside();	//�̳߳ض�ʱ��������
	t_int32 stopInside();	//�̳߳�ֹͣ������

public:
	static void* threadFunc(void* args);	//�̳߳������ص�����
	static t_int32 poolTimerCb(void* args);	//�̳߳��ж�ʱ���ص�����
	static t_int32 stopNotifyCb(void* args);//�̳߳�ֹͣ�ص�����

public:
	t_int32 appendToIdleList(workerThreadI*);	//�������̼߳��뵽���ж�����
	t_int32 moveToIdleList(workerThreadI*);		//�ƶ������̵߳����ж�����
	t_int32 moveToBusyList(workerThreadI*);		//�ƶ������̵߳�æµ������

private:
	void freeAllJob();		//�ͷ��������������
	void freeAllThread();	//�ͷ������߳�

private:
	mutexI		m_threadPoolLock;	//�����߳��������⵱���߳�����ʱ���ϲ��û�����ֹͣ����

private:
	std::list<jobStruct*>	m_jobList;
	mutexI				m_jobListLock;

	std::list<workerThreadI*>   m_threadList;	//�ܵ��߳��б�
	std::list<workerThreadI*>   m_busyList;		//�����б�
	std::list<workerThreadI*>   m_idleList;		//�����б�
	mutexI				m_threadLock;
	mutexI				m_busyLock;
	mutexI				m_idleLock;
private:
	hthread_t	m_handle;
	t_int32		m_threadNum;	//�̳߳����߳�����
	t_int32		m_busyNum;		//�̳߳���æµ�߳���
	t_int32		m_idleNum;		//�̳߳��п����߳���

private:
	eventTimerI	m_timer;	//�̳߳ض�ʱ������ʱ�鿴�����б�������û������
	eventNotifyI	m_notify;//�̳߳�֪ͨ�����ڹر��̳߳�
};	



#endif


