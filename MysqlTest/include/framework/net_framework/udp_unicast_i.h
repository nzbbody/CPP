

#ifndef _UDP_UNICAST_I_H
#define _UDP_UNICAST_I_H


#include <data_types.h>
#include <net_framework/inet_addr_i.h>
#include <net_framework/socket_stream_i.h>
#include <event_handler_i.h>
#include <event_timer_i.h>
#include <auto_buffer_i.h>
#include <event_notify_i.h>
#include <mutex_i.h>

typedef struct
{
	t_int8		ip[sizeof("255.255.255.255")];
	t_uint16	port;
	t_uint16	online;		//0:using 1:unusing
	t_int32		socket;
	t_uint16	id;
}udp_client_list;

typedef struct  
{
	unsigned int id;
	smartAutoBufferI sab;
}dataRow;

typedef enum
{
	UDP_LISTEN_SEND_NORMAL,	//直接发送方式
	UDP_LISTEN_SEND_DEFAULT,	//默认的智能指针发送方式
	UDP_LISTEN_SEND_CALLBACK,	//回调给上层，上层发送；注意如果采用该发送方式，默认的智能指针发送方式无效

}UDP_LISTEN_SEND_TYPE;

#ifdef WIN32
typedef stdext::hash_map<unsigned long, udp_client_list*> udpClientList;
#else
#include <ext/hash_map>
typedef __gnu_cxx::hash_map<unsigned long, udp_client_list*> udpClientList;
#endif

class DLL_EXPORT udpUnicastI :public eventHandlerI
{
public:
	udpUnicastI();
	virtual ~udpUnicastI();
public:
	/** 
	*
	* 	func name	:		open
	*	@brief		:	    开启udp连接
	*	@param		:		remoteIp: 远程IP地址，remotePort:远程端口
	*	@param		:		localIp:  本地Ip地址，localPort:本地端口
	*	@return		:		E_OK：开启udp连接成功，E_FAIL：开启udp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 open(t_int8 *localIp = NULL, t_uint16 localPort = 0);
	
	/** 
	*
	* 	func name	:		close
	*	@brief		:	    关闭udp连接
	*	@return		:		E_OK：关闭udp连接成功，E_FAIL：关闭udp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 close(void);

	/** 
	*
	* 	func name	:		peerAdd
	*	@brief		:		udpUnicast端增加一条连接
	*	@return		:		E_OK：添加udp连接成功，E_FAIL：添加udp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 peerAdd(t_int8* remoteIp, t_uint16 remotePort);
	
	/** 
	*
	* 	func name	:		disConnect
	*	@brief		:		udpUnicast端断开一条连接
	*	@return		:		E_OK：关闭udp连接成功，E_FAIL：关闭udp连接失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 disConnect(t_handler peerId);
	
public:
	/** 
	*
	* 	func name	:		send
	*	@brief		:	    udp连接发送数据
	*	@return		:		
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 send(t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int8 *remoteIp, t_uint16 remotePort, t_int32 &sended);
	t_int32 send(t_handler peerId, smartAutoBufferI& sab);


	/** 
	*
	* 	func name	:		getLocalIp
	*	@brief		:	    获取本地Ip地址
	*	@return		:		本地Ip地址字符串
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getLocalIp();
	/** 
	*
	* 	func name	:		getLocalPort
	*	@brief		:	    获取本地端口
	*	@return		:		本地端口
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getLocalPort();
	/** 
	*
	* 	func name	:		getRemoteIp
	*	@brief		:	    获取远程Ip地址
	*	@return		:		远程Ip地址字符串
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int8 *getRemoteIp(t_handler peerId);
	/** 
	*
	* 	func name	:		getRemotePort
	*	@brief		:		获取远程端口
	*	@return		:		远程端口号
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_uint16 getRemotePort(t_handler peerId);
public:
	/** 
	*
	* 	func name	:		setCallback
	*	@brief		:	    为udp连接设置回调函数
	*	@return		:		E_OK：回调函数设置成功，E_FIAL:回调函数设置失败
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 setCallback(socketCbI *callback, void *arg);


	static t_int32 eventSendNotifyFunc(void *arg);
	
public:

	//使能UDP listen的可写回调
	t_int32 enableOutput();

	//关闭UDP listen的可写回调
	t_int32 disableOutput();

public:
	virtual iohandle_t getHandle();
	virtual t_int32 setHandle(iohandle_t handle);


	virtual t_int32 handleInput(iohandle_t handle);
	virtual t_int32 handleOutput(iohandle_t handle);
	virtual t_int32 handleInputTimeout(iohandle_t handle);
	virtual t_int32 handleOutputTimeout(iohandle_t handle);
	virtual t_int32 handleException(iohandle_t handle);
private:
	t_int32 openInside();
	t_int32 complete();
	t_int32 connect(t_int8* ip, t_uint16 port, t_handler &peer);
	t_int32 getClientId();

private:
	socketStreamI	socketStream;

	socketCbI		*connectCb;						//回调函数指针
	void			*connectCbArg;					//回调函数参数指针
	
	UDP_LISTEN_SEND_TYPE m_sendType;				//UDPlisten设置的发送方式

	sockaddr_t		_laddr;							//本地地址

	t_int8			_localIp[sizeof("255.255.255.255")];		
	t_uint16		_localPort;

	udpClientList	m_client;						//远程客户端管理
	mutexI			m_clientMutex;
	t_uint32		m_clientId;

	t_bool			bBind;							//是否绑定标志

	mutexI			m_sendMutex;
	autoBufferDataQueue m_abiDataQueue;

	eventNotifyI	m_eventSendNotify;

};


#endif


