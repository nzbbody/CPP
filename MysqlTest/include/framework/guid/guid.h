
/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			guid.h
* 	@brief	:			产生唯一的数字标识符
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan add注释头
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
	*	@brief		:	产生一个全局惟一的数字标识符        
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
	*	@brief		:	获取产生的全局惟一的数字标识符        
	*	@param		:		    
	*	@return		:	标识符
	*	@author		:	     
	*	@note:			
	*
	*/
	t_int8* get_guid(void);

private:
	UUID guid;				//全局唯一标识符
	t_int8 buf[GUID_SIZE];	//guid缓存区
};

#endif
