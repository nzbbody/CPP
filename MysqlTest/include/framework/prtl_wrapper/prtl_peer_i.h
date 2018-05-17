/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_peer_i.h
* 	@brief:			prtl_peer_i.h定义协议连接对端；
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
* 	@brief:		prtlPeerI协议对端	
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
	*	@brief:		发送数据
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
	*	@brief:		发送包
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
	*	@brief:		获取端口
	*	@param:		
	*	@param:		void
	*	@return:	IP地址字符串
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual t_int8* getRemoteIP();

	/** 
	*
	* 	func name:		getRemotePort
	*	@brief:		获取端口
	*	@param:		
	*	@param:		void
	*	@return:	远程端口地址
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual t_uint16 getRemotePort();

	/** 
	*
	* 	func name:		getLocalIP
	*	@brief:		获取端口
	*	@param:		
	*	@param:		void
	*	@return:	本地IP地址
	*	@author:	zhang_xusheng
	*	@note:		本接口只适用于tcpConnect和udpConnect，不适用于peerStream	
	*
	*/
	virtual t_int8* getLocalIP();

	/** 
	*
	* 	func name:		getLocalPort
	*	@brief:		获取端口
	*	@param:		
	*	@param:		void
	*	@return:	本地端口
	*	@author:	zhang_xusheng
	*	@note:		本接口只适用于tcpConnect和udpConnect，不适用于peerStream	
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
