#ifndef TIMER_H_
#define TIMER_H_

typedef void (*TimerTick)(void* param);

struct TimerInfo
{
	TimerTick _TimerTick;
	void*	  _Param;
	int		  _Start;
	int		  _Interval;

	TimerInfo(TimerTick timerTick,void* param,int start,int interval)
	{
		_TimerTick = timerTick;		
		_Param     = param;
		_Start     = start;
		_Interval  = interval;
	}
};

class Timer
{
public:
	Timer(TimerTick timerTick,void* param,int start,int interval);
};

#endif