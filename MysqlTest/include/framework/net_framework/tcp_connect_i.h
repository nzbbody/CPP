/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:			tcp_connect_i.h
 * 	@brief:			tcp_connect_i.h������tcp������
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
	TCP_SEND_NORMAL,	//ֱ�ӷ��ͷ�ʽ
	TCP_SEND_DEFAULT,	//Ĭ�ϵ�����ָ�뷢�ͷ�ʽ
	TCP_SEND_CALLBACK,	//�ص����ϲ㣬�ϲ㷢�ͣ�ע��������ø÷��ͷ�ʽ��Ĭ�ϵ�����ָ�뷢�ͷ�ʽ��Ч

}TCP_SEND_TYPE;
/** 
*
*	class:		tcpConnectCbI
* 	@brief:		tcpConnectCbIʵ��tcp���ӵĻص�����	
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
 * 	@brief:		tcpConnectIʵ��tcp���ӹ���	
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
	*	@brief		:	    ��tcp����
	*	@param		��		remoteIp��Զ��Ip,remotePort��Զ��Port��localIp������Ip��localPort�����ض˿�
	*	@return		:		E_OK����tcp���ӳɹ���E_FAIL:��tcp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 open(t_int8 *remoteIp, t_uint16 remotePort, 
		t_int8 *localIp = NULL, t_uint16 localPort = 0);

	/** 
	*
	* 	func name	:		close
	*	@brief		:	    �ر�tcp����
	*	@return		:		E_OK���ر�tcp���ӳɹ���E_FAIL:�ر�tcp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 close();

	/** 
	*
	* 	func name	:		resume
	*	@brief		:	    �ָ�tcp����
	*	@return		:		E_OK���ָ�tcp���ӳɹ���E_FAIL:�ָ�tcp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 resume();

	/** 
	*
	* 	func name	:		suspend
	*	@brief		:	    ����tcp����
	*	@return		:		E_OK������tcp���ӳɹ���E_FAIL:����tcp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 suspend();
	
	/** 
	*
	* 	func name	:		send
	*	@brief		:	    ��������
	*	@param		��		buff������������ָ�룬buffLen�����������ݳ��ȣ�flags�����ͱ�־��sended�������ѷ��͵����ݳ���
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
	*	@brief		:	    ����tcp����
	*	@return		:		E_OK������tcp���ӳɹ���E_FAIL:����tcp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	static t_int32 reconnect(void *arg);
public:
	/** 
	*
	* 	func name	:		setCallback
	*	@brief		:	    Ϊtcp�������ûص�����
	*	@param		��		callback���ص�����ָ�룬arg���ص���������ָ��
	*	@return		:		E_OK�����ûص������ɹ���E_FAIL:���ûص�����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setCallback(socketCbI *callback, void *arg);

	static t_int32 eventSendNotifyFunc(void *arg);

	/** 
	*
	* 	func name	:		complete
	*	@brief		:	    ���tcp����
	*	@return		:		E_OK����tcp���ӳɹ���E_FAIL:��tcp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 complete();

	/** 
	*
	* 	func name	:		getLocalIp
	*	@brief		:	    ��ȡ����Ip
	*	@return		:		E_OK����ȡ����Ip�ɹ���E_FAIL:��ȡ����Ipʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getLocalIp();

	/** 
	*
	* 	func name	:		getLocalPort
	*	@brief		:	    ��ȡ���ض˿�
	*	@return		:		E_OK����ȡ���ض˿ڳɹ���E_FAIL:��ȡ���ض˿�ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getLocalPort();

	/** 
	*
	* 	func name	:		getRemoteIp
	*	@brief		:	    ��ȡԶ��Ip
	*	@return		:		E_OK����ȡԶ��Ip�ɹ���E_FAIL:��ȡԶ��Ipʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getRemoteIp();

	/** 
	*
	* 	func name	:		getRemotePort
	*	@brief		:	    ��ȡԶ�̶˿�
	*	@return		:		E_OK����ȡԶ�̶˿ڳɹ���E_FAIL:��ȡԶ�̶˿�ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getRemotePort();
	
	/** 
	*
	* 	func name	:		getReconnectFlag
	*	@brief		:	    ��ȡ������־
	*	@return		:		������־
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_bool getReconnectFlag();
	/** 
	*
	* 	func name	:		setReconnectFlag
	*	@brief		:	    ����������־
	*	@return		:		������־
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setReconnectFlag(t_bool reconnectFlag);

	/** 
	*
	* 	func name	:		getTcpState
	*	@brief		:	    ��ȡTCP�ĵ�ǰ״̬
	*	@return		:		TCP��ǰ״̬
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getTcpState();

public:

	//ʹ��TCP�Ŀ�д�ص�
	t_int32 enableOutput();

	//�ر�TCP�Ŀ�д�ص�
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

	socketCbI		*connectCb;						//�ص���ָ��
	void			*connectCbArg;					//�ص����������

	TCP_CONNECT_STATUS		m_status;

	TCP_SEND_TYPE	m_sendType;						//TCP���ͷ�ʽ��ֱ�ӷ��ͣ�Ĭ������ָ�뷢�ͣ��ϲ���Ʒ���
	
	t_bool			m_bindFlag;						//�Ƿ���Ҫ�󶨱�־

	t_bool			m_reconnect;					//������־

	sockaddr_t		m_raddr;
	sockaddr_t		m_laddr;

	t_int8			m_localIp[sizeof("255.255.255.255")];
	t_uint16		m_localPort;

	t_int8			m_remoteIp[sizeof("255.255.255.255")];
	t_uint16		m_remotePort;

	eventTimerI		*m_connectTimer;					//��ʱ��ָ��

	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;				//�������
	eventNotifyI	m_eventSendNotify;				//����֪ͨ

};



#endif

