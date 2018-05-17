/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_factory_i.h
* 	@brief:			prtl_packet_i.h定义了协议包类, 完成协议包的组合和提取；
* 	@author:			zhang_sunbo 
*	@note:	
*/

#ifndef _PRTL_FACTORY_I_H
#define _PRTL_FACTORY_I_H


#include <prtl_wrapper/prtl_instance_i.h>


/** 
*
*	class:		prtlFactoryI
* 	@brief:		prtlFactoryI协议工厂类	
* 	@author:	zhang_sunbo
*	@date:		2013-03-07
*	@note:	
*/
class prtlFactoryI
{
public:
	prtlFactoryI();
	virtual ~prtlFactoryI();

public:
	/** 
	*
	* 	func name:		createTcpListen
	*	@brief:		创建一个tcp 监听的协议对象
	*	@param:		instance返回协议对象
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	static t_int32 createTcpListen(prtlInstanceI **instance);
	/** 
	*
	* 	func name:		destoryTcpListen
	*	@brief:		销毁一个tcp 监听的协议对象
	*	@param:		instance返回协议对象
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	static t_int32 destoryTcpListen(prtlInstanceI *instance);
	/** 
	*
	* 	func name:		createTcpConnect
	*	@brief:		创建一个tcp 连接的协议对象
	*	@param:		instance返回协议对象
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	static t_int32 createTcpConnect(prtlInstanceI **instance);
	/** 
	*
	* 	func name:		destoryTcpConnect
	*	@brief:		销毁一个tcp 连接的协议对象
	*	@param:		instance返回协议对象
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	static t_int32 destoryTcpConnect(prtlInstanceI *instance);
	/** 
	*
	* 	func name:		createUdpConnect
	*	@brief:		创建一个udp 连接的协议对象
	*	@param:		instance返回协议对象
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	static t_int32 createUdpConnect(prtlInstanceI **instance);
	/** 
	*
	* 	func name:		destoryUdpConnect
	*	@brief:		销毁一个udp 连接的协议对象
	*	@param:		instance返回协议对象
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	static t_int32 destoryUdpConnect(prtlInstanceI *instance);
	/** 
	*
	* 	func name:		createUdpListen
	*	@brief:		创建一个udp 监听的协议对象
	*	@param:		instance返回协议对象
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	static t_int32 createUdpListen(prtlInstanceI **instance);
	/** 
	*
	* 	func name:		destoryUdpListen
	*	@brief:		创建一个udp 监听的协议对象
	*	@param:		instance返回协议对象
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	static t_int32 destoryUdpListen(prtlInstanceI *instance);

};






#endif
