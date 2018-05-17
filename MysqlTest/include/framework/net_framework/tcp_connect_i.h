/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:			tcp_connect_i.h
 * 	@brief:			tcp_connect_i.h定义了tcp连接类
 * 	@author:			zhang_sunbo 
 *	@note:	
 */


#ifndef _TCP_CONNECT_I_H
#define _TCP_CONNECT_I_H


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
	TCP_CLOSED = 0,
	TCP_CONNECTING,
	TCP_CONNECTED,
	TCP_DISCONNECT,

}TCP_CONNECT_STATUS;


typedef enum
{
	TCP_SEND_NORMAL,	//直接发送方式
	TCP_SEND_DEFAULT,	//默认的智能指针发送方式
	TCP_SEND_CALLBACK,	//回调给上层，上层发送；注意如果采用该发送方式，默认的智能指针发送方式无效

}TCP_SEND_TYPE;
/** 
*
*	class:		tcpConnectCbI
* 	@brief:		tcpConnectCbI实现tcp连接的回调功能	
* 	@author:	zhang_sunbo
*	@date:		2012-12-26
*	@note:	
*/
class DLL_EXPORT tcpConnectCbI
{
public:
	virtual ~tcpConnectCbI() {}
public:

	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg) = 0;
	virtual t_int32 onClose(t_handler handlerId, void *arg) = 0;
	virtual t_int32 onDisconnect(t_handler handlerId, void *arg) = 0;


	virtual t_int32 onInputTimeout(t_handler handlerId, void *arg) = 0;
	virtual t_int32 onOutputTimeout(t_handler handlerId, void *arg) = 0;
	virtual t_int32 onExpection(t_handler handlerId, void *arg) = 0;
};


/** 
 *
 *	class:		tcpConnectI
 * 	@brief:		tcpConnectI实现tcp连接功能	
 * 	@author:	zhang_sunbo
 *	@date:		2012-12-26
 *	@note:	
 */
class DLL_EXPORT tcpConnectI : public eventHandlerI
{
public:
	tcpConnectI();
	virtual ~tcpConnectI();

public:
	/** 
	*
	* 	func name	:		open
	*	@brief		:	    打开tcp连接
	*	@param		：		remoteIp：远程Ip,remotePort：远程Port，localIp：本地Ip，localPort：本地端口
	*	@return		:		E_OK：打开tcp连接成功，E_FAIL:打开tcp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 open(t_int8 *remoteIp, t_uint16 remotePort, 
		t_int8 *localIp = NULL, t_uint16 localPort = 0);

	/** 
	*
	* 	func name	:		close
	*	@brief		:	    关闭tcp连接
	*	@return		:		E_OK：关闭tcp连接成功，E_FAIL:关闭tcp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 close();

	/** 
	*
	* 	func name	:		resume
	*	@brief		:	    恢复tcp连接
	*	@return		:		E_OK：恢复tcp连接成功，E_FAIL:恢复tcp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 resume();

	/** 
	*
	* 	func name	:		suspend
	*	@brief		:	    挂起tcp连接
	*	@return		:		E_OK：挂起tcp连接成功，E_FAIL:挂起tcp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 suspend();
	
	/** 
	*
	* 	func name	:		send
	*	@brief		:	    发送数据
	*	@param		：		buff：待发送数据指针，buffLen：待发送数据长度，flags：发送标志，sended：接收已发送的数据长度
	*	@return		:		
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 send(t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int32 &sended);

	t_int32 send(smartAutoBufferI sab);
public:
	/** 
	*
	* 	func name	:		reconnect
	*	@brief		:	    重连tcp连接
	*	@return		:		E_OK：重连tcp连接成功，E_FAIL:重连tcp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	static t_int32 reconnect(void *arg);
public:
	/** 
	*
	* 	func name	:		setCallback
	*	@brief		:	    为tcp连接设置回调函数
	*	@param		：		callback：回调函数指针，arg：回调函数参数指针
	*	@return		:		E_OK：设置回调函数成功，E_FAIL:设置回调函数失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setCallback(socketCbI *callback, void *arg);

	static t_int32 eventSendNotifyFunc(void *arg);

	/** 
	*
	* 	func name	:		complete
	*	@brief		:	    完成tcp连接
	*	@return		:		E_OK：打开tcp连接成功，E_FAIL:打开tcp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 complete();

	/** 
	*
	* 	func name	:		getLocalIp
	*	@brief		:	    获取本地Ip
	*	@return		:		E_OK：获取本地Ip成功，E_FAIL:获取本地Ip失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getLocalIp();

	/** 
	*
	* 	func name	:		getLocalPort
	*	@brief		:	    获取本地端口
	*	@return		:		E_OK：获取本地端口成功，E_FAIL:获取本地端口失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getLocalPort();

	/** 
	*
	* 	func name	:		getRemoteIp
	*	@brief		:	    获取远程Ip
	*	@return		:		E_OK：获取远程Ip成功，E_FAIL:获取远程Ip失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getRemoteIp();

	/** 
	*
	* 	func name	:		getRemotePort
	*	@brief		:	    获取远程端口
	*	@return		:		E_OK：获取远程端口成功，E_FAIL:获取远程端口失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getRemotePort();
	
	/** 
	*
	* 	func name	:		getReconnectFlag
	*	@brief		:	    获取重连标志
	*	@return		:		重连标志
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_bool getReconnectFlag();
	/** 
	*
	* 	func name	:		setReconnectFlag
	*	@brief		:	    设置重连标志
	*	@return		:		重连标志
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setReconnectFlag(t_bool reconnectFlag);

	/** 
	*
	* 	func name	:		getTcpState
	*	@brief		:	    获取TCP的当前状态
	*	@return		:		TCP当前状态
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getTcpState();

public:

	//使能TCP的可写回调
	t_int32 enableOutput();

	//关闭TCP的可写回调
	t_int32 disableOutput();

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
	
private:
	socketStreamI	socketStream;

	socketCbI		*connectCb;						//回调类指针
	void			*connectCbArg;					//回调类参数类型

	TCP_CONNECT_STATUS		m_status;

	TCP_SEND_TYPE	m_sendType;						//TCP发送方式：直接发送，默认智能指针发送，上层控制发送
	
	t_bool			m_bindFlag;						//是否需要绑定标志

	t_bool			m_reconnect;					//重连标志

	sockaddr_t		m_raddr;
	sockaddr_t		m_laddr;

	t_int8			m_localIp[sizeof("255.255.255.255")];
	t_uint16		m_localPort;

	t_int8			m_remoteIp[sizeof("255.255.255.255")];
	t_uint16		m_remotePort;

	eventTimerI		*m_connectTimer;					//定时器指针

	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;				//缓存队列
	eventNotifyI	m_eventSendNotify;				//发送通知

};



#endif

