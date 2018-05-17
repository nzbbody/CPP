/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:			tcp_listen_i.h
 * 	@brief:			tcp_listen_i.h������errCode�࣬��ɶ൱ǰ������Ĵ���
 * 	@author:			zhang_sunbo 
 *	@note:	
 */

#ifndef _TCP_LISTEN_I_H
#define _TCP_LISTEN_I_H

#include <data_types.h>
#include <list_i.h>
#include <event_handler_i.h>
#include <net_framework/socket_acceptor_i.h>
#include <net_framework/peer_stream_i.h>
#include <net_framework/socket_i.h>


class tcpListenCbI
{
public:
	virtual ~tcpListenCbI() {};

public:
	virtual t_int32 onAccept(t_handler handlerId, void *arg) = 0;
	virtual t_int32 onClose(t_handler handlerId, void *arg) = 0;
	virtual t_int32 onDisconnect(t_handler handlerId, void *arg) = 0;
};


class DLL_EXPORT tcpListenManagerI
{
public:
	t_int32 add(peerStreamI *peer);
	t_int32 del(peerStreamI *peer);
	t_int32 closeAll();

private:
	listI<peerStreamI *> peerStreamList;
};



/** 
 *
 *	class:		tcpListenI
 * 	@brief:		tcpListenIʵ��tcp��������
 * 	@author:		zhang_sunbo
 *	@date:		2012-12-27
 *	@note:	
 */
class DLL_EXPORT tcpListenI : public eventHandlerI, public tcpListenManagerI
{
public:
	tcpListenI();
	virtual ~tcpListenI();

public:
	/** 
	*
	* 	func name	:		open
	*	@brief		:	    ��tcp����
	*	@return		:		E_OK����tcp�����ɹ���E_FAIL����tcp������ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 open(t_int8 *ip,
		t_uint16 port,
		t_int32 reuse = 1, 
		t_int32 family = AF_INET, 
		t_int32 backlog = 5, 
		t_int32 proto = 0);
	/** 
	*
	* 	func name	:		close
	*	@brief		:	    �ر�tcp����
	*	@return		:		E_OK���ر�tcp�����ɹ���E_FAIL���ر�tcp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 close();
	/** 
	*
	* 	func name	:		resume
	*	@brief		:	    �ָ�tcp����
	*	@return		:		E_OK���ָ�tcp�����ɹ���E_FAIL���ָ�tcp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 resume();
	/** 
	*
	* 	func name	:		suspend
	*	@brief		:	    ����tcp����
	*	@return		:		E_OK������tcp�����ɹ���E_FAIL������tcp����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 suspend();

public:
	/** 
	*
	* 	func name	:		setCallback
	*	@brief		:		���ûص�����
	*	@param		��		callback���ص�����ָ�룬arg���ص���������ָ��
	*	@return		:		E_OK�����ûص������ɹ���E_FAIL�����ûص�����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setCallback(socketCbI *callback, void *arg);
	/** 
	*
	* 	func name	:		addpeer
	*	@brief		:		���ͨ��
	*	@param		��		peerͨ��ָ��
	*	@return		:		E_OK�����ͨ���ɹ���E_FAIL�����ͨ��ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 addPeer(peerStreamI *peer);
	/** 
	*
	* 	func name	:		delPeer
	*	@brief		:		ɾ��ͨ��
	*	@param		��		peer��ͨ��ָ��
	*	@return		:		E_OK��ɾ��ͨ���ɹ���E_FIAL��ɾ��ͨ��ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 delPeer(peerStreamI *peer);
	/** 
	*
	* 	func name	:		closeAllPeer
	*	@brief		:		�ر�����ͨ��
	*	@param		��		void
	*	@return		:		E_OK��ɾ���ɹ���E_FAIL��ɾ��ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 closeAllPeer();
	
public:
	virtual iohandle_t getHandle();
	virtual t_int32 setHandle(iohandle_t handle);


	virtual t_int32 handleInput(iohandle_t handle);
	virtual t_int32 handleOutput(iohandle_t handle);
	virtual t_int32 handleInputTimeout(iohandle_t handle);
	virtual t_int32 handleOutputTimeout(iohandle_t handle);
	virtual t_int32 handleException(iohandle_t handle);


private:
	//listI<peerStreamI *> peerStreamList;				//ͨ���б�
	
	socketAcceptorI peerAcceptor;						//�������֪��

	sockaddr_t listenAddr;								//socket��ַ

	socketCbI *listenCb;								//�ص�����ָ��
	void *listenCbArg;									//�ص���������ָ��

	
	
};



#endif

