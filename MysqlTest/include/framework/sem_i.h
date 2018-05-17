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
	*	@brief		:	创建一个信号量，信号量的资源个数为num
	*	@param		:	num:资源数量
	*	@return		:   E_OK  E_FAIL
	*	@author		:   zhangxusheng
	*   @date		:    
	*	@note		:	创建一个信号量，信号量的资源个数为num
	*
	*/
	t_int32 create(int num);

	/** 
	*
	* 	func name	:	close
	*	@brief		:	关闭当前信号量
	*	@param		:	void
	*	@return		:   E_OK  E_FAIL
	*	@author		:   zhangxusheng
	*   @date		:    
	*	@note		:	使用完成一定要释放
	*
	*/

	t_int32 close();

	/** 
	*
	* 	func name	:	P
	*	@brief		:	执行P操作
	*	@param		:	void
	*	@return		:   E_OK  E_FAIL
	*	@author		:   zhangxusheng
	*   @date		:    
	*	@note		:	执行P操作
	*
	*/
	t_int32 P();
	
	/** 
	*
	* 	func name:		timeoutP
	*	@brief:			等待资源超时
	*	@param:		    超时时间
	*	@return:		0：能够获取等待资源；-1：超时；-2：其他错误
	*	@author:		zhangxusheng
	*	@modify:			
	*	@note:			2013-3-26
	*
	*/
	t_int32 timeoutP(t_int32 ms_timeout);

	/** 
	*
	* 	func name	:	V
	*	@brief		:	执行V操作
	*	@param		:	void
	*	@return		:   E_OK  E_FAIL
	*	@author		:   zhangxusheng
	*   @date		:    
	*	@note		:	执行P操作
	*
	*/
	t_int32 V();

private:
	//int PV(unsigned short sem_num,short sem_op,short sem_flag);

private: 
	sem_ptr		sem_handle;		//信号量句柄
	int			m_mutex;
};

#endif
