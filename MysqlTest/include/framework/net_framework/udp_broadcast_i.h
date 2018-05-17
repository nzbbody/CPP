#ifndef _UDP_BROADCAST_I_H
#define _UDP_BROADCAST_I_H

#include <data_types.h>
#include <net_framework/inet_addr_i.h>
#include <net_framework/socket_stream_i.h>
#include <event_handler_i.h>
#include <event_timer_i.h>
#include <auto_buffer_i.h>
#include <event_notify_i.h>
#include <mutex_i.h>

typedef enum
{
	BROADCAST_CLOSED = 0,
	BROADCAST_CONNECTING,
	BROADCAST_CONNECTED,

}UDPBROADCAST_STATUS;

class DLL_EXPORT udpBroadCastI :public eventHandlerI
{
public:
	udpBroadCastI();
	virtual ~udpBroadCastI();
public:
	/** 
	*
	* 	func name	:		open
	*	@brief		:	    开启udp连接
	*	@param		:		remoteIp: 远程IP地址，remotePort:远程端口
	*	@param		:		localIp:  本地Ip地址，localPort:本地端口
	*	@return		:		E_OK：开启udp连接成功，E_FAIL：开启udp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 open(t_uint16 localPort = 0);
	/** 
	*
	* 	func name	:		close
	*	@brief		:	    关闭udp连接
	*	@return		:		E_OK：关闭udp连接成功，E_FAIL：关闭udp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 close(void);

public:

	t_int32 send(smartAutoBufferI sab);

public:
	/** 
	*
	* 	func name	:		setCallback
	*	@brief		:	    为udp连接设置回调函数
	*	@return		:		E_OK：回调函数设置成功，E_FIAL:回调函数设置失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setCallback(socketCbI *callback, void *arg);


	static t_int32 eventSendNotifyFunc(void *arg);

public:
	virtual iohandle_t getHandle();
	virtual t_int32 setHandle(iohandle_t handle);

	virtual t_int32 handleInput(iohandle_t handle);
	virtual t_int32 handleOutput(iohandle_t handle);
	virtual t_int32 handleInputTimeout(iohandle_t handle);
	virtual t_int32 handleOutputTimeout(iohandle_t handle);
	virtual t_int32 handleException(iohandle_t handle);
private:
	t_int32 openInside();
	t_int32 complete();


private:
	socketStreamI	socketStream;

	socketCbI		*m_connectCb;						//回调函数指针
	void			*m_connectCbArg;					//回调函数参数指针

	sockaddr_t		m_laddr;							//本地地址
	sockaddr_t		m_fromAddr;						//接收数据的地址
	sockaddr_t		m_toAddr;						//发送数据的目的地址

	UDPBROADCAST_STATUS m_status;					//udp广播状态
	t_bool			m_bBind;									//是否绑定标志
	socklen_t		m_remoteLen;

	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;

	eventNotifyI m_eventSendNotify;

};



#endif

