



#ifndef _EVENT_TIMER_I_H
#define _EVENT_TIMER_I_H


#include <event_i.h>


/**
	定时器类型
*/
typedef enum
{
	event_timer_once,
	event_timer_always,
}event_timer_type;

typedef t_int32 eventTimerCallback(void *);

class DLL_EXPORT timerHandlerI
{

public:
	timerHandlerI();
	virtual ~timerHandlerI();
public:
	static void timerHandlerCallback(iohandle_t handle,
		t_int16 eventFlag,
		void *arg);

public:
	virtual t_int32 handleTimeout(iohandle_t handle);

public:
	t_int32 registerTimeout(t_int32 timeoutMs, t_bool always = TRUE);
	t_int32 removeTimeout();


private:
	event_t _eventTimeout;

	t_bool	m_registerFlag;
	
};
//template<class _Arg, class _Result>
//struct timerFunc
//{
//	typedef _Arg	stdFuncType;
//	typedef	_Result	clientFuncType;
//};
//
//template<typename _Result, typename _Ty>
//class mem_fun_t2 : public timerFunc<_Ty*, _Result>
//{
//	typedef _Result(_Ty::*_Pmemfun)();
//public:
//	explicit mem_fun_t2(_Pmemfun& pfunc)
//	{
//		m_func.m_pfun = pfunc;
//	}
//	eventTimerCallback* operator()() const
//	{
//		return m_func.m_callback;
//	}
//
//private:
//
//	union func_ptr
//	{
//		_Pmemfun m_pfun;
//		eventTimerCallback *m_callback;
//	}m_func;
//};
//
//template<class _Result, class _Ty>
//mem_fun_t2<_Result, _Ty> mem_fun2(_Result (_Ty::*_Pm)())
//{
//	return (mem_fun_t2<_Result, _Ty>(_Pm));
//}

class DLL_EXPORT eventTimerI : public timerHandlerI
{
public:
	eventTimerI();
	virtual ~eventTimerI();

public:
	t_int32 connect(eventTimerCallback *cb, 
					t_int32 timeoutMs,
					void *arg,
					event_timer_type timerType = event_timer_always);

	//template<class _Result, class _Ty>
	//t_int32 mem_fun2(_Result (_Ty::*_Pm)(), t_int32 timeoutMs, void*arg, event_timer_type timerType = event_timer_always)
	//{
	//	_timeoutMs = timeoutMs;
	//	_timerArg = arg;
	//	_timerType = timerType;
	//	_timerCb = mem_fun_t2<_Result, _Ty>(_Pm)();
	//	return E_OK;
	//}

public:

	t_int32 start();
	t_int32 stop();

public:
	virtual t_int32 handleTimeout(iohandle_t handle);
	
private:
	eventTimerCallback *_timerCb;		//定时器的回调函数指针
	event_timer_type _timerType;		//定时器的类型
	void *_timerArg;					//定时器回调函数的参数
	t_int32 _timeoutMs;					//定时器的时间片
	//mem_fun_t2 _timerCb;

};
#endif

