#ifndef _MEDIA_PARSE_I_H
#define _MEDIA_PARSE_I_H
#include <data_types.h>
#include <trace/trace_i.h>
#include <media_socket_i.h>
#include <media_packet_i.h>

#define HALF_PACKET -2		//��ذ��Ĵ�����

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
	//virtual t_int32 onData(t_handler handlerId, t_handler peer, mediaPacketI * packet, void *arg);//�ýӿ���ʱ����
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
	*	@brief:		��������յ��������ݰ���ʱ������ݰ����н���
	*	@return:	E_OK: �����ɹ���E_FAIL:����ʧ��
	*	@author:	zhang_xusheng
	*	@note:		modified on 2013-4-24
	*
	*/
	virtual t_int32 parse(const t_int8* buff, const t_int32 buffLen, mediaPacketI* &packet, enumMediaSocket peerType);
	virtual t_int32 parse(mediaRawPacketI* rawPacket, mediaPacketI* packet);

	virtual t_int32 exparse(const t_int8* buff, const t_int32 buffLen);

	/** 
	* 	func name:	buildPacket
	*	@brief:		�齨��
	*	@return:	E_OK: �齨�ɹ���E_FAIL:�齨ʧ��
	*	@author:	zhang_xusheng
	*	@note:		modified on 2013-4-24
	*
	*/
	virtual t_int32 buildPacket(const t_int8* buff, t_int32 buffLen, mediaRawPacketI* packet);
	virtual t_int32 buildPacket(const t_int8* buff, t_int32 buffLen, mediaRawPacketI* packet, enumMediaSocket transType);

public:
	/** 
	* 	func name:	setExconnect
	*	@brief:		������չ��������
	*	@return:	E_OK: ���óɹ���E_FAIL:����ʧ��
	*	@author:	zhang_xusheng
	*	@note:		exConnectToPort = ������Զ�̶˿ڵ�ƫ����;��������Զ�̶˿� = ������Զ�̶˿� + exConnectToPort��
	*	@note:		exConnectPort = �����ӱ��ض˿ڵ�ƫ����;�������ӱ��ض˿� = �����ӱ��ض˿� + exConnectPort��
	*	@note:		modified on 2014-4-24
	*
	*/
	t_int32 setExconnect(t_uint16 exConnectToPort, t_uint16 exConnectPort);

	/** 
	* 	func name:	setCallback
	*	@brief:		���ûỰ�Ļص�����
	*	@return:	E_OK: ���óɹ���E_FAIL:����ʧ��
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
