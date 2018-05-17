/*
* Copyright (c) 2007, �㽭�󻪼����ɷ����޹�˾
* All rights reserved.
*
* �ļ����ƣ�RTPProtocol.h
* �ļ���ʶ���μ����ù���ƻ���
* ժ����Ҫ��RTPȫ�ֺꡢԤ�����ļ���
*
* ��ǰ�汾��1.0
* �������ߣ�������
* ������ڣ�2007��7��15��
* �޶���¼���ȶ�����׼RTP�����ط���RTP�Ự������ˡ�

*
* ȡ���汾��0.1
* ԭ���ߡ���������
* ������ڣ�2007��7��1��
* �޶���¼������
*/

#ifndef _RTP_PROTOCOL_H_
#define _RTP_PROTOCOL_H_

#if 0
#if defined(WIN32)||defined(WINCE)
#include <winsock2i.h>
#else
#include<netinet/in.h>
#endif
#endif

#define MIN_HEAD_LENGTH		12
#define PROTOCOL_VERSION	2
#define RTP_BUFFER_SIZE		8*1024

enum Model
{
	SENDER = 1,
	RECEIVER
};

enum RTCPTYPE
{
	SR		= 200,
	RR		= 201,
	SDES	= 202,
	BYE		= 203,
	APP		= 204,
};

#define RESEND	14
#define RTCPDEFAULTSIZE 200

typedef struct
{
	t_uint32 ntpTimestampHigh;
	t_uint32 ntpTimestampLow;
	t_uint32 rtpTimestamp;
	t_uint32 packetCount;
	t_uint32 octetCount;
} SSenderInfo;

typedef struct
{
	t_uint32 fractionLost : 8;
	t_uint32 packetsLost  : 24;
} SLost;

typedef struct
{
	SLost lost;
	t_uint32 highestSequence;
	t_uint32 jitter;
	t_uint32 lastSR;
	t_uint32 delaySR;
} SReportBlock;

typedef struct 
{
	t_uint8 type;
	t_uint8 length;
	t_uint8 data[64];
}SCname;

typedef struct 
{
	t_uint32 ssrc;
	SCname scname;
}SChunk;

typedef struct 
{
	t_uint32 name;
	unsigned short seqence1;
	unsigned short seqence2;
}SAppResend;


#endif//_RTP_PROTOCOL_H_