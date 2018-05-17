


#ifndef _EVENT_NOTIFY_I_H
#define _EVENT_NOTIFY_I_H

#include <data_types.h>

#include <event_handler_i.h>

#include <io_data/io_data_i.h>

enum{
	NOTIFY_ADD = 1,
	NOTIFY_DEL = 2,

};

typedef t_int32 (*notify_callback)(void *arg);



class DLL_EXPORT notifyI : public ioDataI
{
public:
	notifyI();
	~notifyI();

public:
	t_int32 open();
	t_int32 close();
	t_int32 notify();
	t_int32 ack();
public:
	iohandle_t readHandle();
	iohandle_t writeHandle();
private:
	iohandle_t rdHandle;
	iohandle_t wrHandle;
	iohandle_t listenHandle;
};

class DLL_EXPORT eventNotifyI : public eventHandlerI
{
public:
	eventNotifyI();
	virtual ~eventNotifyI();

public:
	t_int32 open();
	t_int32 close();
	t_int32 resume();
	t_int32 suspend();
	t_int32 notify();

	/** eventNotifyI类的onEvent函数
	*
	* 	func name:	onEvent
	*	@brief:		回调类       
	*	@param:		void
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:		尽量避免使用该接口，从2014-3-18起废弃该接口，事件通知一律通过回调的方式返回给上层。如果使用该接口，一定不要将子类释放掉
	*
	*/
	virtual t_int32 onEvent();

public:
	virtual iohandle_t getHandle();
	virtual t_int32 setHandle(iohandle_t handle);


	virtual t_int32 handleInput(iohandle_t handle);
	virtual t_int32 handleOutput(iohandle_t handle);
	virtual t_int32 handleInputTimeout(iohandle_t handle);
	virtual t_int32 handleOutputTimeout(iohandle_t handle);
	virtual t_int32 handleException(iohandle_t handle);
public:
	t_int32 getNotifyHandler(iohandle_t handle[2]);
public:
	t_int32 setCallback(notify_callback cb, void *arg);
	
public:
	notify_callback notifyCb;
	void *notifyArg;
private:
	notifyI notifyer;
};





#endif


