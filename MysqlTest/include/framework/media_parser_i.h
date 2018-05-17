#ifndef _MEDIA_PARSE_I_H
#define _MEDIA_PARSE_I_H
#include <data_types.h>
#include <trace/trace_i.h>
#include <media_socket_i.h>
#include <media_packet_i.h>

#define HALF_PACKET -2		//半截包的错误码

typedef enum
{
	RTP_PARSER,
	PGSP_PARSER,
}mediaParserType;

typedef enum
{
	MEDIAUNKNOWN,
	MEDIARECEIVER,
	MEDIASENDER,
}mediaRole;

typedef struct streamInfo
{
	t_int32 streamTotalPackets;
	t_int32 streamTotalactets;
}streamInfoI;

class mediaCbI:public socketCbI
{
public:
	mediaCbI();
	~mediaCbI();

public:
	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg)
	{
		(void)handlerId;
		(void)buff;
		(void)buffLen;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onData(t_handler handlerId, t_handler peer, t_int8 *buff, t_int32 buffLen, void *arg)
	{
		(void)handlerId;
		(void)peer;
		(void)buff;
		(void)buffLen;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onData(t_handler handlerId, mediaPacketI* packet, void *arg);
	//virtual t_int32 onData(t_handler handlerId, t_handler peer, mediaPacketI * packet, void *arg);//该接口暂时保留
	virtual t_int32 onControlInfo(t_handler handlerId, streamInfoI* pstreamInfo, void *arg);
	virtual t_int32 onTimeout(t_handler handlerId, void *arg);
	virtual t_int32 onExpection(t_handler handlerId, void *args);
	virtual t_int32 onExpection(t_handler handlerId, t_int32 errorNum, void *arg);
};

class mediaParserI:public socketCbI
{
public:
	mediaParserI();
	mediaParserI(mediaRole role);
	virtual ~mediaParserI();

public:
	virtual t_int32 onConnect(t_handler handlerId, void *arg);
	virtual t_int32 onConnect(t_handler handlerId, t_handler peer, t_int8* remoteIp, t_uint16 remotePort);
	virtual t_int32 onDisconnect(t_handler handlerId, void *arg);
	virtual t_int32 onClose(t_handler handlerId, void *arg);
	virtual t_int32 onExpection(t_handler handlerId, void *arg);
	virtual t_int32 onExpection(t_handler handlerId, t_int32 errorNum, void *arg);

public:

	/** 
	* 	func name:	parse
	*	@brief:		解包，当收到网络数据包的时候对数据包进行解析
	*	@return:	E_OK: 解析成功，E_FAIL:解析失败
	*	@author:	zhang_xusheng
	*	@note:		modified on 2013-4-24
	*
	*/
	virtual t_int32 parse(const t_int8* buff, const t_int32 buffLen, mediaPacketI* &packet, enumMediaSocket peerType);
	virtual t_int32 parse(mediaRawPacketI* rawPacket, mediaPacketI* packet);

	virtual t_int32 exparse(const t_int8* buff, const t_int32 buffLen);

	/** 
	* 	func name:	buildPacket
	*	@brief:		组建包
	*	@return:	E_OK: 组建成功，E_FAIL:组建失败
	*	@author:	zhang_xusheng
	*	@note:		modified on 2013-4-24
	*
	*/
	virtual t_int32 buildPacket(const t_int8* buff, t_int32 buffLen, mediaRawPacketI* packet);
	virtual t_int32 buildPacket(const t_int8* buff, t_int32 buffLen, mediaRawPacketI* packet, enumMediaSocket transType);

public:
	/** 
	* 	func name:	setExconnect
	*	@brief:		设置扩展连接属性
	*	@return:	E_OK: 设置成功，E_FAIL:设置失败
	*	@author:	zhang_xusheng
	*	@note:		exConnectToPort = 主连接远程端口的偏移量;（辅连接远程端口 = 主连接远程端口 + exConnectToPort）
	*	@note:		exConnectPort = 主连接本地端口的偏移量;（辅连接本地端口 = 主连接本地端口 + exConnectPort）
	*	@note:		modified on 2014-4-24
	*
	*/
	t_int32 setExconnect(t_uint16 exConnectToPort, t_uint16 exConnectPort);

	/** 
	* 	func name:	setCallback
	*	@brief:		设置会话的回调函数
	*	@return:	E_OK: 设置成功，E_FAIL:设置失败
	*	@author:	zhang_xusheng
	*	@note:		modified on 2014-4-24
	*
	*/
	t_int32 setCallback(mediaCbI* mediaCallback, void* mediaCallbackargs);

private:
	t_int32 parseInside();

public:
	t_bool		m_exConnectFlag;
	t_uint16	m_exConnectToPort;
	t_uint16	m_exConnectPort;

public:
	t_int32	timerStart();
	t_int32 setTimerInterval(t_int32 timerInterval);
	t_int32 timerStop();
	virtual t_int32 heartbeat();
	
public:
	eventTimerI	m_heartTimer;
	t_int32		m_timerInterval;
	
public:
	mediaSocketI*	m_exconnect;
	mediaCbI*		m_callback;
	void*		m_callbackargs;

public:
	mediaRole	m_role;
};

#endif
