


#ifndef _REACTOR_I_H
#define _REACTOR_I_H

#include <data_types.h>
#include <singleton_i.h>
#include <event_handler_i.h>

class reactorI
{

public:
	t_int32 eventLoopStart();
	t_int32 eventLoopStop();

public:
	/** 
	*
	* 	func name	:	registerInput
	*	@brief		:	
	*	@param		:	
	*	@return		:  
	*	@author		:   
	*   @date		:    
	*	@note:			
	*
	*/
	t_int32 registerInput(eventHandlerI *eventHandler, t_int32 timeoutMs);
	t_int32 removeInput(eventHandlerI *eventHandler);

	t_int32 registerOutput(eventHandlerI *eventHandler, t_int32 timeoutMs);
	t_int32 removeOutput(eventHandlerI *eventHandler);

	
	
};

t_int32 DLL_EXPORT reactorInit();
t_int32 DLL_EXPORT reactorExit();
t_int32 DLL_EXPORT reactorStart();
t_int32 DLL_EXPORT reactorStop();
t_int32 DLL_EXPORT reactorInputAdd(eventHandlerI *eventHandler, t_int32 timeoutMs);
t_int32 DLL_EXPORT reactorInputDel(eventHandlerI *eventHandler);
t_int32 DLL_EXPORT reactorOutputAdd(eventHandlerI *eventHandler, t_int32 timeoutMs);
t_int32 DLL_EXPORT reactorOutputDel(eventHandlerI *eventHandler);

typedef singletonI<reactorI> reactorISingleton;

#endif

