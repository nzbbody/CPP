

/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			net_detect_terminal_i.h
* 	@brief:			net_detect_terminal_i.h��������̽���նˣ���Ҫ�����ǣ�
*											��1����������̽������
											��2��������̽����ע��̽��Ŀ�ꣻ
											��3����������̽������̽������
* 	@author:		zhang_xusheng
*	@date��			2015-1-6
*	@note:	
*/

#ifndef NET_DETECT_TERMINAL_I_H_
#define NET_DETECT_TERMINAL_I_H_

#include <data_types.h>
#include <net_framework/socket_i.h>
#include <net_framework/tcp_connect_i.h>


enum NETSTATUS
{
	NET_UNKOWN = 0,	//����״̬δ֪
	NET_GREEN,	//����״̬����
	NET_YELLOW,		//��������ʱ
	NET_RED,		//������ʱ����
	NET_BLACK,		//�����������
	NET_DISCONNECT,	//�������
};

typedef struct
{
	t_int8 dstIp[sizeof("255.255.255.255")];
	t_int32 netStatus;
}netStatusNotify;

/** 
*
*	class:		netStatusCbI
* 	@brief:		netStatusCbI����������״̬̽��Ļص�������������̽���ն��յ�����״̬��Ϣʱ��ͨ���ûص������ص����ϲ�	
* 	@author:	zhang_xusheng
*	@date:		2015-1-6
*	@note:	
*/
class DLL_EXPORT NetStatusCbI
{
public:
	NetStatusCbI();
	virtual ~NetStatusCbI();

public:
	virtual t_int32 onNetStatus(t_int8* dstIp, NETSTATUS netStatus, void* args);

};

/** 
*
*	class:		dhNetDetectTerminal
* 	@brief:		dhNetDetectTerminal����������̽���ն�
* 	@author:	zhang_xusheng
*	@date:		2015-1-6
*	@note:	
*/
class DLL_EXPORT DhNetDetectTerminalI : public socketCbI
{
public:
	DhNetDetectTerminalI();
	virtual ~DhNetDetectTerminalI();

public:
	
	/** 
	* 	func name	:		onConnect
	*	@brief		:	    ̽���ն����ӳɹ��Ļص���Ϣ
	*	@param		��		handlerId:���Ӿ��
	*	@return		:		
	*	@author		:	    zhang_xusheng
	*	@note		:		ϵͳ�ص��ӿڣ��û�������������
	*/
	virtual t_int32 onConnect(t_handler handlerId, void *arg);

	/** 
	* 	func name	:		onData
	*	@brief		:	    ̽���ն˽������ݵĻص��ӿڣ����յ���Ϣ�󣬵ײ���øýӿ�֪ͨ�ϲ�
	*	@param		��		handlerId:���Ӿ����buff���յ������ݣ�buffLen:���ݳ���
	*	@return		:		
	*	@author		:	    zhang_xusheng
	*	@note		:		ϵͳ�ص��ӿڣ��û�������������
	*/
	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg);

public:

	/** 
	* 	func name	:		start
	*	@brief		:	    ����̽���ն�
	*	@param		��		void
	*	@return		:		����̽���ն˶���ִ�����
	*	@author		:	    zhang_xusheng
	*	@note		:		̽���ն���������ʱ��ϵͳ�ص�onConnect֪ͨ�ϲ㣬�˴��ķ���ֵΪstartִ�гɹ����
	*/
	t_int32 start(void);

	/** 
	* 	func name	:		stop
	*	@brief		:	    �ر�̽���ն�
	*	@param		��		void
	*	@return		:		E_OK��̽���ն˹رճɹ���E_FAIL��̽���ն˹ر�ʧ�ܣ��������errCode::lastError()��ȡ
	*	@author		:	    zhang_xusheng
	*	@note		:		�رն�������ͬ��������ֱֵ�ӱ�ʾ�رս��
	*/
	t_int32 stop(void);

	/** 
	* 	func name	:		setCallback
	*	@brief		:	    ����̽���ն˵Ļص�������ָ����̽���ն��յ����ݺ�ص��Ķ���
	*	@param		��		callback���ص�����ָ�룻args���ص�����
	*	@return		:		
	*	@author		:	    zhang_xusheng
	*	@note		:		
	*/
	t_int32 setCallback(NetStatusCbI* callback, void* args);

public:

	/** 
	* 	func name	:		registerIp
	*	@brief		:	    ��̽������ע��IP
	*	@param		��		dstIp��Ŀ������
	*	@return		:		E_OK��ע��ɹ���E_FAIL:ע��ʧ��
	*	@author		:	    zhang_xusheng
	*	@note		:	
	*/
	t_int32 registerIp(const t_int8* dstIp);
	
	/** 
	* 	func name	:		unRegisterIp
	*	@brief		:	    ��̽������ע��IP
	*	@param		��		dstIP��Ŀ������
	*	@return		:		E_OK��ע���ɹ���E_FAIL��ע��ʧ��
	*	@author		:	    zhang_xusheng
	*	@note		:	
	*/
	t_int32 unRegisterIp(const t_int8* dstIp);

private:
	tcpConnectI m_detectTerminal;
	t_int32 m_status;	//��ǰ�ն�״̬��0��δ���ӣ�1��������

private:
	NetStatusCbI* m_callback;
	void* m_args;
};

#endif
