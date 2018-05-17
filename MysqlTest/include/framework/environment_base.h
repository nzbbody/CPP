/**
*	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
*
*	@file		:		environment_base.h
* 	@brief		:		environment_base.h������environmentBase�࣬��Ҫ��ɻ��������ĳ�ʼ������
* 	@author		:		chenjiang
*	@note		:	
*	@modify		:		hehairan addע��ͷ	
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
	*	@brief:	  ���������ĳ�ʼ��
	*	@param:	  void
	*	@return:  OK or FAILED
	*	@author:  chenjiang 
	*   @date:    
	*	@note:	  ƽ̨���û�����ʼ������
	*	@modify	  : hehairan add ע��ͷ
	*/
	t_int32 init(t_int32 argc, t_int8* argv[]);
	t_int32 init(t_int8* configName);
	/** 
	*
	* 	func name:		Exit
	*	@brief:	  �����������˳�
	*	@param:	  void
	*	@return:  OK or FAILED
	*	@author:  chenjiang 
	*   @date:    
	*	@note:	  ƽ̨���û�����ʼ������
	*	@modify	  : hehairan add ע��ͷ
	*/
	t_int32 exit();

	/** 
	*
	* 	func name	:	getShellHandle
	*	@brief		:	��ȡ�����о��
	*	@param		:	void **handle
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	
	*	@modify	  : hehairan add ע��ͷ	
	*/
	t_int32 getShellHandle(void **handle);

private:
	/** 
	*
	* 	func name	:	globalPathInit
	*	@brief		:	ƽ̨����·����ʼ������
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	ƽ̨����·����ʼ��
	*	@modify	  : hehairan add ע��ͷ	
	*/
	t_int32 globalPathInit(t_int8* configPath);

	/** 
	*
	* 	func name	:	datetimeInit
	*	@brief		:	ƽ̨��ʱ����ʼ������
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	��ʱ����ʼ��
	*	@modify	  : hehairan add ע��ͷ	
	*/
	t_int32 datetimeInit(void);

	/** 
	*
	* 	func name	:	datetimeExit
	*	@brief		:	ƽ̨��ʱ����ʼ������
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   zhangxusheng
	*   @date:    
	*	@note		:	��ʱ����ʼ��
	*	@modify		:	
	*/
	t_int32 datetimeExit(void);

	/** 
	*
	* 	func name	:	shellInit
	*	@brief		:	ƽ̨�����г�ʼ������
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	ƽ̨�����г�ʼ��
	*	@modify	
	*/
	t_int32 shellInit(keyValueI & globalConfig);

	/** 
	*
	* 	func name	:	shellExit
	*	@brief		:	ƽ̨�������˳�����
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:	zhangxusheng
	*   @date:		:	2013-12-30
	*	@note		:	ƽ̨�����г�ʼ��
	*	@modify		:	
	*/
	t_int32 shellExit();

	/** 
	*
	* 	func name	:	traceFlagInit
	*	@brief		:	ƽ̨���Եȼ���ʼ������
	*	@param		:	void
	*	@return		:   OK or FAILED
	*	@author		:   
	*   @date:    
	*	@note		:	ƽ̨���Եȼ���ʼ��
	*	@modify	  	
	*/
	t_int32 traceFlagInit(keyValueI & globalConfig);

	/** 
	*
	* 	func name	:	NetDetectStart
	*	@brief		:	����̽��ģ������
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

