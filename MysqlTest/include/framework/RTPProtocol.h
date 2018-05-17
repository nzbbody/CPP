/*
* Copyright (c) 2007, 浙江大华技术股份有限公司
* All rights reserved.
*
* 文件名称：RTPProtocol.h
* 文件标识：参见配置管理计划书
* 摘　　要：RTP全局宏、预定义文件。
*
* 当前版本：1.0
* 作　　者：李明江
* 完成日期：2007年7月15日
* 修订记录：稳定，标准RTP及带重发的RTP会话都完成了。

*
* 取代版本：0.1
* 原作者　：李明江
* 完成日期：2007年7月1日
* 修订记录：创建
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