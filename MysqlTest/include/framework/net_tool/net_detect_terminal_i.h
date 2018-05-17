

/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file:			net_detect_terminal_i.h
* 	@brief:			net_detect_terminal_i.h定义网络探测终端；主要功能是：
*											（1）连接网络探测器；
											（2）向网络探测器注册探测目标；
											（3）接收网络探测器的探测结果；
* 	@author:		zhang_xusheng
*	@date：			2015-1-6
*	@note:	
*/

#ifndef NET_DETECT_TERMINAL_I_H_
#define NET_DETECT_TERMINAL_I_H_

#include <data_types.h>
#include <net_framework/socket_i.h>
#include <net_framework/tcp_connect_i.h>


enum NETSTATUS
{
	NET_UNKOWN = 0,	//网络状态未知
	NET_GREEN,	//网络状态良好
	NET_YELLOW,		//网络有延时
	NET_RED,		//网络延时严重
	NET_BLACK,		//网络带宽已满
	NET_DISCONNECT,	//网络断线
};

typedef struct
{
	t_int8 dstIp[sizeof("255.255.255.255")];
	t_int32 netStatus;
}netStatusNotify;

/** 
*
*	class:		netStatusCbI
* 	@brief:		netStatusCbI定义了网络状态探测的回调函数，当网络探测终端收到网络状态信息时，通过该回调函数回调给上层	
* 	@author:	zhang_xusheng
*	@date:		2015-1-6
*	@note:	
*/
class DLL_EXPORT NetStatusCbI
{
public:
	NetStatusCbI();
	virtual ~NetStatusCbI();

public:
	virtual t_int32 onNetStatus(t_int8* dstIp, NETSTATUS netStatus, void* args);

};

/** 
*
*	class:		dhNetDetectTerminal
* 	@brief:		dhNetDetectTerminal定义了网络探测终端
* 	@author:	zhang_xusheng
*	@date:		2015-1-6
*	@note:	
*/
class DLL_EXPORT DhNetDetectTerminalI : public socketCbI
{
public:
	DhNetDetectTerminalI();
	virtual ~DhNetDetectTerminalI();

public:
	
	/** 
	* 	func name	:		onConnect
	*	@brief		:	    探测终端连接成功的回调信息
	*	@param		：		handlerId:连接句柄
	*	@return		:		
	*	@author		:	    zhang_xusheng
	*	@note		:		系统回调接口，用户无需主动调用
	*/
	virtual t_int32 onConnect(t_handler handlerId, void *arg);

	/** 
	* 	func name	:		onData
	*	@brief		:	    探测终端接收数据的回调接口，当收到信息后，底层调用该接口通知上层
	*	@param		：		handlerId:连接句柄；buff：收到的数据；buffLen:数据长度
	*	@return		:		
	*	@author		:	    zhang_xusheng
	*	@note		:		系统回调接口，用户无需主动调用
	*/
	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg);

public:

	/** 
	* 	func name	:		start
	*	@brief		:	    启动探测终端
	*	@param		：		void
	*	@return		:		启动探测终端动作执行完成
	*	@author		:	    zhang_xusheng
	*	@note		:		探测终端真正启动时，系统回调onConnect通知上层，此处的返回值为start执行成功与否
	*/
	t_int32 start(void);

	/** 
	* 	func name	:		stop
	*	@brief		:	    关闭探测终端
	*	@param		：		void
	*	@return		:		E_OK：探测终端关闭成功；E_FAIL：探测终端关闭失败，错误码从errCode::lastError()获取
	*	@author		:	    zhang_xusheng
	*	@note		:		关闭动作属于同步，返回值直接表示关闭结果
	*/
	t_int32 stop(void);

	/** 
	* 	func name	:		setCallback
	*	@brief		:	    设置探测终端的回调函数，指定当探测终端收到数据后回调的对象
	*	@param		：		callback：回调对象指针；args：回调参数
	*	@return		:		
	*	@author		:	    zhang_xusheng
	*	@note		:		
	*/
	t_int32 setCallback(NetStatusCbI* callback, void* args);

public:

	/** 
	* 	func name	:		registerIp
	*	@brief		:	    向探测主机注册IP
	*	@param		：		dstIp：目标主机
	*	@return		:		E_OK：注册成功，E_FAIL:注册失败
	*	@author		:	    zhang_xusheng
	*	@note		:	
	*/
	t_int32 registerIp(const t_int8* dstIp);
	
	/** 
	* 	func name	:		unRegisterIp
	*	@brief		:	    从探测主机注销IP
	*	@param		：		dstIP：目标主机
	*	@return		:		E_OK：注销成功；E_FAIL：注销失败
	*	@author		:	    zhang_xusheng
	*	@note		:	
	*/
	t_int32 unRegisterIp(const t_int8* dstIp);

private:
	tcpConnectI m_detectTerminal;
	t_int32 m_status;	//当前终端状态，0：未连接；1：已连接

private:
	NetStatusCbI* m_callback;
	void* m_args;
};

#endif
