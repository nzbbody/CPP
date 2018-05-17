/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_factory_i.h
* 	@brief:			prtl_packet_i.h������Э�����, ���Э�������Ϻ���ȡ��
* 	@author:			zhang_sunbo 
*	@note:	
*/

#ifndef _PRTL_FACTORY_I_H
#define _PRTL_FACTORY_I_H


#include <prtl_wrapper/prtl_instance_i.h>


/** 
*
*	class:		prtlFactoryI
* 	@brief:		prtlFactoryIЭ�鹤����	
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
	*	@brief:		����һ��tcp ������Э�����
	*	@param:		instance����Э�����
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
	*	@brief:		����һ��tcp ������Э�����
	*	@param:		instance����Э�����
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
	*	@brief:		����һ��tcp ���ӵ�Э�����
	*	@param:		instance����Э�����
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
	*	@brief:		����һ��tcp ���ӵ�Э�����
	*	@param:		instance����Э�����
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
	*	@brief:		����һ��udp ���ӵ�Э�����
	*	@param:		instance����Э�����
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
	*	@brief:		����һ��udp ���ӵ�Э�����
	*	@param:		instance����Э�����
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
	*	@brief:		����һ��udp ������Э�����
	*	@param:		instance����Э�����
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
	*	@brief:		����һ��udp ������Э�����
	*	@param:		instance����Э�����
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	static t_int32 destoryUdpListen(prtlInstanceI *instance);

};






#endif
