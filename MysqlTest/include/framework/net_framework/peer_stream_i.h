/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:			peer_stream_i.h
 * 	@brief:			peer_stream_i.h�����˶Զ�������
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
	TCP_PEER_SEND_NORMAL,	//ֱ�ӷ��ͷ�ʽ
	TCP_PEER_SEND_DEFAULT,	//Ĭ�ϵ�����ָ�뷢�ͷ�ʽ
	TCP_PEER_SEND_CALLBACK,	//�ص����ϲ㣬�ϲ㷢�ͣ�ע��������ø÷��ͷ�ʽ��Ĭ�ϵ�����ָ�뷢�ͷ�ʽ��Ч

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
 * 	@brief:		peerStreamIʵ�ֶԶ�����
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
	*	@brief		:	    ��ȡͨ����ǰ״̬
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
	*	@brief		:	    peerStream�Ĵ򿪷�ʽ
	*	@note		��		OpenType 0��tcpListen�Զ����peerStream�Ĵ򿪶�����1��peerStream�����û����
	*	@author		:	    zhang_xusheng 
	*	@date:		:		2013-6-20
	*
	*/
	t_int32 getOpenType();
	t_int32 setOpenType(t_int32 openType);

public:

	//ʹ��TCP peer�Ŀ�д�ص�
	t_int32 enableOutput();

	//�ر�TCP peer�Ŀ�д�ص�
	t_int32 disableOutput();

public:
	t_int32 setCallback(socketCbI *callback, void *arg);

	static t_int32 eventSendNotifyFunc(void *arg);
	/** 
	*
	* 	class name	:		setTimeOut
	*	@brief		:	    ���ó�ʱʱ��
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
	t_int32			m_openType;	//OpenType 0��tcpListen�Զ����peerStream�Ĵ򿪶�����1��peerStream�����û����

	t_int8			peerIp[sizeof("255.255.255.255")];
	t_uint16		peerPort;
	t_int32			m_timeout;
	
	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;					//�������
	eventNotifyI	m_eventSendNotify;						//����֪ͨ

};

t_int32 DLL_EXPORT peerStreamSend(t_handler handlerId, t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int32 &sended);


#endif

