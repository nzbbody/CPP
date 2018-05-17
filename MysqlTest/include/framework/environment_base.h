/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file		:		environment_base.h
* 	@brief		:		environment_base.h定义了environmentBase类，主要完成基础环境的初始化功能
* 	@author		:		chenjiang
*	@note		:	
*	@modify		:		hehairan add注释头	
*/

#ifndef _ENVIRONMENT_BASE_H
#define _ENVIRONMENT_BASE_H

#include <data_types.h>
#include <initialize_ex.h>


#include <event_i.h>
#include <key_value_i.h>
#include <event_timer_i.h>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>
#include <rapidxml/rapidxml_print.hpp>
#include <ez/ez_shell_impl.h>

#define EZCLIPORT	"ezcli_port"

#define TRACECONFIG	"trace_config"
#define CONFIGDEBUG	"trace_debug"
#define CONFIGINFO	"trace_info"
#define CONFIGAPI	"trace_api"
#define CONFIGWARNING	"trace_warning"
#define CONFIGERR	"trace_error"
#define CONFIGFATAL	"trace_fatal"
#define CONFIGFRAMEDEB	"trace_framedebug"
#define CONFIGFRAMEINFO	"trace_frameinfo"

#define EZDEFAULTPORT	6000

#define DETECT_CONFIG	"detect_config"

class DLL_EXPORT environmentBase
{
public:
	environmentBase();
	virtual ~environmentBase();


public:

	/** 
	*
	* 	func name:		Init
	*	@brief:	  基础环境的初始化
	*	@param:	  void
	*	@return:  OK or FAILED
	*	@author:  chenjiang 
	*   @date:    
	*	@note:	  平台配置环境初始化函数
	*	@modify	  : hehairan add 注释头
	*/
	t_int32 init(t_int32 argc, t_int8* argv[]);
	t_int32 init(t_int8* configName);
	/** 
	*
	* 	func name:		Exit
	*	@brief:	  基础环境的退出
	*	@param:	  void
	*	@return:  OK or FAILED
	*	@author:  chenjiang 
	*   @date:    
	*	@note:	  平台配置环境初始化函数
	*	@modify	  : hehairan add 注释头
	*/
	t_int32 exit();

	/** 
	*
	* 	func name	:	getShellHandle
	*	@brief		:	获取命令行句柄
	*	@param		:	void **handle
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	
	*	@modify	  : hehairan add 注释头	
	*/
	t_int32 getShellHandle(void **handle);

private:
	/** 
	*
	* 	func name	:	globalPathInit
	*	@brief		:	平台配置路径初始化函数
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	平台配置路径初始化
	*	@modify	  : hehairan add 注释头	
	*/
	t_int32 globalPathInit(t_int8* configPath);

	/** 
	*
	* 	func name	:	datetimeInit
	*	@brief		:	平台定时器初始化函数
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	定时器初始化
	*	@modify	  : hehairan add 注释头	
	*/
	t_int32 datetimeInit(void);

	/** 
	*
	* 	func name	:	datetimeExit
	*	@brief		:	平台定时器初始化函数
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   zhangxusheng
	*   @date:    
	*	@note		:	定时器初始化
	*	@modify		:	
	*/
	t_int32 datetimeExit(void);

	/** 
	*
	* 	func name	:	shellInit
	*	@brief		:	平台命令行初始化函数
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	平台命令行初始化
	*	@modify	
	*/
	t_int32 shellInit(keyValueI & globalConfig);

	/** 
	*
	* 	func name	:	shellExit
	*	@brief		:	平台命令行退出函数
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:	zhangxusheng
	*   @date:		:	2013-12-30
	*	@note		:	平台命令行初始化
	*	@modify		:	
	*/
	t_int32 shellExit();

	/** 
	*
	* 	func name	:	traceFlagInit
	*	@brief		:	平台调试等级初始化函数
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	平台调试等级初始化
	*	@modify	  	
	*/
	t_int32 traceFlagInit(keyValueI & globalConfig);

	/** 
	*
	* 	func name	:	NetDetectStart
	*	@brief		:	网络探测模块启动
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:
	*	@note		:	
	*	@modify	  	
	*/
	t_int32 NetDetectStart(keyValueI & globalConfig);

#if 0
	t_int32 globalEventInit(void);
	t_int32 globalEventStart(void);
	t_int32 globalEventStop(void);
#endif


public:
	keyValueI mGlobalPath;

private:
	eventTimerI *_dateTimer;
	ezShellI *_sheller;
	t_int32		m_mmND;
};



#endif

