/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_packet_i.h
* 	@brief:			prtl_packet_i.h������Э�����, ���Э�������Ϻ���ȡ��
* 	@author:			zhang_sunbo 
*	@note:	
*/

#ifndef _PRTL_PACKET_I_H
#define _PRTL_PACKET_I_H


#include <framework_i.h>

/** 
*
*	class:		prtlPacketI
* 	@brief:		prtlPacketIЭ�������,����Э�������Ļ����ӿ�	
* 	@author:	zhang_sunbo
*	@date:		2013-03-07
*	@note:	
*/
#define DHCPLOG "dhcpLog"

class prtlPacketI : public smartPtrI
{
	friend class smartPtrI;
public:
	prtlPacketI();
	virtual ~prtlPacketI();
public:


public:
	/** 
	*
	* 	func name:		getProtocal
	*	@brief:		��ȡЭ������
	*	@param:		void
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual stringI getProtocal();
	/** 
	*
	* 	func name:		getVersion
	*	@brief:		��ȡ�汾��
	*	@param:		void
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 getVersion();
	/** 
	*
	* 	func name:		setMethod
	*	@brief:		����Э������
	*	@param:		method ������,����μ�����ʵ�ֶ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 setMethod(t_int32 method);
	/** 
	*
	* 	func name:		setMethod
	*	@brief:		����Э������
	*	@param:		method ������,����μ�����ʵ�ֶ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/
	virtual t_int32 setMethod(t_int8 *method);
	/** 
	*
	* 	func name:		getMethod
	*	@brief:		��ȡЭ������
	*	@param:		method ������,����μ�����ʵ�ֶ���
	*	@param:		void
	*	@return:	���ط���
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/

	virtual t_int32 getMethod(stringI &command);
	/** 
	*
	* 	func name:		getMethod
	*	@brief:		��ȡЭ������
	*	@param:		method ������,����μ�����ʵ�ֶ���
	*	@param:		void
	*	@return:	���ط���
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/

	virtual t_int32 getMethod();
	/** 
	*
	* 	func name:		getModule
	*	@brief:		��ȡģ����
	*	@param:		module ģ����,����μ�����ʵ�ֶ���
	*	@param:		void
	*	@return:	���ط���
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/

	virtual t_int32 getModule(stringI &module);

	/** 
	*
	* 	func name:		setModule
	*	@brief:		����ģ����
	*	@param:		module ģ����,����μ�����ʵ�ֶ���
	*	@param:		void
	*	@return:	���ط���
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/

	virtual t_int32 setModule(t_int8 *module);

	/** 
	*
	* 	func name:		setExpires
	*	@brief:		���ù���ʱ��
	*	@param:		expires ����ʱ��-��
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 setExpires(t_int32 expires);

	/** 
	*
	* 	func name:		getExpires
	*	@brief:		��ȡ����ʱ��
	*	@param:		expires ����ʱ��-��
	*	@param:		void
	*	@return:	���ع���ʱ��
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 getExpires();


	/** 
	*
	* 	func name:		setFromCode
	*	@brief:		����From������
	*	@param:		code �����ַ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setFromCode(t_int8 *code);

	/** 
	*
	* 	func name:		setFromAddr
	*	@brief:		����From�ĵ�ַ
	*	@param:		addr ��ַ�ַ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setFromAddr(t_int8 *addr);
	/** 
	*
	* 	func name:		setFromPort
	*	@brief:		����From�Ķ˿�
	*	@param:		port �˿�
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setFromPort(t_uint16 port);
	/** 
	*
	* 	func name:		getFromCode
	*	@brief:		��ȡFrom������
	*	@param:		void
	*	@param:		void
	*	@return:	����
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getFromCode();
	/** 
	*
	* 	func name:		setSequence
	*	@brief:		�������к�
	*	@param:		void
	*	@param:		void
	*	@return:	����
	*	@author:	zhang_xusheng		
	*
	*/
	virtual t_int32 setSequence(t_uint32 sequence);
	/** 
	*
	* 	func name:		getSequence
	*	@brief:		�������к�
	*	@param:		void
	*	@param:		void
	*	@return:	����
	*	@author:	zhang_xusheng		
	*
	*/
	virtual t_int32 getSequence(t_uint32 &sequence);


	/** 
	*
	* 	func name:		setSession
	*	@brief:		����session
	*	@param:		void
	*	@param:		void
	*	@return:	����
	*	@author:	zhang_xusheng		
	*
	*/
	virtual t_int32 setSession(const t_uint32 session);
	
	/** 
	*
	* 	func name:		getSession
	*	@brief:		����session
	*	@param:		void
	*	@param:		void
	*	@return:	����
	*	@author:	zhang_xusheng		
	*
	*/
	virtual t_int32 getSession(t_uint32 &sequence);
	/** 
	*
	* 	func name:		getFromAddr
	*	@brief:		��ȡFrom�ĵ�ַ
	*	@param:		void
	*	@param:		void
	*	@return:	��ַ
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getFromAddr();
	/** 
	*
	* 	func name:		getFromPort
	*	@brief:		��ȡFrom�Ķ˿�
	*	@param:		void
	*	@param:		void
	*	@return:	�˿�
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_uint16 getFromPort();

	/** 
	*
	* 	func name:		setToCode
	*	@brief:		����To������
	*	@param:		code �����ַ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setToCode(t_int8 *code);

	/** 
	*
	* 	func name:		setToAddr
	*	@brief:		����To�ĵ�ַ
	*	@param:		addr ��ַ�ַ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setToAddr(t_int8 *addr);
	/** 
	*
	* 	func name:		setToPort
	*	@brief:		����To�Ķ˿�
	*	@param:		port �˿�
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setToPort(t_uint16 port);

	/** 
	*
	* 	func name:		getToCode
	*	@brief:		��ȡTo������
	*	@param:		void
	*	@param:		void
	*	@return:	����
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getToCode();
	/** 
	*
	* 	func name:		getToAddr
	*	@brief:		��ȡTo�ĵ�ַ
	*	@param:		void
	*	@param:		void
	*	@return:	��ַ
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getToAddr();
	/** 
	*
	* 	func name:		getToPort
	*	@brief:		��ȡTo�ĵ�ַ
	*	@param:		void
	*	@param:		void
	*	@return:	�˿�
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_uint16 getToPort();

	/** 
	*
	* 	func name:		setProxyCode
	*	@brief:		����Proxy������
	*	@param:		code �����ַ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setProxyCode(t_int8 *code);
	/** 
	*
	* 	func name:		setProxyAddr
	*	@brief:		����Proxy�ĵ�ַ
	*	@param:		addr ��ַ�ַ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setProxyAddr(t_int8 *addr);
	/** 
	*
	* 	func name:		setProxyPort
	*	@brief:		����Proxy�Ķ˿�
	*	@param:		port �˿�
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setProxyPort(t_uint16 port);
	/** 
	*
	* 	func name:		getProxyCode
	*	@brief:		��ȡProxy������
	*	@param:		void
	*	@param:		void
	*	@return:	����
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getProxyCode();
	/** 
	*
	* 	func name:		getProxyAddr
	*	@brief:		��ȡProxy�ĵ�ַ
	*	@param:		void
	*	@param:		void
	*	@return:	��ַ
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getProxyAddr();
	/** 
	*
	* 	func name:		getProxyPort
	*	@brief:		��ȡProxy�Ķ˿�
	*	@param:		void
	*	@param:		void
	*	@return:	�˿�
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_uint16 getProxyPort();

	/** 
	*
	* 	func name:		setContactCode
	*	@brief:		����Contact������
	*	@param:		code �����ַ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setContactCode(t_int8 *code);
	/** 
	*
	* 	func name:		setContactAddr
	*	@brief:		����Contact�ĵ�ַ
	*	@param:		code ��ַ�ַ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setContactAddr(t_int8 *addr);
	/** 
	*
	* 	func name:		setContactPort
	*	@brief:		����Contact�Ķ˿�
	*	@param:		port �˿�
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setContactPort(t_uint16 port);

	/** 
	*
	* 	func name:		getContactCode
	*	@brief:		��ȡContact������
	*	@param:		void
	*	@param:		void
	*	@return:	����
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getContactCode();
	/** 
	*
	* 	func name:		getContactAddr
	*	@brief:		��ȡContact�ĵ�ַ
	*	@param:		void
	*	@param:		void
	*	@return:	��ַ
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getContactAddr();
	/** 
	*
	* 	func name:		getContactPort
	*	@brief:		��ȡContact�Ķ˿�
	*	@param:		void
	*	@param:		void
	*	@return:	�˿�
	*	@author:	zhang_sunbo
	*	@note:	��ʽ���� "sip:code@addr:port"		
	*
	*/
	virtual t_uint16 getContactPort();

	/** 
	*
	* 	func name:		getBodyType
	*	@brief:		��ȡBody����
	*	@param:		void
	*	@param:		void
	*	@return:	Body�����ַ���,����μ�����ʵ�ֶ���
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_int8 *getBodyType();

	/** 
	*
	* 	func name:		getBodyType
	*	@brief:		����Body����
	*	@param:		bodyType body�����ַ���,����μ�����ʵ�ֶ���
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_int32 setBodyType(t_int8 *bodyType);

	/** 
	*
	* 	func name:		getBody
	*	@brief:		��ȡbody����
	*	@param:		bodyLen ���body����
	*	@param:		void
	*	@return:	body����
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_int8 *getBody(t_int32 &bodyLen);

	/** 
	*
	* 	func name:		setBody
	*	@brief:		����body����
	*	@param:		body body����
	*	@param:		bodyLen body����
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_int32 setBody(t_int8 *body, t_int32 bodyLen);

	/** 
	*
	* 	func name:		getSuccess
	*	@brief:		��ȡ����״̬
	*	@param:		void
	*	@param:		void
	*	@return:	(1-�ɹ�)��(0-ʧ��)
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_bool getSuccess();

	/** 
	*
	* 	func name:		getSuccess
	*	@brief:		���ð���״̬
	*	@param:		bSuccess 
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_int32 setSuccess(t_bool bSuccess);


	virtual t_int32 getPacketType();

	virtual t_int32 setPacketType(t_int32 reqOrRes);

	virtual t_int32 getTransId();
	virtual t_int32 setTransId(t_int32 transId);
	virtual t_int32 getDialogId();
	virtual t_int32 setDialogId(t_int32 dialogId);
	virtual t_int32 getCallId();
	virtual t_int32 setCallId(t_int32 callId);

	virtual t_int32 getStatusCode();
	virtual t_int32 setStatusCode(t_int32 statusCode);


};

typedef smartPtrImpl<prtlPacketI> smartPrtlPacketI;



#endif
