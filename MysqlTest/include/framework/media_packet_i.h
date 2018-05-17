#ifndef MEDIA_PACKET_I_H
#define MEDIA_PACKET_I_H
#include <framework_i.h>

#define STREAMLOG	"streamlog"

#define PACKET_MAX_SIZE		(8*1024)
#define BUFFER_SIZE			(64*1024*2)
enum PayloadTypes 
{
	PCMU,         // G.711 u-Law
	FS1016,       // Federal Standard 1016 CELP
	G721,         // ADPCM - Subsumed by G.726
	G726 = G721,
	GSM,          // GSM 06.10
	G7231,        // G.723.1 at 6.3kbps or 5.3 kbps
	DVI4_8k,      // DVI4 at 8kHz sample rate
	DVI4_16k,     // DVI4 at 16kHz sample rate
	LPC,          // LPC-10 Linear Predictive CELP
	PCMA,         // G.711 A-Law
	G722,         // G.722
	L16_Stereo,   // 16 bit linear PCM
	L16_Mono,     // 16 bit linear PCM
	G723,         // G.723
	CN,           // Confort Noise
	MPA,          // MPEG1 or MPEG2 audio
	G728,         // G.728 16kbps CELP
	DVI4_11k,     // DVI4 at 11kHz sample rate
	DVI4_22k,     // DVI4 at 22kHz sample rate
	G729,         // G.729 8kbps
	Cisco_CN,     // Cisco systems comfort noise (unofficial)

	CelB = 25,    // Sun Systems Cell-B video
	JPEG,         // Motion JPEG
	H261 = 31,    // H.261
	MPV,          // MPEG1 or MPEG2 video
	MP2T,         // MPEG2 transport system
	H263,         // H.263

	LastKnownPayloadType,

	DynamicBase = 96,
	DynamicVideo = DynamicBase,
	DynamicAudio = 97,

	MaxPayloadType = 127,
	Tunnel = 128,	//穿网打洞包，无实际意义
	IllegalPayloadType
};

class mediaRawPacketI
{
public:
	mediaRawPacketI();
	virtual ~mediaRawPacketI();

public:
	virtual t_int8* getBuff();
	virtual t_int32 getBuffLen();

public:
	t_int8	m_buff[PACKET_MAX_SIZE];
	t_int32 m_buffLen;
};
class DLL_EXPORT mediaPacketI
{
public:
	mediaPacketI();
	virtual ~mediaPacketI();

public:

	//设置、获取负载类型
	virtual PayloadTypes getPayloadType();
	virtual void		setPayloadType(PayloadTypes t);

	//设置、获取序列号
	virtual t_uint16	getSequenceNumber();
	virtual void		setSequenceNumber(t_uint16 seqNum);

	//设置、获取时间戳
	virtual t_uint32	getTimestamp();
	virtual void		setTimestatmp(t_uint32 time);

	//增加负载数据，add: 从起始位置增加;append: 从原有数据末尾增加
	virtual t_int32		addPayload(t_int8* data, t_int32 len);
	virtual t_int32		appendPayload(t_int8* data, t_int32 len);

	//读取负载数据和长度
	virtual t_int8*		readPayload(t_int32& len);
	virtual t_int32		getPayloadLen(void);

	//拷贝
	virtual t_int32		copy(mediaPacketI* packet);
	virtual t_int32		setBuffer(t_int8* data, t_int32 len);

	//获取原始数据
	virtual t_int8*		getBuff();
	virtual t_int32		getBuffLen();
	
public:
	t_int8	m_buffer[BUFFER_SIZE];
	t_int32 m_buffLen;
};


#endif
