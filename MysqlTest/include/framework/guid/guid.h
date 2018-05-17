
/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			guid.h
* 	@brief	:			����Ψһ�����ֱ�ʶ��
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan addע��ͷ
*/

#ifndef _GUID_H
#define _GUID_H


#include <data_types.h>
#include <errno/error_i.h>
#ifdef WIN32
#define  UUID  GUID
#else
#ifdef ARM_NONE
#define	UUID	t_int32
#else
#define  UUID  uuid_t
#endif
#endif




#define GUID_SIZE  64

class DLL_EXPORT GUID_
{
public:
	GUID_();
	virtual ~GUID_(){};

	/** 
	*
	* 	func name	:	new_guid
	*	@brief		:	����һ��ȫ��Ωһ�����ֱ�ʶ��        
	*	@param		:		    
	*	@return		:	E_OK
	*	@author		:	     
	*	@note:			
	*
	*/
	t_int32 new_guid(void);

	t_int8* to_string(void);

	/** 
	*
	* 	func name	:	get_guid
	*	@brief		:	��ȡ������ȫ��Ωһ�����ֱ�ʶ��        
	*	@param		:		    
	*	@return		:	��ʶ��
	*	@author		:	     
	*	@note:			
	*
	*/
	t_int8* get_guid(void);

private:
	UUID guid;				//ȫ��Ψһ��ʶ��
	t_int8 buf[GUID_SIZE];	//guid������
};

#endif
