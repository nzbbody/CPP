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
	UDP_SEND_NORMAL,	//ֱ�ӷ��ͷ�ʽ
	UDP_SEND_DEFAULT,	//Ĭ�ϵ�����ָ�뷢�ͷ�ʽ
	UDP_SEND_CALLBACK,	//�ص����ϲ㣬�ϲ㷢�ͣ�ע��������ø÷��ͷ�ʽ��Ĭ�ϵ�����ָ�뷢�ͷ�ʽ��Ч

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
	*	@brief		:	    ����udp����
	*	@param		:		remoteIp: Զ��IP��ַ��remotePort:Զ�̶˿�
	*	@param		:		localIp:  ����Ip��ַ��localPort:���ض˿�
	*	@return		:		E_OK������udp���ӳɹ���E_FAIL������udp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note		:		udp�����ִ򿪷�ʽ��
	*						A�������ӷ�ʽ--->ָ��Զ��IP���˿ںͱ���IP���˿�
	*						B: �������ӷ�ʽ--->ָ��Զ��IP���˿ںͱ��ض˿ڣ�����IPΪNULL��Ϊ���ַ��������ӻ���ָ���ı��ض˿�ȥ��������
	*						C���������ӷ�ʽ--->ָ��Զ��IP���˿ڣ����ӻ��漴ѡ��˿�ȥ����
	*/
	t_int32 open(t_int8 *remoteIp, t_uint16 remotePort, 
		t_int8 *localIp = NULL, t_uint16 localPort = 0);
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
	/** 
	*
	* 	func name	:		send
	*	@brief		:	    udp���ӷ�������
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
	*	@brief		:	    ��ȡ����Ip��ַ
	*	@return		:		����Ip��ַ�ַ���
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getLocalIp();
	/** 
	*
	* 	func name	:		getLocalPort
	*	@brief		:	    ��ȡ���ض˿�
	*	@return		:		���ض˿�
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getLocalPort();
	/** 
	*
	* 	func name	:		getRemoteIp
	*	@brief		:	    ��ȡԶ��Ip��ַ
	*	@return		:		Զ��Ip��ַ�ַ���
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getRemoteIp();
	/** 
	*
	* 	func name	:		getRemotePort
	*	@brief		:		��ȡԶ�̶˿�
	*	@return		:		Զ�̶˿ں�
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getRemotePort();

public:
	//ʹ��TCP�Ŀ�д�ص�
	t_int32 enableOutput();

	//�ر�TCP�Ŀ�д�ص�
	t_int32 disableOutput();

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
	
	UDP_SEND_TYPE	m_sendType;						//TCP���ͷ�ʽ��ֱ�ӷ��ͣ�Ĭ������ָ�뷢�ͣ��ϲ���Ʒ���
	sockaddr_t		m_laddr;							//���ص�ַ
	sockaddr_t		m_raddr;							//Զ�̵�ַ

	t_int8			m_localIp[sizeof("255.255.255.255")];		
	t_uint16		m_localPort;
	t_int8			m_remoteIp[sizeof("255.255.255.255")];
	t_uint16		m_remotePort;

	UDP_STATUS		m_status;
	t_bool			m_bBind;									//�Ƿ�󶨱�־
	t_bool			m_connectFlag;								//�Ƿ����ӱ�־
	socklen_t		m_remoteLen;

	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;

	eventNotifyI	m_eventSendNotify;

};



#endif


