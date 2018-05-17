/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */
 

#ifndef _BASE_I_H
#define _BASE_I_H


#include <data_types.h>
#include <string/string_i.h>
#include <errno/error_i.h>
#include <trace/trace_i.h>

/** 
*
* 	func name : getEnvironmentVar
*	@brief	  :	��ȡ��������ֵ
*	@param	  :	var:��������
*	@param	  : strValue:���ֵ��ָ��ȡ�Ļ�������ֵ
*	@return	  :  OK or FAILED
*	@author   :  chenjiang 
*   @date     :    
*	@note     :	 
*	@modify	  : hehairan add ע��ͷ
*
*/
t_int32 getEnvironmentVar(const t_int8 *var, stringI &strValue);

/** 
*
* 	func name : setEnvironmentVar
*	@brief	  :	���û�������
*	@param	  :	var:�����õĻ�������
*	@param	  : strValue:�����õĻ�������ֵ
*	@return	  :  OK or FAILED
*	@author   :  chenjiang 
*   @date     :    
*	@note     :	 
*	@modify	  : hehairan add ע��ͷ
*
*/
t_int32 setEnvironmentVar(const t_int8 * var, stringI &strValue);



#endif
