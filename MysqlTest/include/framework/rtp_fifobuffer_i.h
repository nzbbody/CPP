/*
* Copyright (c) 2008,���㽭�󻪼����ɷ����޹�˾
* All rights reserved.
*
* �ļ����ƣ�rtp_fifo_buffer.h
* �ļ���ʶ��
* ժ����Ҫ��FIFO���壬��RTP��over TCP���ӷ�ʽʱ����Ҫ�����Է�ֹ���ݹ������ضϵ������
*
* ��ǰ�汾��1.0
* �������ߣ�������
* ������ڣ�2014��5��30��
* �޶���¼������
*/
//////////////////////////////////////////////////////////////////////

#ifndef RTP_FIFO_BUFFER_I_H
#define RTP_FIFO_BUFFER_I_H

#include <framework_i.h>

//��·���ܶ������£�����û���̫�󣬿ռ��˷�̫���أ�gaowei 09-08-06
#define	FIFO_BUFFER_LENGTH	1024*256 //1024*1024*1	//Ĭ��1M

class RTPFIFOBuffer
{
public:
	RTPFIFOBuffer();
	virtual ~RTPFIFOBuffer();

	//����ʵ�ʻ���ĳ��ȣ�add by gaowei 09-08-06
	t_int32 appendData(const t_int8* data, t_int32 len);

	t_int32	addData(const t_int8* data, t_int32 len);
	t_int32 decData(t_int32 len);

	t_int8*	getDataPtr();
	t_int32	getDataLen();

protected:
	//�򵥻���
	t_int8	m_buffer[FIFO_BUFFER_LENGTH];
	t_int32	m_readPos;
	t_int32	m_writePos;
	mutexI	m_mutex;
};

#endif // !defined(RTSP_BUFFER_INCLUDE)
