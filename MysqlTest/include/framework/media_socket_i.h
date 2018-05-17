#ifndef MEDIA_SOCKET_I_H
#define MEDIA_SOCKET_I_H
#include <framework_i.h>
#include <media_packet_i.h>

enum enumMediaPrtl
{
	MEDIA_UNKNOWN = 0,
	MEDIA_RTP,
	MEDIA_PGSP,

};
enum enumMediaSocket
{
	TRANS_UNKNOWN = 0,
	TRANS_TCP_LISTEN,
	TRANS_TCP_CONNECT,
	TRANS_UDP_CONNECT,
	TRANS_UDP_LISTEN,
	TRANS_PEER_STREAM,

};

/** 
*
*	class:		mediaSocketI
* 	@brief:		流媒体传输类的基类；
* 	@author:	zhang_xusheng
*	@date:		2013-5-3
*	@note:		
*/
class mediaSocketI
{

public:
	mediaSocketI() {};
	virtual ~mediaSocketI() {};
public:
	virtual t_int32 open(t_int8 *remoteIp, t_uint16 remotePort, t_int8 * localIp, t_uint16 localPort)
	{
		return E_OK;
	}
	virtual t_int32 open(t_int8 *localIp, t_uint16 localPort)
	{
		return E_OK;
	}
	//connectTo主要用于UDP监听时主动向远端发起连接
	virtual t_int32 connectTo(t_int8* remoteIp, t_uint16 remotePort)
	{
		return E_OK;
	}
	virtual t_int32 close(t_handler peer)
	{
		return E_OK;
	}

	virtual t_int32 close(void)
	{
		return E_OK;
	}
	virtual t_int32 setCallBack(socketCbI *socketCb, void *args)
	{
		return E_OK;
	}
	virtual t_int32 send(t_int8 *buff, t_int32 buffLen)
	{
		return E_OK;
	}
	virtual t_int8* getLocalIp()
	{
		return E_OK;
	}
	virtual t_uint16 getLocalPort()
	{
		return E_OK;
	}
	virtual void* getPeerStream()
	{
		return E_OK;
	}
};

#endif
