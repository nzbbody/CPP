#ifndef THREAD_JOB2_I_H
#define THREAD_JOB2_I_H

#include <threadpool/thread_impl.h>

class DLL_EXPORT jobI
{
public:
	jobI();
	virtual ~jobI();

public:
	/** 
	* 	func name:	getJobNo
	*	@brief:		��ȡ������
	*	@param:		void
	*	@return:	������
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	t_int32	getJobNo(void);

	/** 
	* 	func name:	setJobNo
	*	@brief:		����������
	*	@param:		job��������
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	setJobNo(int jobno);

	/** 
	* 	func name:	getJobName
	*	@brief:		��ȡ��������
	*	@param:		void
	*	@return:	��������
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	char*	getJobName(void);

	/** 
	* 	func name:	setJobName
	*	@brief:		������������
	*	@param:		��������
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	setJobName(char* jobname);

	/** 
	* 	func name:	getWorkThread
	*	@brief:		��ȡ�����߳�ָ��
	*	@param:		void
	*	@return:	�����߳�ָ��
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	threadImpl*	getWorkThread(void);

	/** 
	* 	func name:	setWorkThread
	*	@brief:		���ù����߳�ָ��
	*	@param:		�����߳�ָ��
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	setWorkThread (threadImpl *pWorkThread);

	/** 
	* 	func name:	run
	*	@brief:		�������нӿ�(����ӿ�)
	*	@param:		ptr���������
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	virtual void run ( void *ptr ) = 0;

private:
	t_int32	m_JobNo;
	t_int8	*m_JobName;
	threadImpl	*m_pWorkThread;
};

#endif
