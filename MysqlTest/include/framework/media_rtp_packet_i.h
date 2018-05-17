#ifndef MEDIA_RTP_PACKET_I_H
#define MEDIA_RTP_PACKET_I_H
#include <framework_i.h>
#include <media_packet_i.h>
#include "RTPProtocol.h"
#include "mediaRTPPacketPool.h"

#define		RTP_VERSION							2							//RTP版本号默认为2
#define		RTP_PACKET_MAXSIZE					1460						//RTP最大包长度为32768
#define		RTP_BUFFER_LENGTH					1024*5						//9192

///RTP头 12个字节
struct RTPhead
{
#ifdef RTP_BIG_ENDIAN
	t_uint8 version:2;
	t_uint8 padding:1;
	t_uint8 extension:1;
	t_uint8 csrccount:4;

	t_uint8 marker:1;
	t_uint8 payloadtype:7;
#else 
	t_uint8 csrccount:4;		//同步源个数，仅用于混 合器
	t_uint8 extension:1;
	t_uint8 padding:1;			//填充
	t_uint8 version:2;			//版本标识

	t_uint8 payloadtype:7;		//负载类型
	t_uint8 marker:1;			//标记重要事件
#endif		

	t_uint16 sequencenumber;	//序列号
	t_uint32 timestamp;			//时间戳
	t_uint32 ssrc;				//同步源标识符
};

class DLL_EXPORT mediaRtpPacketI : public mediaPacketI
{
public:
	mediaRtpPacketI();
	mediaRtpPacketI(t_int32 size);
	mediaRtpPacketI(const mediaRtpPacketI& packet);
	mediaRtpPacketI(t_int8* data, t_int32 dataLen);
	virtual ~mediaRtpPacketI();

public:
	void addCSRC(t_int32 csrc);
	
	t_int32 getVersion();
	void	setVersion(t_int32 version);
	
	t_bool	getExtension();
	void	setExtension(t_int32 ext);
	
	t_bool	getMarker();
	void	setMarker(t_bool mark);

	PayloadTypes getPayloadType();
	void	setPayloadType(PayloadTypes t);

	t_uint16 getSequenceNumber();
	void	setSequenceNumber(t_uint16 seqNum);

	t_uint32 getTimestamp();
	void	setTimestatmp(t_uint32 time);

	t_uint32 getSyncSource();
	void	setSyncSource(t_uint32 ssrc);

	t_int32		getContribSrcCount();
	t_uint32	getContribSource(t_int32 index);
	void		setContribSource(int index, t_uint32 csrc);

	t_int32		getHeaderSize();
	t_uint16	getExtensionType();
	void		setExtensionType(t_uint16 type);
	void		setExtensionSize(t_uint16 len);
	t_uint16	getExtensionSize();
	t_int8*		getExtensionPtr();

	t_int32		addPayload(t_int8* data, t_int32 len);
	t_int32		appendPayload(t_int8* data, t_int32 len);

	t_int8* readPayload(t_int32& len);
	t_int32 getPayloadLen(void);

	t_int32 copy(mediaRtpPacketI* packet);
	t_int32 setBuffer(t_int8* data, t_int32 len);
	t_int8* getBufferPtr(void);
	t_int32 getBufferLen(void);

	//下面这两个函数和readPayload的功能一样，只是为了继承接口
	t_int8* getBuff();
	t_int32 getBuffLen();

	t_int32 setPool(mediaRtpPacketPool* pool);

	virtual t_int32 release();

public:
	//解析包时给下列四个值赋值
	t_uint32	m_timeStamp;
	t_uint32	m_ssrc;
	t_uint32	m_seqNum;
	t_int32 m_payloadLen;
	t_int8	m_buffer[RTP_BUFFER_SIZE];
	t_int32 m_buffLen;

	mediaRtpPacketPool* pool;
};

class DLL_EXPORT mediaRTCPPacketI
{
public:
	mediaRTCPPacketI(t_int32 size);
	mediaRTCPPacketI(RTCPTYPE type);
	mediaRTCPPacketI(t_int8* data, t_int32 len);
	virtual ~mediaRTCPPacketI();

public:

	virtual int release();

	t_int32 getVersion();
	void setVersion(t_int32 version);

	t_int32 getPadding();
	void setPadding(t_int32 padding);

	t_int32 getRC();
	void setRC(t_int32 RC);

	RTCPTYPE getPayloadType();
	void setPayloadType(RTCPTYPE payload);

	t_uint16 getLength();
	void setLength(t_uint16 length);

	t_uint32 getSenderSSRC();
	void setSenderSSRC(t_uint32 ssrc);
	//数据体部分。

	//SR和RR使用
	t_int32 getSenderInfo(SSenderInfo* info);
	t_int32 setSenderInfo(SSenderInfo* info);

	//SR和RR使用。index从1开始。第一个block索引是1.
	t_int32 addReportBlock(t_int32 index, SReportBlock* block);
	t_int32 getReportBlock(t_int32 index, SReportBlock* block);

	//SDES使用
	t_int32 addChunk(t_int32 index, SChunk* chunk);
	t_int32 getChunk(t_int32 index, SChunk* chunk);

	//APP 重发使用，其它的App不支持
	t_int32 getAppResend(SAppResend* info);
	t_int32 setAppResend(SAppResend* info);

	t_int32 setBuffer(t_int8* data, t_int32 len);

	//二进制流处理	
	t_uint8* getStream();
	t_int32 getStreamLen();

private:
	t_uint8* m_data;
	t_int32 m_dataLen;

	mutexI	m_mutex;
};

#endif
