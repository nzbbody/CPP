#ifndef THREAD_MANAGER_I_H
#define THREAD_MANAGER_I_H

#include <threadpool/thread_pool_i.h>

#define THREADPOOL_DEFAULT_SIZE	10

class DLL_EXPORT threadManager
{
public:
	/** 
	* 	func name:	threadManager
	*	@brief:		��ʼ��һ���̳߳�
	*	@param:		void
	*	@return:	NULL
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:		�̳߳�Ĭ������10���߳�
	*/
	threadManager();
	/** 
	* 	func name:	threadManager
	*	@brief:		��ʼ��һ���̳߳�
	*	@param:		�̳߳����̸߳���
	*	@return:	NULL
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	threadManager(int num);
	virtual ~threadManager();

public:
	/** 
	* 	func name:	start
	*	@brief:		�̳߳�����
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	start();

	/** 
	* 	func name:	run
	*	@brief:		���������ý��̳߳أ���������
	*	@param:		job������jobdata:�������
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void    run(jobI* job, void* jobdata);

	/** 
	* 	func name:	stop
	*	@brief:		ֹͣ�̳߳�
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	stop();

private:
	threadPoolI	*m_pool;		//�̳߳�ָ��
	t_int32		m_numOfThread;	//�̳߳����̸߳���
};


#endif
