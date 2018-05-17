#ifndef THREAD_MANAGER_I_H
#define THREAD_MANAGER_I_H

#include <threadpool/thread_pool_i.h>

#define THREADPOOL_DEFAULT_SIZE	10

class DLL_EXPORT threadManager
{
public:
	/** 
	* 	func name:	threadManager
	*	@brief:		初始化一个线程池
	*	@param:		void
	*	@return:	NULL
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:		线程池默认启动10个线程
	*/
	threadManager();
	/** 
	* 	func name:	threadManager
	*	@brief:		初始化一个线程池
	*	@param:		线程池中线程个数
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
	*	@brief:		线程池启动
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	start();

	/** 
	* 	func name:	run
	*	@brief:		将任务设置进线程池，运行任务
	*	@param:		job：任务；jobdata:任务参数
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void    run(jobI* job, void* jobdata);

	/** 
	* 	func name:	stop
	*	@brief:		停止线程池
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@date:		2014-3-18
	*	@note:
	*/
	void	stop();

private:
	threadPoolI	*m_pool;		//线程池指针
	t_int32		m_numOfThread;	//线程池中线程个数
};


#endif
