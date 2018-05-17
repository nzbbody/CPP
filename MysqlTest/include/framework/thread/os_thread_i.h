/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			os_thread_i.h
* 	@brief	:			
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan addע��ͷ
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
	*	@brief		:	�̻߳�������ʼ��        
	*	@input		:	thread_mutex_t *m���߳���ָ��
	*	@return		:	TRUE / FAIL	
	*	@author		:	     
	*	@note:			
	*
	*/
	int thread_mutex_init(thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_mutex_lock
	*	@brief		:	�̻߳�����        
	*	@input		:	thread_mutex_t *m���߳���ָ��    
	*	@return		:	FALSE / TRUE
	*	@author		:	     
	*	@note		:	����Դ�������߳�����ʱ������ֱ��unlock		
	*
	*/
	int thread_mutex_lock(thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_mutex_lock
	*	@brief		:	�̻߳�����        
	*	@input		:	thread_mutex_t *m���߳���ָ��
	*	@input		:	timeval_t &timeout:��ʱʱ��	    
	*	@return		:	FALSE / TRUE
	*	@author		:	     
	*	@note		:	��������������Դ��timeoutʱ�����Ա������򷵻�FALSE�������������TRUE		
	*
	*/
	int thread_mutex_lock(thread_mutex_t *m, const timeval_t &timeout);

	/** 
	*
	* 	func name	:	thread_mutex_lock
	*	@brief		:	�̻߳�����        
	*	@input		:	thread_mutex_t *m���߳���ָ��
	*	@input		:	timeval_t *timeout:��ʱʱ��	    
	*	@return		:	FALSE / TRUE
	*	@author		:	     
	*	@note		:	��������������Դ��timeoutʱ�����Ա������򷵻�FALSE�������������TRUE		
	*
	*/
	int thread_mutex_lock(thread_mutex_t *m, const timeval_t *timeout);

	/** 
	*
	* 	func name	:	thread_mutex_trylock
	*	@brief		:	�̻߳�����        
	*	@input		:	thread_mutex_t *m���߳���ָ��    
	*	@return		:	FALSE / TRUE
	*	@author		:	     
	*	@note		:	��������,��������Դ�������߳�����ʱ����FALSE�������������TRUE	
	*
	*/
	int thread_mutex_trylock(thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_mutex_unlock
	*	@brief		:	�̻߳������       
	*	@input		:	thread_mutex_t *m���߳���ָ��    
	*	@return		:	E_OK
	*	@author		:	     
	*	@note		:	��������,��������Դ�������߳�����ʱ����FALSE�������������TRUE		
	*
	*/
	int thread_mutex_unlock(thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_mutex_destroy
	*	@brief		:	�̻߳������ͷ�       
	*	@input		:	thread_mutex_t *m���߳���ָ��    
	*	@return		:	E_OK
	*	@author		:	     
	*	@note		:	�ͷ���ռ�õ���Դ		
	*
	*/
	int thread_mutex_destroy(thread_mutex_t *m);
	

	
	/** private key operation function set */

	/** 
	*
	* 	func name	:	thread_key_create
	*	@brief		:	�����̼߳�       
	*	@param		:	thread_key_t *key��ָ�����ָ��
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	����һ������Ϊthread_key_t�ı������Ƹñ���Ϊ��
	*
	*/
	int thread_key_create(thread_key_t *key,THR_DEST func = NULL);

	/** 
	*
	* 	func name	:	thread_key_set
	*	@brief		:	�̴߳洢����ֵ      
	*	@param		:	thread_key_t������
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	int thread_key_set(thread_key_t, void *data = NULL);

	/** 
	*
	* 	func name	:	thread_key_get
	*	@brief		:	��ȡ�߳�֮ǰ�洢������ֵ      
	*	@param		:	thread_key_t������
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	void* thread_key_get(thread_key_t);

	/** 
	*
	* 	func name	:	thread_key_free
	*	@brief		:	�ͷ��̼߳�      
	*	@param		:	thread_key_t������
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
	*	@brief		:	��ʼ��һ����������     
	*	@param		:	thread_cond_t *cond��
	*	@param		:	thread_condattr_t *attr���߳�����
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	���������������̼߳���û����߳��ڿ���
	*
	*/
	int thread_cond_init(thread_cond_t *cond, thread_condattr_t *attr);

	/** 
	*
	* 	func name	:	thread_cond_signal
	*	@brief		:	�����߳�   
	*	@param		:	thread_cond_t *cond��
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	����һ���źŸ�����һ������������״̬���̣߳�ʹ����������״̬����ִ��
	*
	*/
	int thread_cond_signal(thread_cond_t *cond);

	/** 
	*
	* 	func name	:	thread_cond_wait
	*	@brief		:	�����ȴ�    
	*	@param		:	thread_cond_t *cond��
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	int thread_cond_wait(thread_cond_t *cond, thread_mutex_t *m);

	/** 
	*
	* 	func name	:	thread_cond_wait
	*	@brief		:	��ʱ�ȴ�    
	*	@param		:	thread_cond_t *cond��
	*	@param		:	thread_mutex_t *m:������
	*	@param		:	timeout:��ʱʱ��
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	
	*
	*/
	int thread_cond_timedwait(thread_cond_t *cond, thread_mutex_t *m, timeval_t *timeout);

	/** 
	*
	* 	func name	:	thread_cond_broadcast
	*	@brief		:	�����߳� ����thread_cond_signal����һ��  
	*	@param		:	thread_cond_t *cond��
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	����һ���źŸ�����һ������������״̬���̣߳�ʹ����������״̬����ִ��
	*
	*/
	int thread_cond_broadcast(thread_cond_t *cond);

	/** 
	*
	* 	func name	:	thread_cond_destroy
	*	@brief		:	������������  
	*	@param		:	thread_cond_t *cond��
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
	*	@brief		:	�̴߳���  
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
	*	@brief		:	һ���̵߳ȴ��̵߳Ľ���  
	*	@input		:	hthread_t thr_handle���߳�ID
	*	@output		:	THR_FUNC_RETURN *status:���ȴ��̵߳ķ���ֵ
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	һ���̵߳ȴ��̵߳Ľ���
	*
	*/
	int thread_join(hthread_t thr_handle, THR_FUNC_RETURN *status);

	/** 
	*
	* 	func name	:	thread_join
	*	@brief		:	һ���̵߳ȴ��̵߳Ľ���  
	*	@input		:	hthread_t thr_handle���߳�ID
	*	@input		:	timeout		��ʱʱ��
	*	@output		:	THR_FUNC_RETURN *status:���ȴ��̵߳ķ���ֵ
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	һ���̵߳ȴ��̵߳Ľ���
	*
	*/
	int thread_join(hthread_t thr_handle, int timeout, THR_FUNC_RETURN *status);

	/** 
	*
	* 	func name	:	thread_continue
	*	@brief		:	�����߳�  
	*	@input		:	hthread_t thr_handle����������߳�ID
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	�����̵߳�����
	*
	*/
	int thread_continue(hthread_t thr_handle);

	/** 
	*
	* 	func name	:	thread_suspend
	*	@brief		:	�����̺߳���  
	*	@input		:	hthread_t thr_handle����������߳�ID
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	����ĳ���߳�
	*
	*/
	int thread_suspend(hthread_t thr_handle);

	/** 
	*
	* 	func name	:	thread_getprio
	*	@brief		:	��ȡ�̵߳����ȼ��� 
	*	@input		:	hthread_t thr_id���߳�ID
	*	@output		:	priority:���ȼ���
	*	@output		:	policy	:�̴߳�������
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	��ȡ�̵߳����ȼ���
	*
	*/
	int thread_getprio(hthread_t ht_id, int &priority, int &policy);

	/** 
	*
	* 	func name	:	thread_getprio
	*	@brief		:	��ȡ�̵߳����ȼ��� 
	*	@input		:	hthread_t thr_id���߳�ID
	*	@output		:	priority:���ȼ���
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	��ȡ�̵߳����ȼ���
	*
	*/
	int thread_getprio(hthread_t ht_id, int &priority);

	/** 
	*
	* 	func name	:	thread_setprio
	*	@brief		:	�����̵߳����ȼ��� 
	*	@input		:	hthread_t thr_id���߳�ID
	*	@output		:	priority:���ȼ���
	*	@output		:	policy	:�̴߳�������
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	�����̵߳����ȼ���
	*
	*/
	int thread_setprio (hthread_t ht_id, int priority, int policy);

	/** 
	*
	* 	func name	:	thread_kill
	*	@brief		:	�������� 
	*	@input		:	hthread_t thr_id���߳�ID
	*	@output		:	signum:�˳���
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	�����̣߳���Windows��thread_kill��thread_cancel�ȼ�
	*
	*/
	int thread_kill(hthread_t thr_id, int signum);

	/** 
	*
	* 	func name	:	thread_self
	*	@brief		:	��ȡ��ǰ���̵�ID 
	*	@input		:	void
	*	@return		:	�߳�ID	
	*	@author		:	     
	*	@note		:	��ȡ��ǰ���̵�α���
	*
	*/
	int thread_self();

	/** 
	*
	* 	func name	:	thread_self
	*	@brief		:	��ȡ��ǰ���̵�α��� 
	*	@output		:	self:���
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	��ȡ��ǰ���̵�α���
	*
	*/
	void thread_self(hthread_t &self);

	/** 
	*
	* 	func name	:	thread_cancel
	*	@brief		:	���̷߳�����ֹ���� 
	*	@output		:	hthread_t ht_id���߳�ID
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	������ֹ������̣߳�Window�µȼ���thread_kill��
	*					��Windows��ʹ��thread_cancelʱ������߳�Ӧ������ʹ��new��delete
	*/
	int thread_cancel(hthread_t ht_id);

	/** 
	*
	* 	func name	:	thread_yield
	*	@brief		:	���н����ó�ִ��Ȩ 
	*	@output		:	
	*	@return		:	TRUE /FAIL	
	*	@author		:	     
	*	@note		:	�������еĽ����ó�ִ��Ȩ���������ȼ��߻�������Ľ�������
	*
	*/
	void thread_yield();
}

#endif

