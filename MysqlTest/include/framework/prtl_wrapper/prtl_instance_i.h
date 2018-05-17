/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_instance_i.h
* 	@brief:			prtl_instance_i.h定义协议回调函数；
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
* 	@brief:		prtlCallbackI协议回调函数	
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
	*	@brief:		将收到的包返回给上层
	*	@param:		parser 协议解析器
	*   @param:		peer 关联的对端
	*	@param:		packet 收到的协议包
	*	@param:		arg 设置回调时的参数
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
	*	@brief:		收到一个协议包
	*	@param:		parser 协议解析器
	*   @param:		peer 关联的对端
	*	@param:		packet 收到的协议包
	*	@param:		arg 设置回调时的参数
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
	*	@brief:		收到一个错误协议包
	*	@param:		parser 协议解析器
	*   @param:		peer 关联的对端
	*	@param:		packet 收到的协议包
	*	@param:		arg 设置回调时的参数
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
	*	@brief:		连接成功
	*	@param:		parser 协议解析器
	*   @param:		peer 关联的对端
	*	@param:		arg 设置回调时的参数
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
	*	@brief:		连接失败
	*	@param:		parser 协议解析器
	*   @param:		peer 关联的对端
	*	@param:		arg 设置回调时的参数
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
	*	@brief:		对方输入超时
	*	@param:		parser 协议解析器
	*   @param:		peer 关联的对端
	*	@param:		arg 设置回调时的参数
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
	*	@brief:		本端输出超时
	*	@param:		parser 协议解析器
	*   @param:		peer 关联的对端
	*	@param:		arg 设置回调时的参数
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
	*	@brief:		异常处理
	*	@param:		parser 协议解析器
	*   @param:		peer 关联的对端
	*	@param:		arg 设置回调时的参数
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
* 	@brief:		prtlInstanceI协议对象实例	
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
	*	@brief:		打开监听端
	*	@param:		ip 监听IP
	*   @param:		port 监听端口
	*	@return:	E_OK：监听成功；E_FAIL：监听出错
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual t_int32 listen(t_int8* ip, t_uint16 port);
	/** 
	*
	* 	func name:	connect
	*	@brief:		打开连接端
	*	@param:		remoteIp
	*   @param:		remotePort
	*	@param:		localIp:本地Ip，默认值NULL；
	*	@param:		localPort:本地Port，默认值0；
	*	@return:	E_OK：打开成功；E_FAIL：打开失败
	*	@author:	zhang_xusheng
	*	@note:		
	*
	*/
	virtual t_int32 connect(t_int8* remoteIp, t_uint16 remotePort, t_int8* localIp = NULL, t_uint16 localPort = 0);
	/** 
	*
	* 	func name:		close
	*	@brief:		关闭处理
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 close();

	/** 
	*
	* 	func name:		close
	*	@brief:		关闭单一连接处理
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual t_int32 close(prtlPeerI *peer);

	/** 
	*
	* 	func name:		reconnect
	*	@brief:		tcp连接重新连接一次
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:		仅用于TCP的重连	
	*
	*/
	virtual t_int32 reOpen();
	/** 
	*
	* 	func name:	addPeer
	*	@brief:		增加一条连接
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:		仅用于UDPListen类型
	*
	*/
	virtual t_int32 addPeer(t_int8 *remoteIp, t_uint16 remotePort);
public:

	/** 
	*
	* 	func name:		createDhcpParser
	*	@brief:		创建一个Dhcp解析器
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
	*	@brief:		设置回调函数
	*	@param:		prtlCb 回调处理函数 
	*	@param:		parser 协议解析器
	*	@param:		arg 回调时返回的参数
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 setCallback(prtlCallbackI *prtlCb, prtlParserI *parser, void *arg);
	/** 
	*
	* 	func name:	isAutoReconnect
	*	@brief:		是否启动TCP自动重连功能
	*	@param:		 
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		tcp连接具备自动重连功能，仅在prtl_instance为tcpConnect时使用
	*
	*/
	virtual t_int32 isAutoReconnect(t_bool flag);
	/** 
	*
	* 	func name:	getCallback
	*	@brief:		获取回调函数
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		内部使用		
	*
	*/
	virtual prtlCallbackI *getCallback();
	/** 
	*
	* 	func name:		getParser
	*	@brief:		获取解析器
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		内部使用		
	*
	*/
	virtual prtlParserI *getParser();

	/** 
	*
	* 	func name:		getArg
	*	@brief:		获取参数
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		内部使用		
	*
	*/
	virtual void *getArg();

	/** 
	*
	* 	func name:		getParser
	*	@brief:		获取对端
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		内部使用		
	*
	*/
	virtual prtlPeerI *getPeer(t_int8 *host, t_uint16 port);

	/** 
	*
	* 	func name:		prtlFamily
	*	@brief:		获取协议族
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		内部使用		
	*
	*/
	virtual t_int32 prtlFamily();

	/** 
	*
	* 	func name:	getLocalIp
	*	@brief:		获取地址
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		内部使用		
	*
	*/
	virtual t_int8 *getLocalIp();

	/** 
	*
	* 	func name:	getLocalPort
	*	@brief:		获取端口
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		内部使用		
	*
	*/
	virtual t_uint16 getLocalPort();

	/** 
	*
	* 	func name:	getRemoteIp
	*	@brief:		获取端口
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		内部使用		
	*
	*/
	virtual t_int8 *getRemoteIp();
	
	/** 
	*
	* 	func name:	getRemotePort
	*	@brief:		获取端口
	*	@return:	
	*	@author:	zhang_xusheng
	*	@note:		内部使用		
	*
	*/
	virtual t_uint16 getRemotePort();
};
#endif
