/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_parser_i.h
* 	@brief:			prtl_parser_i.h定义了协议解析类, 完成协议解析；
* 	@author:			zhang_sunbo 
*	@note:	
*/

#ifndef _PRTL_PARSER_I_H
#define _PRTL_PARSER_I_H

#include <framework_i.h>
#include <prtl_wrapper/prtl_peer_i.h>


class prtlInstanceI;

/** 
*
*	class:		prtlParserI
* 	@brief:		prtlParserI协议解析基类, 完成协议接口	
* 	@author:	zhang_sunbo
*	@date:		2013-03-07
*	@note:	
*/
class prtlParserI
{
public:
	prtlParserI();
	virtual ~prtlParserI();

public:
	/** 
	*
	* 	func name:		serialize
	*	@brief:		协议序列化, 并完成数据发送
	*	@param:		packet 协议包
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 serialize(smartPrtlPacketI packet, prtlPeerI *peer);


public:

	/** 
	*
	* 	func name:		parse
	*	@brief:		解析接口
	*	@param:		void
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:		内部使用接口	
	*
	*/
	virtual t_int32 parse(prtlPeerI *peer, t_int8 *buff, t_int32 buffLen);

	/** 
	*
	* 	func name:		instance
	*	@brief:		设置解析器关联的实例
	*	@param:		void
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:		内部使用接口	
	*
	*/
	virtual t_int32 instance(prtlInstanceI *inst);
};





#endif
