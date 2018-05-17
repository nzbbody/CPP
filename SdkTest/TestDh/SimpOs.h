#ifndef SIMPOS_H_
#define SIMPOS_H_

#ifdef WIN32
#include <windows.h>
#include <process.h>
#else
#include <unistd.h>
#include <pthread.h>
#endif

#ifdef WIN32

#define MUTEX(mt)\
	CRITICAL_SECTION mt;

#define MUTEX_INIT(mt)\
	CRITICAL_SECTION mt;\
	InitializeCriticalSection(&mt);

#define INITMU(mt)\
	InitializeCriticalSection(&mt);

#define  LOCK(p)\
	EnterCriticalSection(&p);

#define UNLOCK(p)\
	LeaveCriticalSection(&p);

#define SLEEP(m)\
	Sleep(m);

typedef unsigned (__stdcall * BeginThreadExStartAddress) (void *);

#define CREATTHD(handle, fun, thdid, arge)\
	handle = (unsigned int *)::_beginthreadex(NULL,0,(BeginThreadExStartAddress)fun,	arge,	0,	&thdid);

#else //WIN32  linux

#define MUTEX(mt)\
	pthread_mutex_t mt;

#define INITMU(mt)

#define MUTEX_INIT(mt)\
	pthread_mutex_t mt;

#define  LOCK(p)\
	pthread_mutex_lock(&p);

#define UNLOCK(p)\
	pthread_mutex_unlock(&p);

#define SLEEP(m)\
	::usleep(m*1000);

#define CREATTHD(handle, fun, thdid)\
	pthread_create((pthread_t*)&thdid, NULL, fun, NULL);\
	::pthread_attr_destroy (&attr);\
	handle = &thdid;

#endif //linux

#endif   //SIMPOS_H_


//unsigned int* threadHandle;
//unsigned int threadId;
//
//CREATTHD(threadHandle, sendData, threadId);