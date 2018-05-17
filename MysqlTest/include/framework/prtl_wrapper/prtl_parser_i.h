/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_parser_i.h
* 	@brief:			prtl_parser_i.h������Э�������, ���Э�������
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
* 	@brief:		prtlParserIЭ���������, ���Э��ӿ�	
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
	*	@brief:		Э�����л�, ��������ݷ���
	*	@param:		packet Э���
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
	*	@brief:		�����ӿ�
	*	@param:		void
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:		�ڲ�ʹ�ýӿ�	
	*
	*/
	virtual t_int32 parse(prtlPeerI *peer, t_int8 *buff, t_int32 buffLen);

	/** 
	*
	* 	func name:		instance
	*	@brief:		���ý�����������ʵ��
	*	@param:		void
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:		�ڲ�ʹ�ýӿ�	
	*
	*/
	virtual t_int32 instance(prtlInstanceI *inst);
};





#endif
