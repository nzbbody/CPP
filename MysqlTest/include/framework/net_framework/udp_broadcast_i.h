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
	*	@brief		:	    ����udp����
	*	@param		:		remoteIp: Զ��IP��ַ��remotePort:Զ�̶˿�
	*	@param		:		localIp:  ����Ip��ַ��localPort:���ض˿�
	*	@return		:		E_OK������udp���ӳɹ���E_FAIL������udp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 open(t_uint16 localPort = 0);
	/** 
	*
	* 	func name	:		close
	*	@brief		:	    �ر�udp����
	*	@return		:		E_OK���ر�udp���ӳɹ���E_FAIL���ر�udp����ʧ��
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
	*	@brief		:	    Ϊudp�������ûص�����
	*	@return		:		E_OK���ص��������óɹ���E_FIAL:�ص���������ʧ��
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

	socketCbI		*m_connectCb;						//�ص�����ָ��
	void			*m_connectCbArg;					//�ص���������ָ��

	sockaddr_t		m_laddr;							//���ص�ַ
	sockaddr_t		m_fromAddr;						//�������ݵĵ�ַ
	sockaddr_t		m_toAddr;						//�������ݵ�Ŀ�ĵ�ַ

	UDPBROADCAST_STATUS m_status;					//udp�㲥״̬
	t_bool			m_bBind;									//�Ƿ�󶨱�־
	socklen_t		m_remoteLen;

	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;

	eventNotifyI m_eventSendNotify;

};



#endif

