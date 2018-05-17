/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_instance_i.h
* 	@brief:			prtl_instance_i.h����Э��ص�������
* 	@author:			zhang_sunbo 
*	@note:	
*/

#ifndef _PRTL_INSTANCE_I_H
#define _PRTL_INSTANCE_I_H

#include <framework_i.h>
#include <prtl_wrapper/prtl_peer_i.h>
#include <prtl_wrapper/prtl_parser_i.h>
#include <prtl_wrapper/prtl_packet_i.h>


/** 
*
*	class:		prtlCallbackI
* 	@brief:		prtlCallbackIЭ��ص�����	
* 	@author:	zhang_sunbo
*	@date:		2013-03-07
*	@note:	
*/
class prtlCallbackI
{
public:
	prtlCallbackI() {};
	virtual ~prtlCallbackI() {};

public:
	/** 
	*
	* 	func name:		onData
	*	@brief:		���յ��İ����ظ��ϲ�
	*	@param:		parser Э�������
	*   @param:		peer �����ĶԶ�
	*	@param:		packet �յ���Э���
	*	@param:		arg ���ûص�ʱ�Ĳ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 onData(prtlPeerI *peer, t_int8 *buff, t_int32 buffLen, void* args)
	{
		return E_OK;
	}

	virtual t_int32 onData(prtlPeerI* handlerId, t_handler peer, t_int8 *buff, t_int32 buffLen, void *arg)
	{
		return E_OK;
	}
	/** 
	*
	* 	func name:		onPacket
	*	@brief:		�յ�һ��Э���
	*	@param:		parser Э�������
	*   @param:		peer �����ĶԶ�
	*	@param:		packet �յ���Э���
	*	@param:		arg ���ûص�ʱ�Ĳ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 onPacket(prtlParserI *parser, prtlPeerI *peer, smartPrtlPacketI packet, void *arg)
	{
		return E_OK;
	}

	/** 
	*
	* 	func name:		onPacketError
	*	@brief:		�յ�һ������Э���
	*	@param:		parser Э�������
	*   @param:		peer �����ĶԶ�
	*	@param:		packet �յ���Э���
	*	@param:		arg ���ûص�ʱ�Ĳ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 onPacketError(prtlParserI *parser, prtlPeerI *peer, smartPrtlPacketI packet, void *arg)
	{
		return E_OK;
	}
	
	/** 
	*
	* 	func name:		onConnect
	*	@brief:		���ӳɹ�
	*	@param:		parser Э�������
	*   @param:		peer �����ĶԶ�
	*	@param:		arg ���ûص�ʱ�Ĳ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 onConnect(prtlParserI *parser, prtlPeerI *peer,  void *arg)
	{
		return E_OK;
	}

	/** 
	*
	* 	func name:		onDisconnect
	*	@brief:		����ʧ��
	*	@param:		parser Э�������
	*   @param:		peer �����ĶԶ�
	*	@param:		arg ���ûص�ʱ�Ĳ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 onDisconnect(prtlParserI *parser, prtlPeerI *peer, void *arg)
	{
		return E_OK;
	}

	/** 
	*
	* 	func name:		onInputTimeout
	*	@brief:		�Է����볬ʱ
	*	@param:		parser Э�������
	*   @param:		peer �����ĶԶ�
	*	@param:		arg ���ûص�ʱ�Ĳ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 onInputTimeout(prtlParserI *parser, prtlPeerI *peer, void *arg)
	{
		return E_OK;
	}

	/** 
	*
	* 	func name:		onOutputTimeout
	*	@brief:		���������ʱ
	*	@param:		parser Э�������
	*   @param:		peer �����ĶԶ�
	*	@param:		arg ���ûص�ʱ�Ĳ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 onOutputTimeout(prtlParserI *parser, prtlPeerI *peer, void *arg)
	{
		return E_OK;
	}

	/** 
	*
	* 	func name:		onExpection
	*	@brief:		�쳣����
	*	@param:		parser Э�������
	*   @param:		peer �����ĶԶ�
	*	@param:		arg ���ûص�ʱ�Ĳ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 onExpection(prtlParserI *parser, prtlPeerI *peer, void *arg)
	{
		return E_OK;
	}

};


/** 
*
*	class:		prtlInstanceI
* 	@brief:		prtlInstanceIЭ�����ʵ��	
* 	@author:	zhang_sunbo
*	@date:		2013-03-07
*	@note:	
*/
class prtlInstanceI
{
public:
	prtlInstanceI();
	virtual ~prtlInstanceI();


public:
	/** 
	*
	* 	func name:	listen
	*	@brief:		�򿪼�����
	*	@param:		ip ����IP
	*   @param:		port �����˿�
	*	@return:	E_OK�������ɹ���E_FAIL����������
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual t_int32 listen(t_int8* ip, t_uint16 port);
	/** 
	*
	* 	func name:	connect
	*	@brief:		�����Ӷ�
	*	@param:		remoteIp
	*   @param:		remotePort
	*	@param:		localIp:����Ip��Ĭ��ֵNULL��
	*	@param:		localPort:����Port��Ĭ��ֵ0��
	*	@return:	E_OK���򿪳ɹ���E_FAIL����ʧ��
	*	@author:	zhang_xusheng
	*	@note:		
	*
	*/
	virtual t_int32 connect(t_int8* remoteIp, t_uint16 remotePort, t_int8* localIp = NULL, t_uint16 localPort = 0);
	/** 
	*
	* 	func name:		close
	*	@brief:		�رմ���
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 close();

	/** 
	*
	* 	func name:		close
	*	@brief:		�رյ�һ���Ӵ���
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual t_int32 close(prtlPeerI *peer);

	/** 
	*
	* 	func name:		reconnect
	*	@brief:		tcp������������һ��
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:		������TCP������	
	*
	*/
	virtual t_int32 reOpen();
	/** 
	*
	* 	func name:	addPeer
	*	@brief:		����һ������
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:		������UDPListen����
	*
	*/
	virtual t_int32 addPeer(t_int8 *remoteIp, t_uint16 remotePort);
public:

	/** 
	*
	* 	func name:		createDhcpParser
	*	@brief:		����һ��Dhcp������
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:		2013-5-28	
	*
	*/
	virtual prtlParserI *createDhcpParser();
public:
	/** 
	*
	* 	func name:		setCallback
	*	@brief:		���ûص�����
	*	@param:		prtlCb �ص������� 
	*	@param:		parser Э�������
	*	@param:		arg �ص�ʱ���صĲ���
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 setCallback(prtlCallbackI *prtlCb, prtlParserI *parser, void *arg);
	/** 
	*
	* 	func name:	isAutoReconnect
	*	@brief:		�Ƿ�����TCP�Զ���������
	*	@param:		 
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		tcp���Ӿ߱��Զ��������ܣ�����prtl_instanceΪtcpConnectʱʹ��
	*
	*/
	virtual t_int32 isAutoReconnect(t_bool flag);
	/** 
	*
	* 	func name:	getCallback
	*	@brief:		��ȡ�ص�����
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		�ڲ�ʹ��		
	*
	*/
	virtual prtlCallbackI *getCallback();
	/** 
	*
	* 	func name:		getParser
	*	@brief:		��ȡ������
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		�ڲ�ʹ��		
	*
	*/
	virtual prtlParserI *getParser();

	/** 
	*
	* 	func name:		getArg
	*	@brief:		��ȡ����
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		�ڲ�ʹ��		
	*
	*/
	virtual void *getArg();

	/** 
	*
	* 	func name:		getParser
	*	@brief:		��ȡ�Զ�
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		�ڲ�ʹ��		
	*
	*/
	virtual prtlPeerI *getPeer(t_int8 *host, t_uint16 port);

	/** 
	*
	* 	func name:		prtlFamily
	*	@brief:		��ȡЭ����
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		�ڲ�ʹ��		
	*
	*/
	virtual t_int32 prtlFamily();

	/** 
	*
	* 	func name:	getLocalIp
	*	@brief:		��ȡ��ַ
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		�ڲ�ʹ��		
	*
	*/
	virtual t_int8 *getLocalIp();

	/** 
	*
	* 	func name:	getLocalPort
	*	@brief:		��ȡ�˿�
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		�ڲ�ʹ��		
	*
	*/
	virtual t_uint16 getLocalPort();

	/** 
	*
	* 	func name:	getRemoteIp
	*	@brief:		��ȡ�˿�
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		�ڲ�ʹ��		
	*
	*/
	virtual t_int8 *getRemoteIp();
	
	/** 
	*
	* 	func name:	getRemotePort
	*	@brief:		��ȡ�˿�
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		�ڲ�ʹ��		
	*
	*/
	virtual t_uint16 getRemotePort();
};
#endif
