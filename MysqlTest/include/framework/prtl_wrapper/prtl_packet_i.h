/**
*	Copyright (C) 2013 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			prtl_packet_i.h
* 	@brief:			prtl_packet_i.h定义了协议包类, 完成协议包的组合和提取；
* 	@author:			zhang_sunbo 
*	@note:	
*/

#ifndef _PRTL_PACKET_I_H
#define _PRTL_PACKET_I_H


#include <framework_i.h>

/** 
*
*	class:		prtlPacketI
* 	@brief:		prtlPacketI协议包基类,定义协议包处理的基本接口	
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
	*	@brief:		获取协议名称
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
	*	@brief:		获取版本号
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
	*	@brief:		设置协议命令
	*	@param:		method 方法名,具体参见子类实现定义
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
	*	@brief:		设置协议命令
	*	@param:		method 方法名,具体参见子类实现定义
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
	*	@brief:		获取协议命令
	*	@param:		method 方法名,具体参见子类实现定义
	*	@param:		void
	*	@return:	返回方法
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/

	virtual t_int32 getMethod(stringI &command);
	/** 
	*
	* 	func name:		getMethod
	*	@brief:		获取协议命令
	*	@param:		method 方法名,具体参见子类实现定义
	*	@param:		void
	*	@return:	返回方法
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/

	virtual t_int32 getMethod();
	/** 
	*
	* 	func name:		getModule
	*	@brief:		获取模块名
	*	@param:		module 模块名,具体参见子类实现定义
	*	@param:		void
	*	@return:	返回方法
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/

	virtual t_int32 getModule(stringI &module);

	/** 
	*
	* 	func name:		setModule
	*	@brief:		设置模块名
	*	@param:		module 模块名,具体参见子类实现定义
	*	@param:		void
	*	@return:	返回方法
	*	@author:	zhang_xusheng
	*	@note:			
	*
	*/

	virtual t_int32 setModule(t_int8 *module);

	/** 
	*
	* 	func name:		setExpires
	*	@brief:		设置过期时间
	*	@param:		expires 过期时间-秒
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
	*	@brief:		获取过期时间
	*	@param:		expires 过期时间-秒
	*	@param:		void
	*	@return:	返回过期时间
	*	@author:	zhang_sunbo
	*	@note:			
	*
	*/
	virtual t_int32 getExpires();


	/** 
	*
	* 	func name:		setFromCode
	*	@brief:		设置From的名称
	*	@param:		code 名称字符串
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setFromCode(t_int8 *code);

	/** 
	*
	* 	func name:		setFromAddr
	*	@brief:		设置From的地址
	*	@param:		addr 地址字符串
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setFromAddr(t_int8 *addr);
	/** 
	*
	* 	func name:		setFromPort
	*	@brief:		设置From的端口
	*	@param:		port 端口
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setFromPort(t_uint16 port);
	/** 
	*
	* 	func name:		getFromCode
	*	@brief:		获取From的名称
	*	@param:		void
	*	@param:		void
	*	@return:	名称
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getFromCode();
	/** 
	*
	* 	func name:		setSequence
	*	@brief:		设置序列号
	*	@param:		void
	*	@param:		void
	*	@return:	名称
	*	@author:	zhang_xusheng		
	*
	*/
	virtual t_int32 setSequence(t_uint32 sequence);
	/** 
	*
	* 	func name:		getSequence
	*	@brief:		设置序列号
	*	@param:		void
	*	@param:		void
	*	@return:	名称
	*	@author:	zhang_xusheng		
	*
	*/
	virtual t_int32 getSequence(t_uint32 &sequence);


	/** 
	*
	* 	func name:		setSession
	*	@brief:		设置session
	*	@param:		void
	*	@param:		void
	*	@return:	名称
	*	@author:	zhang_xusheng		
	*
	*/
	virtual t_int32 setSession(const t_uint32 session);
	
	/** 
	*
	* 	func name:		getSession
	*	@brief:		设置session
	*	@param:		void
	*	@param:		void
	*	@return:	名称
	*	@author:	zhang_xusheng		
	*
	*/
	virtual t_int32 getSession(t_uint32 &sequence);
	/** 
	*
	* 	func name:		getFromAddr
	*	@brief:		获取From的地址
	*	@param:		void
	*	@param:		void
	*	@return:	地址
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getFromAddr();
	/** 
	*
	* 	func name:		getFromPort
	*	@brief:		获取From的端口
	*	@param:		void
	*	@param:		void
	*	@return:	端口
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_uint16 getFromPort();

	/** 
	*
	* 	func name:		setToCode
	*	@brief:		设置To的名称
	*	@param:		code 名称字符串
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setToCode(t_int8 *code);

	/** 
	*
	* 	func name:		setToAddr
	*	@brief:		设置To的地址
	*	@param:		addr 地址字符串
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setToAddr(t_int8 *addr);
	/** 
	*
	* 	func name:		setToPort
	*	@brief:		设置To的端口
	*	@param:		port 端口
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setToPort(t_uint16 port);

	/** 
	*
	* 	func name:		getToCode
	*	@brief:		获取To的名称
	*	@param:		void
	*	@param:		void
	*	@return:	名称
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getToCode();
	/** 
	*
	* 	func name:		getToAddr
	*	@brief:		获取To的地址
	*	@param:		void
	*	@param:		void
	*	@return:	地址
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getToAddr();
	/** 
	*
	* 	func name:		getToPort
	*	@brief:		获取To的地址
	*	@param:		void
	*	@param:		void
	*	@return:	端口
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_uint16 getToPort();

	/** 
	*
	* 	func name:		setProxyCode
	*	@brief:		设置Proxy的名称
	*	@param:		code 名称字符串
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setProxyCode(t_int8 *code);
	/** 
	*
	* 	func name:		setProxyAddr
	*	@brief:		设置Proxy的地址
	*	@param:		addr 地址字符串
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setProxyAddr(t_int8 *addr);
	/** 
	*
	* 	func name:		setProxyPort
	*	@brief:		设置Proxy的端口
	*	@param:		port 端口
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setProxyPort(t_uint16 port);
	/** 
	*
	* 	func name:		getProxyCode
	*	@brief:		获取Proxy的名称
	*	@param:		void
	*	@param:		void
	*	@return:	名称
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getProxyCode();
	/** 
	*
	* 	func name:		getProxyAddr
	*	@brief:		获取Proxy的地址
	*	@param:		void
	*	@param:		void
	*	@return:	地址
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getProxyAddr();
	/** 
	*
	* 	func name:		getProxyPort
	*	@brief:		获取Proxy的端口
	*	@param:		void
	*	@param:		void
	*	@return:	端口
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_uint16 getProxyPort();

	/** 
	*
	* 	func name:		setContactCode
	*	@brief:		设置Contact的名称
	*	@param:		code 名称字符串
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setContactCode(t_int8 *code);
	/** 
	*
	* 	func name:		setContactAddr
	*	@brief:		设置Contact的地址
	*	@param:		code 地址字符串
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setContactAddr(t_int8 *addr);
	/** 
	*
	* 	func name:		setContactPort
	*	@brief:		设置Contact的端口
	*	@param:		port 端口
	*	@param:		void
	*	@return:	void
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int32 setContactPort(t_uint16 port);

	/** 
	*
	* 	func name:		getContactCode
	*	@brief:		获取Contact的名称
	*	@param:		void
	*	@param:		void
	*	@return:	名称
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getContactCode();
	/** 
	*
	* 	func name:		getContactAddr
	*	@brief:		获取Contact的地址
	*	@param:		void
	*	@param:		void
	*	@return:	地址
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_int8 *getContactAddr();
	/** 
	*
	* 	func name:		getContactPort
	*	@brief:		获取Contact的端口
	*	@param:		void
	*	@param:		void
	*	@return:	端口
	*	@author:	zhang_sunbo
	*	@note:	格式定义 "sip:code@addr:port"		
	*
	*/
	virtual t_uint16 getContactPort();

	/** 
	*
	* 	func name:		getBodyType
	*	@brief:		获取Body类型
	*	@param:		void
	*	@param:		void
	*	@return:	Body类型字符串,具体参见子类实现定义
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_int8 *getBodyType();

	/** 
	*
	* 	func name:		getBodyType
	*	@brief:		设置Body类型
	*	@param:		bodyType body类型字符串,具体参见子类实现定义
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
	*	@brief:		获取body内容
	*	@param:		bodyLen 输出body长度
	*	@param:		void
	*	@return:	body内容
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_int8 *getBody(t_int32 &bodyLen);

	/** 
	*
	* 	func name:		setBody
	*	@brief:		设置body内容
	*	@param:		body body内容
	*	@param:		bodyLen body长度
	*	@return:	
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_int32 setBody(t_int8 *body, t_int32 bodyLen);

	/** 
	*
	* 	func name:		getSuccess
	*	@brief:		获取包的状态
	*	@param:		void
	*	@param:		void
	*	@return:	(1-成功)或(0-失败)
	*	@author:	zhang_sunbo
	*	@note:		
	*
	*/
	virtual t_bool getSuccess();

	/** 
	*
	* 	func name:		getSuccess
	*	@brief:		设置包的状态
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
