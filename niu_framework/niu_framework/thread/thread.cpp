#include "thread.h"

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#endif

namespace niu
{
	Thread::Thread(ThreadCallback callBack,void* param)
	{
#ifdef WIN32
		HANDLE hThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)callBack,param,0,NULL);
		CloseHandle(hThread);
#else
		pthread_t hThread;
		pthread_create(&hThread,NULL,callBack,param);
#endif
	}
}



