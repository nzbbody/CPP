#ifndef _TRACEDATA_I_H
#define _TRACEDATA_I_H

#include <data_types.h>


#define TRACE_INFO		1<<1
#define TRACE_DEBUG		1<<2
#define TRACE_API		1<<3
#define TRACE_WARNING	1<<4
#define TRACE_ERR		1<<5
#define TRACE_FOTAL		1<<6
#define TRACE_FATAL		1<<6	//以前写错了，现在弥补一下

#define TRACE_FRAMEINFO	1<<9
#define TRACE_FRAMEDEB	1<<10

/** 
*
* 	func name	:	getTraceFlag
*	@brief		:	获取打印信息标志        
*	@param		:	void	    
*	@return		:	标志位
*	@author		:	     
*	@note:			
*
*/
t_int32 DLL_EXPORT getTraceFlag();

/** 
*
* 	func name	:	setTraceFlag
*	@brief		:	设置打印信息标志        
*	@param		:	flag	标志位    
*	@return		:	E_OK
*	@author		:	     
*	@note:			
*
*/
t_int32 DLL_EXPORT enableTrace(t_int32 flag);

/** 
*
* 	func name	:	clrTraceFlag
*	@brief		:	清除打印信息标志        
*	@param		:	flag	标志位    
*	@return		:	E_OK
*	@author		:	     
*	@note:			
*
*/
t_int32 DLL_EXPORT disEnableTrace(t_int32 flag);

#endif


