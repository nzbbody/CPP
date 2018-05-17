#ifndef MEDIA_RTP_PARAM_I_H
#define MEDIA_RTP_PARAM_I_H

#include "media_rtp_random_i.h"

class DLL_EXPORT mediaRtpParamI	
{
public:
	mediaRtpParamI();
	~mediaRtpParamI();

public:
	/** 
	* 	func name:	setPayloadType
	*	@brief:		���ø�������
	*	@param:		payloadtype
	*	@return:	void
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/
	t_uint32 setPayloadType(t_uint8 payloadtype);	

	/** 
	* 	func name:	setTimeStamp
	*	@brief:		����ʱ���
	*	@param:		
	*	@return:	void
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/
	void setTimeStamp();

	/** 
	* 	func name:	setTimeStampUnit
	*	@brief:		����ʱ���������Ԫ
	*	@param:		timeStampUnit
	*	@return:	void
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/
	void setTimeStampUnit(t_uint32 timeStampUnit);

	/** 
	* 	func name:	setProtocalType
	*	@brief:		���ô���Э������
	*	@param:		protocalType
	*	@return:	protocalType
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/
	void setProtocalType(t_int8 *prlType);


	/** 
	* 	func name:	setSeqrNum
	*	@brief:		���ð����к�
	*	@param:		
	*	@return:	protocalType
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/	
	void setSeqrNum();

	/** 
	* 	func name:	setSsrc
	*	@brief:		����ͬ��Դ��ʶ
	*	@param:		
	*	@return:	
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-26
	*
	*/	
	void  setSsrc();

	t_uint32 getSSRC();
	/** 
	* 	func name:	setMask
	*	@brief:		���ñ�־λ������¼������Ҫ���¼�
	*	@param:		mask
	*	@return:	
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-26
	*
	*/
	void setMask(bool mask);

	/** 
	* 	func name:	setExtension
	*	@brief:		
	*	@param:		
	*	@return:	
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-26
	*
	*/
	t_uint8 setExtension();	

	/** 
	* 	func name:	setMaxPacket
	*	@brief:		
	*	@param:		
	*	@return:	
	*	@author:	he_hairan
	*	@note:		creat on 2013-5-21
	*
	*/
	t_int32 setMaxPacket(t_int32 maxSize);

	t_int32 getMaxPacket();

public:
	void paramInit();

public:	

	t_uint8		payloadType;			//��������
	t_uint32	timeStamp;				//ʱ���
	t_int8		protocalType[10];		//Э������
	bool		maskFlag;				//��־λ
	t_uint8		extension;				//��չλ
	t_uint32	ssrc;					//SSRC��־��
	t_uint16	seqrNum;				//���к�
	t_uint32	timeStampUnit;			//ʱ�����Ԫ
	t_uint8		csrcnum;				//�������ͬ��Դ�ĸ���
	t_int32		maxPacketSize;			//������С
	mediaRandomI mediarnd;				//�����������


};

#endif
