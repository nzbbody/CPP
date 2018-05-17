#ifndef _UDP_LISTEN_I_H
#define _UDP_LISTEN_I_H



#include <data_types.h>
#include <list_i.h>
#include <event_handler_i.h>
//#include <net_framework/socket_acceptor_i.h>
#include <net_framework/peer_stream_i.h>
#include <net_framework/socket_i.h>



class DLL_EXPORT udpListenCbI
{
public:
	virtual t_int32 onAccept(t_handler handlerId, void *arg) = 0;
	virtual t_int32 onClose(t_handler handlerId, void *arg) = 0;
	virtual t_int32 onDisconnect(t_handler handlerId, void *arg) = 0;
};
/** 
 *
 *	class:		udpListenI
 * 	@brief:		udpListenI实现tcp监听功能
 * 	@author:	zhang_xusheng
 *	@date:		2013-3-15
 *	@note:	
 */
class DLL_EXPORT udpListenI : public eventHandlerI
{
public:
	udpListenI();
	virtual ~udpListenI();

public:
	t_int32 open(t_int8 *ip,
		t_uint16 port,
		t_int32 reuse = 1, 
		t_int32 family = AF_INET, 
		t_int32 backlog = 5, 
		t_int32 proto = 0);
	t_int32 close();
	t_int32 resume();
	t_int32 suspend();

public:
	t_int32 setCallback(socketCbI *callback, void *arg);
	
public:
	virtual iohandle_t getHandle();
	virtual t_int32 setHandle(iohandle_t handle);


	virtual t_int32 handleInput(iohandle_t handle);
	virtual t_int32 handleOutput(iohandle_t handle);
	virtual t_int32 handleInputTimeout(iohandle_t handle);
	virtual t_int32 handleOutputTimeout(iohandle_t handle);
	virtual t_int32 handleException(iohandle_t handle);


private:
	
	socketStreamI peeraccept;

	sockaddr_t listenAddr;

	socketCbI *listenCb;
	void *listenCbArg;

	
	
};



#endif

