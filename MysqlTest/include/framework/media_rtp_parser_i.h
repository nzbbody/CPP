#ifndef MEDIA_RTP_PARSER_I_H
#define MEDIA_RTP_PARSER_I_H
#include <media_parser_i.h>
#include <media_packet_i.h>
#include "media_rtp_param_i.h"
#include "media_rtp_packet_i.h"
#include "rtp_fifobuffer_i.h"

#define RTP_MIN_SIZE	12
#define RTP_HEAD_SIZE	12
#define RTPBUFFER_SIZE	65535*2

#define RTP_TTL			5			//RTP会话超时时间
#define RTP_EXTENSION_PACKET_LENGTH 1


class DLL_EXPORT mediaRTPParserI : public mediaParserI
{
public:
	mediaRTPParserI();
	mediaRTPParserI(mediaRole role);
	virtual ~mediaRTPParserI();

public:

	virtual t_int32 parse(const t_int8* buff, const t_int32 buffLen, mediaPacketI* &packet, enumMediaSocket peerType);
	virtual t_int32 parse(mediaRawPacketI* rawPacket, mediaPacketI* packet);
	virtual t_int32 exparse(const t_int8* buff, const t_int32 buffLen);

	virtual t_int32 buildPacket(const t_int8 *buff, t_int32 buffLen, mediaRawPacketI* packet);
	virtual t_int32 buildPacket(const t_int8 *buff, t_int32 buffLen, mediaRawPacketI* packet, enumMediaSocket transType);

public:
	t_int32 buildRTPCPacket(mediaRTCPPacketI* rtcpPacket);

public:
	t_int32 sendSRPackets();
	t_int32 sendRRPackets();

public:
	virtual t_int32 heartbeat();

public:
	t_int32 setRTPTTL(t_int32 RTPTTL);	//设置RTP超时时间，单位毫秒(ms)
	t_int32 setSSRC(t_uint32 ssrc);		//设置RTP会话的源描述符——SSRC
	t_uint32 getSSRC();					//获取RTP会话的源描述符——SSRC

	t_int32 setPayloadType(PayloadTypes);	//设置负载类型
	t_uint8 getPayloadType();	//获取负载类型

private:
	t_int32		m_connectTTL;		//上层设置的生命计数
	t_int32		m_realTTL;			//实际生命计数
	t_uint64	m_rtcpTime;
	t_uint32	m_ssrc;
	t_uint32	m_rtcp_snd_packet;
	t_uint32	m_rtcp_snd_octet;
	t_uint32	m_timestamp;
	t_uint32	m_rtcp_rec_fraction_lost;
	t_uint32	m_rtcp_rec_packet_lost;
	t_uint32	m_rtcp_hight_sequence;

	t_int32		m_id;

private:	
	mediaRtpParamI m_param;
	listI<mediaRawPacketI *> m_packet_list;

private:
	t_int32 m_totalPacketNum;
	t_int32 m_totalBuffSize;

private:
	t_int8	m_buffer[RTPBUFFER_SIZE];
	t_int32 m_buffLen;
	t_int32 m_leftLen;
};

#ifdef __cplusplus
extern "C"{
#endif

DLL_EXPORT mediaParserI* createParser();

#ifdef __cplusplus
}
#endif

#endif
