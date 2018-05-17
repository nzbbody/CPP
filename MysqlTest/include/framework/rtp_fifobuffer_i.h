/*
* Copyright (c) 2008,　浙江大华技术股份有限公司
* All rights reserved.
*
* 文件名称：rtp_fifo_buffer.h
* 文件标识：
* 摘　　要：FIFO缓冲，当RTP走over TCP连接方式时，需要缓冲以防止数据过长被截断的情况。
*
* 当前版本：1.0
* 作　　者：张旭升
* 完成日期：2014年5月30日
* 修订记录：创建
*/
//////////////////////////////////////////////////////////////////////

#ifndef RTP_FIFO_BUFFER_I_H
#define RTP_FIFO_BUFFER_I_H

#include <framework_i.h>

//在路数很多的情况下，如果该缓冲太大，空间浪费太严重，gaowei 09-08-06
#define	FIFO_BUFFER_LENGTH	1024*256 //1024*1024*1	//默认1M

class RTPFIFOBuffer
{
public:
	RTPFIFOBuffer();
	virtual ~RTPFIFOBuffer();

	//返回实际缓冲的长度，add by gaowei 09-08-06
	t_int32 appendData(const t_int8* data, t_int32 len);

	t_int32	addData(const t_int8* data, t_int32 len);
	t_int32 decData(t_int32 len);

	t_int8*	getDataPtr();
	t_int32	getDataLen();

protected:
	//简单缓冲
	t_int8	m_buffer[FIFO_BUFFER_LENGTH];
	t_int32	m_readPos;
	t_int32	m_writePos;
	mutexI	m_mutex;
};

#endif // !defined(RTSP_BUFFER_INCLUDE)
