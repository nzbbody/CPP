/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			os_thread_i.h
* 	@brief	:			
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan add注释头
*/

#ifndef _OS_THREAD_I_H
#define _OS_THREAD_I_H

#include <data_types.h>
#include <datetime_i.h>
#include <memory.h>

#ifdef WIN32


typedef DWORD thread_t;
typedef HANDLE hthread_t;
typedef struct
{
	int type_;
	union
	{
		HANDLE proc_mutex_;
		CRITICAL_SECTION thr_mutex_;
	};
} thread_mutex_t;
typedef HANDLE thread_sema_t;
typedef DWORD thread_key_t;


class thread_cond_t
{
public:
	long waiters (void) const {return this->waiters_;}	/// Returns the number of waiters.

	long waiters_;	/// Number of waiting threads.
	thread_mutex_t waiters_lock_;	/// Serialize access to the waiters count.
	thread_sema_t sema_;	/// Queue up threads waiting for the condition to become signaled.
	HANDLE waiters_done_;
	size_t was_broadcast_;	/// Keeps track of whether we were broadcasting or just signaling.
};

struct thread_condattr_t
{
	int type;
};

#else
typedef pthread_t thread_t;
typedef pthread_t hthread_t;
typedef pthread_mutex_t thread_mutex_t;
typedef pthread_key_t thread_key_t;
typedef pthread_cond_t thread_cond_t;
typedef pthread_condattr_t thread_condattr_t;
#endif



///////////////////////////////////////////////
#define USYNC_THREAD	1
#define USYNC_PROCESS	2

///////////////////////////////////////////////
#define DEFAULT_THREAD_PRIORITY 127
#define DEFAULT_THREAD_STACKSIZE 0

///////////////////////////////////////////////
#define THR_BOUND               0x00000001
#define THR_NEW_LWP             0x00000002
#define THR_DAEMON              0x00000010
#define THR_DETACHED            0x00000040
#define THR_SUSPENDED           0x00000080
#define THR_SCHED_FIFO          0x00020000
#define THR_SCHED_RR            0x00040000
#define THR_SCHED_DEFAULT       0x00080000

#define THR_JOINABLE            0x00010000

#define THR_SCOPE_SYSTEM        0x00100000

#define THR_SCOPE_PROCESS       0x00200000
#define THR_INHERIT_SCHED       0x00400000
#define THR_EXPLICIT_SCHED      0x00800000
#define THR_SCHED_IO            0x01000000
/////////////////////////////////////////////////////

typedef void (*THR_DEST)(void*);
typedef void *(*THR_FUNC)(void *);

#ifdef WIN32 
typedef DWORD THR_FUNC_RETURN;
#else
typedef void * THR_FUNC_RETURN;
#endif

namespace OS_THREAD
{
	//////////////////////////////////////////////////////////////
	/** mutex operation function set */

	/** 
	*
	* 	func name	:	thread_mutex_init
	*	@brief		:	线程互斥锁初始化        
	*	@input		:	thread_mutex_t *m：线程锁指针
	*	@return		:	TRUE / FAIL	
	*	@author		:	     
	*	@note:			
	*
	*/
	int thread_mutex_init(thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_mutex_lock
	*	@brief		:	线程互斥锁        
	*	@input		:	thread_mutex_t *m：线程锁指针    
	*	@return		:	FALSE / TRUE
	*	@author		:	     
	*	@note		:	若资源被其它线程锁定时，阻塞直到unlock		
	*
	*/
	int thread_mutex_lock(thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_mutex_lock
	*	@brief		:	线程互斥锁        
	*	@input		:	thread_mutex_t *m：线程锁指针
	*	@input		:	timeval_t &timeout:超时时间	    
	*	@return		:	FALSE / TRUE
	*	@author		:	     
	*	@note		:	尝试锁定，若资源在timeout时间内仍被锁定则返回FALSE，其它情况返回TRUE		
	*
	*/
	int thread_mutex_lock(thread_mutex_t *m, const timeval_t &timeout);

	/** 
	*
	* 	func name	:	thread_mutex_lock
	*	@brief		:	线程互斥锁        
	*	@input		:	thread_mutex_t *m：线程锁指针
	*	@input		:	timeval_t *timeout:超时时间	    
	*	@return		:	FALSE / TRUE
	*	@author		:	     
	*	@note		:	尝试锁定，若资源在timeout时间内仍被锁定则返回FALSE，其它情况返回TRUE		
	*
	*/
	int thread_mutex_lock(thread_mutex_t *m, const timeval_t *timeout);

	/** 
	*
	* 	func name	:	thread_mutex_trylock
	*	@brief		:	线程互斥锁        
	*	@input		:	thread_mutex_t *m：线程锁指针    
	*	@return		:	FALSE / TRUE
	*	@author		:	     
	*	@note		:	尝试锁定,若发现资源被其它线程锁定时返回FALSE，其它情况返回TRUE	
	*
	*/
	int thread_mutex_trylock(thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_mutex_unlock
	*	@brief		:	线程互斥解锁       
	*	@input		:	thread_mutex_t *m：线程锁指针    
	*	@return		:	E_OK
	*	@author		:	     
	*	@note		:	尝试锁定,若发现资源被其它线程锁定时返回FALSE，其它情况返回TRUE		
	*
	*/
	int thread_mutex_unlock(thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_mutex_destroy
	*	@brief		:	线程互斥锁释放       
	*	@input		:	thread_mutex_t *m：线程锁指针    
	*	@return		:	E_OK
	*	@author		:	     
	*	@note		:	释放锁占用的资源		
	*
	*/
	int thread_mutex_destroy(thread_mutex_t *m);
	

	
	/** private key operation function set */

	/** 
	*
	* 	func name	:	thread_key_create
	*	@brief		:	创建线程键       
	*	@param		:	thread_key_t *key：指向键的指针
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	创建一个类型为thread_key_t的变量，称该变量为键
	*
	*/
	int thread_key_create(thread_key_t *key,THR_DEST func = NULL);

	/** 
	*
	* 	func name	:	thread_key_set
	*	@brief		:	线程存储特殊值      
	*	@param		:	thread_key_t：变量
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	int thread_key_set(thread_key_t, void *data = NULL);

	/** 
	*
	* 	func name	:	thread_key_get
	*	@brief		:	获取线程之前存储的特殊值      
	*	@param		:	thread_key_t：变量
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	void* thread_key_get(thread_key_t);

	/** 
	*
	* 	func name	:	thread_key_free
	*	@brief		:	释放线程键      
	*	@param		:	thread_key_t：变量
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	int thread_key_free(thread_key_t);


	/////////////////////////////////////////////////////////////////
	/** condition operation function set  */
	/** 
	*
	* 	func name	:	thread_cond_init
	*	@brief		:	初始化一个条件变量     
	*	@param		:	thread_cond_t *cond：
	*	@param		:	thread_condattr_t *attr：线程属性
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	设置条件变量是线程间可用还是线程内可用
	*
	*/
	int thread_cond_init(thread_cond_t *cond, thread_condattr_t *attr);

	/** 
	*
	* 	func name	:	thread_cond_signal
	*	@brief		:	唤醒线程   
	*	@param		:	thread_cond_t *cond：
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	发送一个信号给另外一个正处于阻塞状态的线程，使其脱离阻塞状态继续执行
	*
	*/
	int thread_cond_signal(thread_cond_t *cond);

	/** 
	*
	* 	func name	:	thread_cond_wait
	*	@brief		:	条件等待    
	*	@param		:	thread_cond_t *cond：
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	int thread_cond_wait(thread_cond_t *cond, thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_cond_wait
	*	@brief		:	计时等待    
	*	@param		:	thread_cond_t *cond：
	*	@param		:	thread_mutex_t *m:互斥锁
	*	@param		:	timeout:计时时间
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	int thread_cond_timedwait(thread_cond_t *cond, thread_mutex_t *m, timeval_t *timeout);

	/** 
	*
	* 	func name	:	thread_cond_broadcast
	*	@brief		:	激活线程 ，与thread_cond_signal功能一样  
	*	@param		:	thread_cond_t *cond：
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	发送一个信号给另外一个正处于阻塞状态的线程，使其脱离阻塞状态继续执行
	*
	*/
	int thread_cond_broadcast(thread_cond_t *cond);

	/** 
	*
	* 	func name	:	thread_cond_destroy
	*	@brief		:	销毁条件变量  
	*	@param		:	thread_cond_t *cond：
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	int thread_cond_destroy(thread_cond_t *cond);

	int thread_condattr_init(thread_condattr_t *condattr, int type);
	int thread_condattr_destroy(thread_condattr_t *condattr);

	
	/** thread opration function set  */
	/** 
	*
	* 	func name	:	thread_create
	*	@brief		:	线程创建  
	*	@input		:	
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	int thread_create(THR_FUNC func,
			void *arg = 0,
			long flags = THR_NEW_LWP | THR_JOINABLE,
			thread_t *t_id = 0,
			hthread_t *t_handle = 0,
			long priority = DEFAULT_THREAD_PRIORITY,
			void *stack = 0,
			unsigned int stack_size = 0,
			const char** thr_name = 0);

	/** 
	*
	* 	func name	:	thread_join
	*	@brief		:	一个线程等待线程的结束  
	*	@input		:	hthread_t thr_handle：线程ID
	*	@output		:	THR_FUNC_RETURN *status:被等待线程的返回值
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	一个线程等待线程的结束
	*
	*/
	int thread_join(hthread_t thr_handle, THR_FUNC_RETURN *status);

	/** 
	*
	* 	func name	:	thread_join
	*	@brief		:	一个线程等待线程的结束  
	*	@input		:	hthread_t thr_handle：线程ID
	*	@input		:	timeout		超时时间
	*	@output		:	THR_FUNC_RETURN *status:被等待线程的返回值
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	一个线程等待线程的结束
	*
	*/
	int thread_join(hthread_t thr_handle, int timeout, THR_FUNC_RETURN *status);

	/** 
	*
	* 	func name	:	thread_continue
	*	@brief		:	激活线程  
	*	@input		:	hthread_t thr_handle：被激活的线程ID
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	激活线程的运行
	*
	*/
	int thread_continue(hthread_t thr_handle);

	/** 
	*
	* 	func name	:	thread_suspend
	*	@brief		:	挂起线程函数  
	*	@input		:	hthread_t thr_handle：被挂起的线程ID
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	挂起某个线程
	*
	*/
	int thread_suspend(hthread_t thr_handle);

	/** 
	*
	* 	func name	:	thread_getprio
	*	@brief		:	获取线程的优先级别 
	*	@input		:	hthread_t thr_id：线程ID
	*	@output		:	priority:优先级别
	*	@output		:	policy	:线程创建类型
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	获取线程的优先级别
	*
	*/
	int thread_getprio(hthread_t ht_id, int &priority, int &policy);

	/** 
	*
	* 	func name	:	thread_getprio
	*	@brief		:	获取线程的优先级别 
	*	@input		:	hthread_t thr_id：线程ID
	*	@output		:	priority:优先级别
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	获取线程的优先级别
	*
	*/
	int thread_getprio(hthread_t ht_id, int &priority);

	/** 
	*
	* 	func name	:	thread_setprio
	*	@brief		:	设置线程的优先级别 
	*	@input		:	hthread_t thr_id：线程ID
	*	@output		:	priority:优先级别
	*	@output		:	policy	:线程创建类型
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	设置线程的优先级别
	*
	*/
	int thread_setprio (hthread_t ht_id, int priority, int policy);

	/** 
	*
	* 	func name	:	thread_kill
	*	@brief		:	结束进程 
	*	@input		:	hthread_t thr_id：线程ID
	*	@output		:	signum:退出码
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	结束线程，在Windows下thread_kill和thread_cancel等价
	*
	*/
	int thread_kill(hthread_t thr_id, int signum);

	/** 
	*
	* 	func name	:	thread_self
	*	@brief		:	获取当前进程的ID 
	*	@input		:	void
	*	@return		:	线程ID	
	*	@author		:	     
	*	@note		:	获取当前进程的伪句柄
	*
	*/
	int thread_self();

	/** 
	*
	* 	func name	:	thread_self
	*	@brief		:	获取当前进程的伪句柄 
	*	@output		:	self:句柄
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	获取当前进程的伪句柄
	*
	*/
	void thread_self(hthread_t &self);

	/** 
	*
	* 	func name	:	thread_cancel
	*	@brief		:	给线程发送终止命令 
	*	@output		:	hthread_t ht_id：线程ID
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	发送终止命令给线程，Window下等价于thread_kill；
	*					在Windows下使用thread_cancel时，相关线程应当避免使用new和delete
	*/
	int thread_cancel(hthread_t ht_id);

	/** 
	*
	* 	func name	:	thread_yield
	*	@brief		:	运行进线让出执行权 
	*	@output		:	
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	正在运行的进线让出执行权给比它优先级高或等于它的进程运行
	*
	*/
	void thread_yield();
}

#endif

