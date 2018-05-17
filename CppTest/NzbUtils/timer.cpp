#include "timer.h"
#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#endif

void NiuSleep(int ms)
{
	#ifdef WIN32
		::Sleep(ms);
	#else
		::usleep(ms*1000);
	#endif
}


#ifdef WIN32
DWORD WINAPI ThreadRun(PVOID param)
#else
void* ThreadRun(void* param)
#endif
{
	TimerInfo* timerInfo = (TimerInfo*)param;
	NiuSleep(timerInfo->_Start);

	while(true)
	{
		timerInfo->_TimerTick(timerInfo->_Param);
		NiuSleep(timerInfo->_Interval);
	}
	
	return 0;
}

Timer::Timer(TimerTick timerTick,void* param,int start,int interval)
{
	TimerInfo* timerInfo = new TimerInfo(timerTick,param,start,interval);

	#ifdef WIN32
	HANDLE hThread = CreateThread(NULL,0,ThreadRun,timerInfo,0,NULL);
	CloseHandle(hThread);
	#else
	pthread_t hThread;
	pthread_create(&hThread,NULL,ThreadRun,(void*)timerInfo);
	#endif
}