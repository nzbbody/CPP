/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			thread.h
* 	@brief	:			
* 	@author	:         
*	@note	:		  线程池函数（引用第三方库）
*	@modify	:         hehairan add注释头
*/

#ifndef _THREAD_I_H
#define _THREAD_I_H


#include <thread/os_thread_i.h>

class DLL_EXPORT threadI
{
public:
	static int spawn (THR_FUNC func,
			void *arg = 0,
			long flags = THR_NEW_LWP | THR_JOINABLE,
			thread_t *t_id = 0,
			hthread_t *t_handle = 0,
			long priority = DEFAULT_THREAD_PRIORITY,
			void *stack = 0,
			unsigned int stack_size = 0,
			const char** thr_name = 0);

	static int spawn_n (unsigned int n,
			THR_FUNC func,
			void *arg = 0,
			long flags = THR_NEW_LWP | THR_JOINABLE,
			long priority = DEFAULT_THREAD_PRIORITY,
			void *stack[] = 0,
			unsigned int stack_size[] = 0,
			const char* thr_name[] = 0);

	static int spawn_n (thread_t thread_ids[],
			unsigned int n,
			THR_FUNC func,
			void *arg,
			long flags,
			long priority = DEFAULT_THREAD_PRIORITY,
			void *stack[] = 0,
			unsigned int stack_size[] = 0,
			hthread_t thread_handles[] = 0,
			const char* thr_name[] = 0);

	static int join (hthread_t,
			THR_FUNC_RETURN * = 0);

	static int join(hthread_t, int timeout, THR_FUNC_RETURN * = 0);

	static int resume (hthread_t);

	static int suspend (hthread_t);

	static int getprio (hthread_t ht_id, int &priority);

	static int getprio (hthread_t ht_id, int &priority, int &policy);

	static int setprio (hthread_t ht_id, int priority, int policy = -1);

	static int kill (hthread_t, int signum);

	static void yield (void);

	static void self (hthread_t &t_handle);

	static thread_t self (void);

	static void exit (THR_FUNC_RETURN status = 0);

	static int getconcurrency (void);

	static int setconcurrency (int new_level);
#if 0
	static int sigsetmask (int how,
			const sigset_t *sigset,
			sigset_t *osigset = 0);
#endif

	static int keycreate (thread_key_t *keyp, THR_DEST destructor);

	static int keyfree (thread_key_t key);

	static int setspecific (thread_key_t key, void *value);

	static int getspecific (thread_key_t key, void **valuep);

	static int disablecancel (struct cancel_state *old_state);

	static int enablecancel (struct cancel_state *old_state, int flag);

	static int setcancelstate (struct cancel_state &new_state, struct cancel_state *old_state);

	static int cancel (hthread_t t_id);

	static void testcancel (void);

protected:
	threadI (void);
};








#endif

