


#ifndef _SOCKET_ACCEPTOR_I_H
#define _SCOKET_ACCEPTOR_I_H


#include <data_types.h>
#include <net_framework/inet_addr_i.h>
#include <net_framework/socket_i.h>
#include <net_framework/socket_stream_i.h>

class socketAcceptorI : public socketI
{
public:
	/** 
	*
	* 	func name	:		open
	*	@brief		:	    ��socket����
	*	@return		:		E_OK����socket���ӳɹ���E_FAIL:��socket����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 open(sockaddr_t &addr, 
		t_int32 reuse = 1, 
		t_int32 family = AF_INET, 
		t_int32 backlog = 5, 
		t_int32 proto = 0);
	/** 
	*
	* 	func name	:		close
	*	@brief		:		�ر�socket����
	*	@return		:		E_OK���ر�socket���ӳɹ���E_FAIL:�ر�socket����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 close();
	/** 
	*
	* 	func name	:		resume
	*	@brief		:	    �ָ�socket����
	*	@return		:		E_OK���ָ�socket���ӳɹ���E_FAIL:�ָ�socket����ʧ��
	*	@author		:	    zhangxusheng
	*	@note:			
	*
	*/
	t_int32 resume();
	t_int32 suspend();


public:

	t_int32 accept(socketStreamI &socketStream, sockaddr_t &sockaddr);


private:
	t_int32 openEx(sockaddr_t &addr, t_int32 family, t_int32 backlog, t_int32 reuse);
};



#endif
