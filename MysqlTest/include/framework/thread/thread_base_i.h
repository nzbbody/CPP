#ifndef _THREAD_BASE_I_H
#define _THREAD_BASE_I_H
#include <data_types.h>
#include <thread/thread_i.h>

#define THREAD_MAX	3

typedef void *(*threadBaseProxy)(void*);


class DLL_EXPORT threadBaseI
{
public:
	threadBaseI();
	virtual ~threadBaseI();
public:
	virtual t_int32 threadProcA();
	virtual t_int32 threadProcB();
	virtual t_int32 threadProcC();
	t_int32 start(t_int32 threadNum = 1);
	t_int32 stop();
private:
	hthread_t m_handle[THREAD_MAX];
	threadBaseProxy m_function[THREAD_MAX];
};

#endif
