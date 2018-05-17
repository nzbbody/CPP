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
	*	@brief:		获取任务编号
	*	@param:		void
	*	@return:	任务编号
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	t_int32	getJobNo(void);

	/** 
	* 	func name:	setJobNo
	*	@brief:		设置任务编号
	*	@param:		job：任务编号
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	setJobNo(int jobno);

	/** 
	* 	func name:	getJobName
	*	@brief:		获取任务名称
	*	@param:		void
	*	@return:	任务名称
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	char*	getJobName(void);

	/** 
	* 	func name:	setJobName
	*	@brief:		设置任务名称
	*	@param:		任务名称
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	setJobName(char* jobname);

	/** 
	* 	func name:	getWorkThread
	*	@brief:		获取工作线程指针
	*	@param:		void
	*	@return:	工作线程指针
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	threadImpl*	getWorkThread(void);

	/** 
	* 	func name:	setWorkThread
	*	@brief:		设置工作线程指针
	*	@param:		工作线程指针
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	setWorkThread (threadImpl *pWorkThread);

	/** 
	* 	func name:	run
	*	@brief:		任务运行接口(纯虚接口)
	*	@param:		ptr：任务参数
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
