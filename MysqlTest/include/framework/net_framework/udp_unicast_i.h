

#ifndef _UDP_UNICAST_I_H
#define _UDP_UNICAST_I_H


#include <data_types.h>
#include <net_framework/inet_addr_i.h>
#include <net_framework/socket_stream_i.h>
#include <event_handler_i.h>
#include <event_timer_i.h>
#include <auto_buffer_i.h>
#include <event_notify_i.h>
#include <mutex_i.h>

typedef struct
{
	t_int8		ip[sizeof("255.255.255.255")];
	t_uint16	port;
	t_uint16	online;		//0:using 1:unusing
	t_int32		socket;
	t_uint16	id;
}udp_client_list;

typedef struct  
{
	unsigned int id;
	smartAutoBufferI sab;
}dataRow;

typedef enum
{
	UDP_LISTEN_SEND_NORMAL,	//ֱ�ӷ��ͷ�ʽ
	UDP_LISTEN_SEND_DEFAULT,	//Ĭ�ϵ�����ָ�뷢�ͷ�ʽ
	UDP_LISTEN_SEND_CALLBACK,	//�ص����ϲ㣬�ϲ㷢�ͣ�ע��������ø÷��ͷ�ʽ��Ĭ�ϵ�����ָ�뷢�ͷ�ʽ��Ч

}UDP_LISTEN_SEND_TYPE;

#ifdef WIN32
typedef stdext::hash_map<unsigned long, udp_client_list*> udpClientList;
#else
#include <ext/hash_map>
typedef __gnu_cxx::hash_map<unsigned long, udp_client_list*> udpClientList;
#endif

class DLL_EXPORT udpUnicastI :public eventHandlerI
{
public:
	udpUnicastI();
	virtual ~udpUnicastI();
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
	t_int32 open(t_int8 *localIp = NULL, t_uint16 localPort = 0);
	
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

	/** 
	*
	* 	func name	:		peerAdd
	*	@brief		:		udpUnicast������һ������
	*	@return		:		E_OK�����udp���ӳɹ���E_FAIL�����udp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 peerAdd(t_int8* remoteIp, t_uint16 remotePort);
	
	/** 
	*
	* 	func name	:		disConnect
	*	@brief		:		udpUnicast�˶Ͽ�һ������
	*	@return		:		E_OK���ر�udp���ӳɹ���E_FAIL���ر�udp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 disConnect(t_handler peerId);
	
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
	t_int32 send(t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int8 *remoteIp, t_uint16 remotePort, t_int32 &sended);
	t_int32 send(t_handler peerId, smartAutoBufferI& sab);


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
	t_int8 *getRemoteIp(t_handler peerId);
	/** 
	*
	* 	func name	:		getRemotePort
	*	@brief		:		��ȡԶ�̶˿�
	*	@return		:		Զ�̶˿ں�
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getRemotePort(t_handler peerId);
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

	//ʹ��UDP listen�Ŀ�д�ص�
	t_int32 enableOutput();

	//�ر�UDP listen�Ŀ�д�ص�
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
	t_int32 complete();
	t_int32 connect(t_int8* ip, t_uint16 port, t_handler &peer);
	t_int32 getClientId();

private:
	socketStreamI	socketStream;

	socketCbI		*connectCb;						//�ص�����ָ��
	void			*connectCbArg;					//�ص���������ָ��
	
	UDP_LISTEN_SEND_TYPE m_sendType;				//UDPlisten���õķ��ͷ�ʽ

	sockaddr_t		_laddr;							//���ص�ַ

	t_int8			_localIp[sizeof("255.255.255.255")];		
	t_uint16		_localPort;

	udpClientList	m_client;						//Զ�̿ͻ��˹���
	mutexI			m_clientMutex;
	t_uint32		m_clientId;

	t_bool			bBind;							//�Ƿ�󶨱�־

	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;

	eventNotifyI	m_eventSendNotify;

};


#endif


