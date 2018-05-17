#ifndef _UDP_CONNECT_I_H
#define _UDP_CONNECT_I_H

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
	UDP_CLOSED = 0,
	UDP_CONNECTING,
	UDP_CONNECTED,

}UDP_STATUS;

typedef enum
{
	UDP_SEND_NORMAL,	//直接发送方式
	UDP_SEND_DEFAULT,	//默认的智能指针发送方式
	UDP_SEND_CALLBACK,	//回调给上层，上层发送；注意如果采用该发送方式，默认的智能指针发送方式无效

}UDP_SEND_TYPE;

class DLL_EXPORT udpConnectI :public eventHandlerI
{
public:
	udpConnectI();
	virtual ~udpConnectI();
public:
	/** 
	*
	* 	func name	:		open
	*	@brief		:	    开启udp连接
	*	@param		:		remoteIp: 远程IP地址，remotePort:远程端口
	*	@param		:		localIp:  本地Ip地址，localPort:本地端口
	*	@return		:		E_OK：开启udp连接成功，E_FAIL：开启udp连接失败
	*	@author		:	    zhangxusheng
	*	@note		:		udp有三种打开方式：
	*						A：绑定连接方式--->指定远程IP、端口和本地IP、端口
	*						B: 不绑定连接方式--->指定远程IP、端口和本地端口，本地IP为NULL或为空字符串，连接会用指定的本地端口去发送数据
	*						C：不绑定连接方式--->指定远程IP、端口，连接会随即选择端口去发送
	*/
	t_int32 open(t_int8 *remoteIp, t_uint16 remotePort, 
		t_int8 *localIp = NULL, t_uint16 localPort = 0);
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
	/** 
	*
	* 	func name	:		send
	*	@brief		:	    udp连接发送数据
	*	@return		:		
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 send(t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int32 &sended);


	t_int32 send(smartAutoBufferI sab);

	/** 
	*
	* 	func name	:		getLocalIp
	*	@brief		:	    获取本地Ip地址
	*	@return		:		本地Ip地址字符串
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getLocalIp();
	/** 
	*
	* 	func name	:		getLocalPort
	*	@brief		:	    获取本地端口
	*	@return		:		本地端口
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getLocalPort();
	/** 
	*
	* 	func name	:		getRemoteIp
	*	@brief		:	    获取远程Ip地址
	*	@return		:		远程Ip地址字符串
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getRemoteIp();
	/** 
	*
	* 	func name	:		getRemotePort
	*	@brief		:		获取远程端口
	*	@return		:		远程端口号
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getRemotePort();

public:
	//使能TCP的可写回调
	t_int32 enableOutput();

	//关闭TCP的可写回调
	t_int32 disableOutput();

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
	
	UDP_SEND_TYPE	m_sendType;						//TCP发送方式：直接发送，默认智能指针发送，上层控制发送
	sockaddr_t		m_laddr;							//本地地址
	sockaddr_t		m_raddr;							//远程地址

	t_int8			m_localIp[sizeof("255.255.255.255")];		
	t_uint16		m_localPort;
	t_int8			m_remoteIp[sizeof("255.255.255.255")];
	t_uint16		m_remotePort;

	UDP_STATUS		m_status;
	t_bool			m_bBind;									//是否绑定标志
	t_bool			m_connectFlag;								//是否连接标志
	socklen_t		m_remoteLen;

	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;

	eventNotifyI	m_eventSendNotify;

};



#endif


