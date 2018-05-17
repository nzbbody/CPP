/*
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

#ifndef _THREAD_IMPL_H
#define _THREAD_IMPL_H

#include <thread_i.h>

#include <pthread.h>
#include <string.h>

#define MAX_POOL_THREADS 200

typedef void (*dispatch_fn)(void *);

//线程的结构体
typedef struct _thread_st 
{
	pthread_t id;             
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	dispatch_fn fn;
	void *arg;
	void *parent;
} _thread;


//线程池的结构体
typedef struct _threadpool_st 
{
	pthread_mutex_t tp_mutex;
	pthread_cond_t tp_idle;//线程池中有线程在休息
	pthread_cond_t tp_full;//线程池中有线程在休息
	pthread_cond_t tp_empty;
	_thread ** tp_list;
	int tp_index;//保存了一个空闲的线程就++，占用了一个空闲的线程就--，所以这个概念是开辟了的，但未被使用的线程数
	int tp_max_index;//允许的最大线程数
	int tp_stop;//线程池要不要停止
	int tp_total;//每保存一个线程就+1，
} _threadpool;

#endif
