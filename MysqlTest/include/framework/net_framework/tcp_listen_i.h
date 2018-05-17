/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:			tcp_listen_i.h
 * 	@brief:			tcp_listen_i.h定义了errCode类，完成多当前错误码的处理；
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
 * 	@brief:		tcpListenI实现tcp监听功能
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
	*	@brief		:	    打开tcp监听
	*	@return		:		E_OK：打开tcp监听成功，E_FAIL：打开tcp监听接失败
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
	*	@brief		:	    关闭tcp监听
	*	@return		:		E_OK：关闭tcp监听成功，E_FAIL：关闭tcp监听失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 close();
	/** 
	*
	* 	func name	:		resume
	*	@brief		:	    恢复tcp监听
	*	@return		:		E_OK：恢复tcp监听成功，E_FAIL：恢复tcp监听失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 resume();
	/** 
	*
	* 	func name	:		suspend
	*	@brief		:	    挂起tcp监听
	*	@return		:		E_OK：挂起tcp监听成功，E_FAIL：挂起tcp监听失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 suspend();

public:
	/** 
	*
	* 	func name	:		setCallback
	*	@brief		:		设置回调函数
	*	@param		：		callback：回调函数指针，arg：回调函数参数指针
	*	@return		:		E_OK：设置回调函数成功，E_FAIL：设置回调函数失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setCallback(socketCbI *callback, void *arg);
	/** 
	*
	* 	func name	:		addpeer
	*	@brief		:		添加通道
	*	@param		：		peer通道指针
	*	@return		:		E_OK：添加通道成功，E_FAIL：添加通道失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 addPeer(peerStreamI *peer);
	/** 
	*
	* 	func name	:		delPeer
	*	@brief		:		删除通道
	*	@param		：		peer：通道指针
	*	@return		:		E_OK：删除通道成功，E_FIAL：删除通道失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 delPeer(peerStreamI *peer);
	/** 
	*
	* 	func name	:		closeAllPeer
	*	@brief		:		关闭所有通道
	*	@param		：		void
	*	@return		:		E_OK：删除成功，E_FAIL：删除失败
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
	//listI<peerStreamI *> peerStreamList;				//通道列表
	
	socketAcceptorI peerAcceptor;						//这个还不知道

	sockaddr_t listenAddr;								//socket地址

	socketCbI *listenCb;								//回调函数指针
	void *listenCbArg;									//回调函数参数指针

	
	
};



#endif

