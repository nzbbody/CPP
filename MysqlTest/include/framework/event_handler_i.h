


#ifndef _EVENT_HANDLER_I_H
#define _EVENT_HANDLER_I_H

#include <data_types.h>
#include <event_i.h>


class DLL_EXPORT eventHandlerI
{
public:
	eventHandlerI();
	virtual ~eventHandlerI();

public:
	static void eventInputCallback(iohandle_t handle, 
		t_int16 eventFlag, 
		void *arg);

	static void eventOutputCallback(iohandle_t handle,
		t_int16 eventFlag,
		void *arg);

public:
	virtual iohandle_t getHandle();
	virtual t_int32 setHandle(iohandle_t handle);


	virtual t_int32 handleInput(iohandle_t handle);
	virtual t_int32 handleOutput(iohandle_t handle);
	virtual t_int32 handleInputTimeout(iohandle_t handle);
	virtual t_int32 handleOutputTimeout(iohandle_t handle);
	virtual t_int32 handleException(iohandle_t handle);


public:
	t_int32 registerInput(t_int32 timeoutMs);
	t_int32 removeInput();

	t_int32 registerOutput(t_int32 timeoutMs);
	t_int32 removeOutput();


private:
	event_t eventInput;
	event_t eventOutput;

	t_bool bInput;
	t_bool bOutput;
};



#endif

