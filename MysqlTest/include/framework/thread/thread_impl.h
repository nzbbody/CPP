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

//�̵߳Ľṹ��
typedef struct _thread_st 
{
	pthread_t id;             
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	dispatch_fn fn;
	void *arg;
	void *parent;
} _thread;


//�̳߳صĽṹ��
typedef struct _threadpool_st 
{
	pthread_mutex_t tp_mutex;
	pthread_cond_t tp_idle;//�̳߳������߳�����Ϣ
	pthread_cond_t tp_full;//�̳߳������߳�����Ϣ
	pthread_cond_t tp_empty;
	_thread ** tp_list;
	int tp_index;//������һ�����е��߳̾�++��ռ����һ�����е��߳̾�--��������������ǿ����˵ģ���δ��ʹ�õ��߳���
	int tp_max_index;//���������߳���
	int tp_stop;//�̳߳�Ҫ��Ҫֹͣ
	int tp_total;//ÿ����һ���߳̾�+1��
} _threadpool;

#endif
