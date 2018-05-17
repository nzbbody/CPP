/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file	:			io_data_i.h
* 	@brief	:			
* 	@author	:         
*	@note	:	
*	@modify	:         hehairan addע��ͷ
*/


#ifndef _IO_DATA_I_H
#define _IO_DATA_I_H

#include <data_types.h>


#define IO_NONBLOCK 1

class DLL_EXPORT ioDataI
{
public:
	ioDataI();
	virtual ~ioDataI();
	

public:
	/** 
	*
	* 	func name	:	enable
	*	@brief		:	�������������ģʽ        
	*	@param		:	value = 1;	    
	*	@return		:	E_OK / E_FAIL
	*	@author		:	     
	*	@note:			
	*
	*/
	t_int32 enable(t_int32 value);

	/** 
	*
	* 	func name	:	disable
	*	@brief		:	���ý�ֹ������ģʽ        
	*	@param		:	value = 1;	    
	*	@return		:	E_OK / E_FAIL
	*	@author		:	     
	*	@note:			
	*
	*/
	t_int32 disable(t_int32 value);

	/** 
	*
	* 	func name	:	getHandle
	*	@brief		:	��ȡ���        
	*	@param		:		    
	*	@return		:	���
	*	@author		:	     
	*	@note:			
	*
	*/
	iohandle_t getHandle();

	/** 
	*
	* 	func name	:	setHandle
	*	@brief		:	���þ��        
	*	@param		:		    
	*	@return		:	E_OK / E_FAIL
	*	@author		:	     
	*	@note:			
	*
	*/
	t_int32 setHandle(iohandle_t handle);

	
private:
	iohandle_t mHandle;

};




#endif

