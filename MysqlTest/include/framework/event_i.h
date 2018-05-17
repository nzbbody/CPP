

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
 *  �¼��ӿ���
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
 *  �¼�ʵ����
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
		/** event_iʵ����ʼ������
		*
		* 	func name:	eventInit
		*	@brief:		��ʼ��һ���¼���
		*	@param:		void
		*	@param:		void
		*	@return:	E_OK---��ʼ���ɹ���E_FAIL---��ʼ��ʧ��
		*	@author:	zhang_xusheng
		*	@date:		2012-12-17
		*	@note:
		*/
		t_int32 eventInit(void);


		/** event_iʵ�����ͷź���
		*
		* 	func name:	eventExit
		*	@brief:		�ͷ��߳�������¼���
		*	@param:		void
		*	@param:		void
		*	@return:	void
		*	@author:	zhang_xusheng
		*	@date:		2012-12-17
		*	@note:
		*/
		t_int32 eventExit(void);

		
		/** eventʵ��������������
		*
		* 	func name:	eventStart
		*	@brief:		��ʼ����event_base�е���������
		*	@param:		void
		*	@param:		void
		*	@return:	E_OK---�ɹ���E_FAIL---ʧ��
		*	@author:	zhang_xusheng
		*	@date:		2012-12-18
		*	@note:
		*/
		t_int32 eventStart(void);


		/** eventʵ����ֹͣ����
		*
		* 	func name:	eventStop
		*	@brief:		�¼�������ֹͣ������ֹͣ�¼�����
		*	@param:		void
		*	@param:		void
		*	@return:	E_OK---�ɹ���E_FAIL---ʧ��
		*	@author:	zhang_xusheng
		*	@date:		2012-12-16
		*	@note:
		*/
		t_int32 eventStop(void);
		

		/** eventʵ�������ú���
		*
		* 	func name:	eventSet
		*	@brief:		�¼����������ú������������¼��¼��󶨵���Ӧ���¼�����
		*	@param:		ev---�¼����
		*	@param:		sockfd---�������¼����ļ�������
		*	@param:		events---�¼�������ʽ:EV_READ ���� EV_WRITE
		*	@return:	E_OK---�ɹ���E_FAIL---ʧ��
		*	@author:	zhang_xusheng
		*	@date:		2012-12-16
		*	@note:
		*/
		t_int32 eventSet(event_t *ev, iohandle_t sockfd, t_int16 events, eventCallback evCb, void *arg);


		/** eventʵ������Ӻ���
		*
		* 	func name:	eventAdd
		*	@brief:		�¼���������Ӻ�����Ϊ�����¼����ó�ʱʱ��
		*	@param:		void
		*	@param:		void
		*	@return:	E_OK---�ɹ���E_FAIL---ʧ��
		*	@author:	zhang_xusheng
		*	@date:		2012-12-16
		*	@note:
		*/
		t_int32 eventAdd(event_t *ev, t_uint32 timeoutMs);


		/** eventʵ����ɾ������
		*
		* 	func name:	eventDel
		*	@brief:		�¼�������ɾ������
		*	@param:		�¼�ָ��
		*	@return:	E_OK---�ɹ���E_FAIL---ʧ��
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
