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
*	@brief	  :	获取环境变量值
*	@param	  :	var:环境变量
*	@param	  : strValue:输出值，指获取的环境变量值
*	@return	  :  OK or FAILED
*	@author   :  chenjiang 
*   @date     :    
*	@note     :	 
*	@modify	  : hehairan add 注释头
*
*/
t_int32 getEnvironmentVar(const t_int8 *var, stringI &strValue);

/** 
*
* 	func name : setEnvironmentVar
*	@brief	  :	设置环境变量
*	@param	  :	var:被设置的环境变量
*	@param	  : strValue:被设置的环境变量值
*	@return	  :  OK or FAILED
*	@author   :  chenjiang 
*   @date     :    
*	@note     :	 
*	@modify	  : hehairan add 注释头
*
*/
t_int32 setEnvironmentVar(const t_int8 * var, stringI &strValue);



#endif
