

/**
 * Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD 
 */

  
#ifndef _EVENT_I_H_
#define _EVENT_I_H_

#include <thread/os_thread_i.h>
#include <data_types.h>

#include <event2/event.h>
#include <event2/event_compat.h>
#include <event2/event_struct.h>



typedef struct event event_t;
typedef struct event_base eventbase_t; 
typedef void (*eventCallback)(iohandle_t sockfd, t_int16 events, void *arg);



/**
 *  事件接口类
 * \author zhangsb
 * \date 2012-06-10
 *
 */
class eventI
{
public:
	virtual ~eventI() {};

public:

	virtual t_int32 eventInit() = 0;
	virtual t_int32 eventStart() = 0;
	virtual t_int32 eventStop() = 0;
	
	virtual t_int32 eventSet(event_t *ev, iohandle_t sockfd, t_int16 events, eventCallback evCb, void *arg) = 0;
	virtual t_int32 eventAdd(event_t *ev,t_uint32 timeoutMs) = 0;
	virtual t_int32 eventDel(event_t *ev) = 0;

	
};

/**
 *  事件实现类
 * \author zhangsb
 * \date 2012-06-10
 *
 */
class eventImpl : public eventI
{
	public:
		eventImpl();
		virtual ~eventImpl();
		
	public:
		/** event_i实例初始化函数
		*
		* 	func name:	eventInit
		*	@brief:		初始化一个事件集
		*	@param:		void
		*	@param:		void
		*	@return:	E_OK---初始化成功；E_FAIL---初始化失败
		*	@author:	zhang_xusheng
		*	@date:		2012-12-17
		*	@note:
		*/
		t_int32 eventInit(void);


		/** event_i实例的释放函数
		*
		* 	func name:	eventExit
		*	@brief:		释放线程申请的事件集
		*	@param:		void
		*	@param:		void
		*	@return:	void
		*	@author:	zhang_xusheng
		*	@date:		2012-12-17
		*	@note:
		*/
		t_int32 eventExit(void);

		
		/** event实例启动监听函数
		*
		* 	func name:	eventStart
		*	@brief:		开始监听event_base中的所有数据
		*	@param:		void
		*	@param:		void
		*	@return:	E_OK---成功；E_FAIL---失败
		*	@author:	zhang_xusheng
		*	@date:		2012-12-18
		*	@note:
		*/
		t_int32 eventStart(void);


		/** event实例的停止函数
		*
		* 	func name:	eventStop
		*	@brief:		事件监听的停止函数，停止事件监听
		*	@param:		void
		*	@param:		void
		*	@return:	E_OK---成功；E_FAIL---失败
		*	@author:	zhang_xusheng
		*	@date:		2012-12-16
		*	@note:
		*/
		t_int32 eventStop(void);
		

		/** event实例的设置函数
		*
		* 	func name:	eventSet
		*	@brief:		事件监听的设置函数，将监听事件事件绑定到相应的事件集上
		*	@param:		ev---事件句柄
		*	@param:		sockfd---待监听事件的文件描述符
		*	@param:		events---事件监听方式:EV_READ 或者 EV_WRITE
		*	@return:	E_OK---成功；E_FAIL---失败
		*	@author:	zhang_xusheng
		*	@date:		2012-12-16
		*	@note:
		*/
		t_int32 eventSet(event_t *ev, iohandle_t sockfd, t_int16 events, eventCallback evCb, void *arg);


		/** event实例的添加函数
		*
		* 	func name:	eventAdd
		*	@brief:		事件监听的添加函数，为监听事件设置超时时间
		*	@param:		void
		*	@param:		void
		*	@return:	E_OK---成功；E_FAIL---失败
		*	@author:	zhang_xusheng
		*	@date:		2012-12-16
		*	@note:
		*/
		t_int32 eventAdd(event_t *ev, t_uint32 timeoutMs);


		/** event实例的删除函数
		*
		* 	func name:	eventDel
		*	@brief:		事件监听的删除函数
		*	@param:		事件指针
		*	@return:	E_OK---成功；E_FAIL---失败
		*	@author:	zhang_xusheng
		*	@date:		2012-12-16
		*	@note:
		*/
		t_int32 eventDel(event_t *ev);
		

		eventbase_t *eventBase(void);
	

	public:
		thread_key_t	eventKey;	
		
};





t_int32 DLL_EXPORT eventManagerInit(void);
t_int32 DLL_EXPORT eventManagerExit(void);
t_int32 DLL_EXPORT eventManagerStart(void);
t_int32 DLL_EXPORT eventManagerStop(void);
t_int32 DLL_EXPORT eventManagerAdd(event_t *ev, 
						iohandle_t sockfd, 
						t_int16 events, 
						eventCallback evCb, 
						void *arg, 
						t_uint32 timeoutMs);
t_int32 DLL_EXPORT eventManagerDel(event_t *ev);
eventImpl DLL_EXPORT *  eventManager(void);



#endif
