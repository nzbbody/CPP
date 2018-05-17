/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:			peer_stream_i.h
 * 	@brief:			peer_stream_i.h定义了对端连接类
 * 	@author:			zhang_sunbo 
 *	@note:	
 */


#ifndef _PEER_STREAM_I_H
#define _PEER_STREAM_I_H

#include <event_handler_i.h>
#include <net_framework/socket_stream_i.h>
#include <auto_buffer_i.h>
#include <event_notify_i.h>
#include <mutex_i.h>

typedef enum
{
	TCP_PEER_SEND_NORMAL,	//直接发送方式
	TCP_PEER_SEND_DEFAULT,	//默认的智能指针发送方式
	TCP_PEER_SEND_CALLBACK,	//回调给上层，上层发送；注意如果采用该发送方式，默认的智能指针发送方式无效

}TCP_PEER_SEND_TYPE;

class DLL_EXPORT peerStreamCbI
{
public:
	virtual ~peerStreamCbI() {};

public:
	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg) = 0;
	virtual t_int32 onClose(t_handler handlerId, void *arg) = 0;
	virtual t_int32 onDisconnect(t_handler handlerId, void *arg) = 0;
	
};

/** 
 *
 *	class:		peerStreamI
 * 	@brief:		peerStreamI实现对端连接
 * 	@author:	zhang_sunbo
 *	@date:		2012-12-27
 *	@note:	
 */
 
class DLL_EXPORT peerStreamI : public eventHandlerI
{
public:
	peerStreamI();
	virtual ~peerStreamI();
	
public:
	virtual t_int32 handleInput(iohandle_t handle);
	virtual	t_int32 handleInputTimeout(iohandle_t handle);
	virtual t_int32 handleOutput(iohandle_t handle);
	virtual t_int32 handleOutputTimeout(iohandle_t handle);
	virtual iohandle_t getHandle();



public:
	t_int32 open(t_int32 nonblocking);
	t_int32 close();

	t_int32 send(t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int32 &sended);
	t_int32 send(smartAutoBufferI sab);

	t_int32 onConnect();
	t_int32 onDisconnect();

public:
	socketStreamI &getStream();
	sockaddr_t &getAddr();

	t_int32 setIpAddr(t_int8 *ip);
	t_int8 *getIpAddr();
	t_int32 setPort(t_uint16 port);
	t_uint16 getPort();
	/** 
	*
	* 	@funcname	:		getStatus
	*	@brief		:	    获取通道当前状态
	*						
	*	@author		:	    zhang_xusheng 
	*	@date:		:		2013-6-20
	*
	*/
	t_bool getPeerStatus();
	void *getPeerArg();

	/** 
	*
	* 	@funcname	:		OpenType
	*	@brief		:	    peerStream的打开方式
	*	@note		：		OpenType 0：tcpListen自动完成peerStream的打开动作；1：peerStream打开由用户完成
	*	@author		:	    zhang_xusheng 
	*	@date:		:		2013-6-20
	*
	*/
	t_int32 getOpenType();
	t_int32 setOpenType(t_int32 openType);

public:

	//使能TCP peer的可写回调
	t_int32 enableOutput();

	//关闭TCP peer的可写回调
	t_int32 disableOutput();

public:
	t_int32 setCallback(socketCbI *callback, void *arg);

	static t_int32 eventSendNotifyFunc(void *arg);
	/** 
	*
	* 	class name	:		setTimeOut
	*	@brief		:	    设置超时时间
	*						
	*	@author		:	    zhang_xusheng 
	*	@date:		:		2013-6-17
	*
	*/
	t_int32 setTimeOut(t_int32 time);

private:
	t_int32 complete();

private:
	socketStreamI	socketStream;
	sockaddr_t		peerAddr;

	t_bool			isAccept;
	t_bool			_online;
	t_bool			m_connecting;

	socketCbI		*peerCb;
	void			*peerCbArg;

	TCP_PEER_SEND_TYPE m_sendType;
	t_int32			m_openType;	//OpenType 0：tcpListen自动完成peerStream的打开动作；1：peerStream打开由用户完成

	t_int8			peerIp[sizeof("255.255.255.255")];
	t_uint16		peerPort;
	t_int32			m_timeout;
	
	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;					//缓存队列
	eventNotifyI	m_eventSendNotify;						//发送通知

};

t_int32 DLL_EXPORT peerStreamSend(t_handler handlerId, t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int32 &sended);


#endif

