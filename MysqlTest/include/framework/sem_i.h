#ifndef _SEM_I_H
#define _SEM_I_H

#ifdef WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <sys/sem.h>
#include <semaphore.h>
#endif

#ifdef WIN32
#define sem_ptr  HANDLE
#else
#define sem_ptr sem_t *
#endif




class DLL_EXPORT  semI
{		
public:
	semI();
	virtual ~semI();

public:

	/** 
	*
	* 	func name	:	create
	*	@brief		:	����һ���ź������ź�������Դ����Ϊnum
	*	@param		:	num:��Դ����
	*	@return		:   E_OK  E_FAIL
	*	@author		:   zhangxusheng
	*   @date		:    
	*	@note		:	����һ���ź������ź�������Դ����Ϊnum
	*
	*/
	t_int32 create(int num);

	/** 
	*
	* 	func name	:	close
	*	@brief		:	�رյ�ǰ�ź���
	*	@param		:	void
	*	@return		:   E_OK  E_FAIL
	*	@author		:   zhangxusheng
	*   @date		:    
	*	@note		:	ʹ�����һ��Ҫ�ͷ�
	*
	*/

	t_int32 close();

	/** 
	*
	* 	func name	:	P
	*	@brief		:	ִ��P����
	*	@param		:	void
	*	@return		:   E_OK  E_FAIL
	*	@author		:   zhangxusheng
	*   @date		:    
	*	@note		:	ִ��P����
	*
	*/
	t_int32 P();
	
	/** 
	*
	* 	func name:		timeoutP
	*	@brief:			�ȴ���Դ��ʱ
	*	@param:		    ��ʱʱ��
	*	@return:		0���ܹ���ȡ�ȴ���Դ��-1����ʱ��-2����������
	*	@author:		zhangxusheng
	*	@modify:			
	*	@note:			2013-3-26
	*
	*/
	t_int32 timeoutP(t_int32 ms_timeout);

	/** 
	*
	* 	func name	:	V
	*	@brief		:	ִ��V����
	*	@param		:	void
	*	@return		:   E_OK  E_FAIL
	*	@author		:   zhangxusheng
	*   @date		:    
	*	@note		:	ִ��P����
	*
	*/
	t_int32 V();

private:
	//int PV(unsigned short sem_num,short sem_op,short sem_flag);

private: 
	sem_ptr		sem_handle;		//�ź������
	int			m_mutex;
};

#endif
