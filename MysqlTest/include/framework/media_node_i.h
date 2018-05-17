
#ifndef MEDIANODE_I_H
#define MEDIANODE_I_H
#include <framework_i.h>
#include <media_socket_i.h>
#include <media_parser_i.h>
#include <media_fifobuffer_i.h>

class mediaUnitI;
typedef enum
{
	MEDIA_NODE_CLOSE,
	MEDIA_NODE_OPEN,
	MEDIA_NODE_CONNECTED,
}mediaNodeStatus;

class mediaNodeI: public socketCbI
{
public:
	mediaNodeI();
	virtual ~mediaNodeI();

public:

	/** 
	* 	func name:	open
	*	@brief:		打开一条连接
	*	@param:		remoteIp:remotePort远程地址，localIp:localPort本地地址，type：socket类型
	*	@return:	E_OK：函数执行成功；E_FAIL:函数执行失败
	*	@author:	zhang_xusheng
	*	@note:		传输类型默认采用UDP连接
	*
	*/
	virtual t_int32 open(t_int8 *remoteIp, t_uint16 remotePort, t_int8 *localIp, t_uint16 localPort, enumMediaSocket type = TRANS_UDP_CONNECT);
	virtual t_int32 open(t_int8* localIp, t_uint16 localPort, enumMediaSocket type = TRANS_UDP_LISTEN);

	/** 
	* 	func name:	connectTo
	*	@brief:		发起一条连接
	*	@param:		remoteIp:remotePort远程地址，localIp:localPort本地地址，type：socket类型
	*	@return:	E_OK：函数执行成功；E_FAIL:函数执行失败
	*	@author:	zhang_xusheng
	*	@note:		传输类型默认采用UDP连接
	*
	*/
	virtual t_int32 connectTo(t_int8* remoteIp, t_uint16 remotePort);//当mediaNode为UDP监听端时可用，用于主动向目标对端发起连接
	virtual t_int32 close(t_handler peer);//当mediaNode为UDP监听端时可用，与connectTo配对使用

	virtual t_int32 close();//关闭mediaNode平台
	virtual t_int32 setCallback(mediaCbI* callback, void* callbackArg);	//设置mediaNode的回调函数

public:
	//mediaNode发送数据，send()函数用于向对端发送
	virtual t_int32 send(t_int8* buffer, t_int32 buffLen);
	virtual t_int32 send(mediaRawPacketI* packet);
	virtual t_int32 send(mediaPacketI* packet);

public:	
	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg);//当mediaNode收到数据时通过onData回调给上层用户
	virtual t_int32 onConnect(t_handler handlerId, void *arg);//当mediaNode连接建立完成后通过onConnect通知上层用户
	virtual t_int32 onConnect(t_handler handlerId, t_handler peer, t_int8* remoteIp, t_uint16 remotePort);//当mediaNode监听建立完成后通过该接口通知上层用户
	virtual t_int32 onDisconnect(t_handler handlerId, void* arg);//当mediaNode断开连接时通过onDisconnect通知上层用户

public:
	t_int32 onOpenFailed(t_handler handerId);
	t_int32 onCloseFailed(t_handler handerId);

public:
	virtual t_int32 createParser(mediaParserI* parser);//创建用于流媒体协议解析的解析器
	virtual t_int32 createParserInstance(t_int8* dllPath);
	virtual mediaParserI* getParser();

public:
	virtual t_int8*		getRemoteIp();	//获取远程连接的IP地址
	virtual t_uint16	getRemotePort();//获取远程连接的端口号	
	virtual t_int8*		getLocalIp();	//获取本地连接的IP地址
	virtual t_uint16	getLocalPort();	//获取本地连接的端口号
	mediaNodeStatus getNodeStatus();	//获取当前mediaNode的状态
	void* getPeerStream();				//当mediaNode为peerStream类型时专用

public:
	t_int32		setSwitchList(mediaUnitI* group);//设置当前结点所处的组
	mediaUnitI*	getSwitchList();//获取当前结点所处的组别

public:
	//下面接口用于多线程模块使用
	t_int32 threadOpen();
	t_int32 threadClose();
	t_int32 setThreadId(t_int32 threadId);
	t_int32 getThreadId();

private:
	mediaNodeStatus		m_status;			//mediaNode状态
	mutexI				m_statusLock;		//

private:
	enumMediaSocket		m_socketType;		//mediaNode的连接类型
	mediaSocketI*		m_connect;			//mediaNode的连接指针
	mediaSocketI*		m_exconnect;		//mediaNode的连接指针，用于RTCP协议连接
	mediaCbI*			m_callback;			//mediaNode的回调指针
	void*				m_args;				//mediaNode的回调参数

	t_int8				m_rIp[sizeof("255.255.255.255")];
	t_uint16			m_rPort;
	t_int8				m_lIp[sizeof("255.255.255.255")];
	t_uint16			m_lPort;

private:
	mediaFIFOBuffer		m_buffer;
private:
	mediaParserI*		m_parser;
	mediaUnitI*			m_switch;
	mutexI				m_switchMutex;

private:
	t_int32				m_threadId;
};

#endif
