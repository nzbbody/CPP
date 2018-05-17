/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_peer_i.h
* 	@brief:			prtl_peer_i.h����Э�����ӶԶˣ�
* 	@author:			zhang_sunbo 
*	@note:	
*/

#ifndef _PRTL_PEER_I_H
#define _PRTL_PEER_I_H

#include <framework_i.h>
#include <prtl_wrapper/prtl_packet_i.h>


/** 
*
*	class:		prtlPeerI
* 	@brief:		prtlPeerIЭ��Զ�	
* 	@author:	zhang_sunbo
*	@date:		2013-03-07
*	@note:	
*/
class prtlPeerI
{
public:
	prtlPeerI();
	virtual ~prtlPeerI();

public:
	/** 
	*
	* 	func name:		sendData
	*	@brief:		��������
	*	@param:		
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 sendData(t_int8 *buff, t_int32 buffLen);

	/** 
	*
	* 	func name:		sendPacket
	*	@brief:		���Ͱ�
	*	@param:		
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 sendPacket(prtlPacketI *packet);

public:
	/** 
	*
	* 	func name:		getRemoteIP
	*	@brief:		��ȡ�˿�
	*	@param:		
	*	@param:		void
	*	@return:	IP��ַ�ַ���
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual t_int8* getRemoteIP();

	/** 
	*
	* 	func name:		getRemotePort
	*	@brief:		��ȡ�˿�
	*	@param:		
	*	@param:		void
	*	@return:	Զ�̶˿ڵ�ַ
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual t_uint16 getRemotePort();

	/** 
	*
	* 	func name:		getLocalIP
	*	@brief:		��ȡ�˿�
	*	@param:		
	*	@param:		void
	*	@return:	����IP��ַ
	*	@author:	zhang_xusheng
	*	@note:		���ӿ�ֻ������tcpConnect��udpConnect����������peerStream	
	*
	*/
	virtual t_int8* getLocalIP();

	/** 
	*
	* 	func name:		getLocalPort
	*	@brief:		��ȡ�˿�
	*	@param:		
	*	@param:		void
	*	@return:	���ض˿�
	*	@author:	zhang_xusheng
	*	@note:		���ӿ�ֻ������tcpConnect��udpConnect����������peerStream	
	*
	*/
	virtual t_uint16 getLocalPort();

	virtual t_int32 getRegId();

	virtual t_int32 setRegId(t_int32 regId);

	virtual t_int32 setTime(t_uint32);

	virtual t_uint32 getTime();

protected:
	t_uint32 m_time;
};


#endif
