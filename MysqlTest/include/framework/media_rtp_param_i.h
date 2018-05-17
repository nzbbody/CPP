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
	*	@brief:		设置负载类型
	*	@param:		payloadtype
	*	@return:	void
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/
	t_uint32 setPayloadType(t_uint8 payloadtype);	

	/** 
	* 	func name:	setTimeStamp
	*	@brief:		设置时间戳
	*	@param:		
	*	@return:	void
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/
	void setTimeStamp();

	/** 
	* 	func name:	setTimeStampUnit
	*	@brief:		设置时间戳增长单元
	*	@param:		timeStampUnit
	*	@return:	void
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/
	void setTimeStampUnit(t_uint32 timeStampUnit);

	/** 
	* 	func name:	setProtocalType
	*	@brief:		设置传输协议类型
	*	@param:		protocalType
	*	@return:	protocalType
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/
	void setProtocalType(t_int8 *prlType);


	/** 
	* 	func name:	setSeqrNum
	*	@brief:		设置包序列号
	*	@param:		
	*	@return:	protocalType
	*	@author:	he_hairan
	*	@note:		creat on 2013-4-22
	*
	*/	
	void setSeqrNum();

	/** 
	* 	func name:	setSsrc
	*	@brief:		设置同步源标识
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
	*	@brief:		设置标志位用来记录流中重要的事件
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

	t_uint8		payloadType;			//负载类型
	t_uint32	timeStamp;				//时间戳
	t_int8		protocalType[10];		//协议类型
	bool		maskFlag;				//标志位
	t_uint8		extension;				//扩展位
	t_uint32	ssrc;					//SSRC标志符
	t_uint16	seqrNum;				//序列号
	t_uint32	timeStampUnit;			//时间戳单元
	t_uint8		csrcnum;				//混合器中同步源的个数
	t_int32		maxPacketSize;			//最大包大小
	mediaRandomI mediarnd;				//随机数生成器


};

#endif
