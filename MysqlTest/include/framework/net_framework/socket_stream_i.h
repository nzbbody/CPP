


#ifndef _SOCKET_STREAM_I_H
#define _SOCKET_STREAM_I_H


#include <data_types.h>
#include <net_framework/socket_i.h>


class socketStreamI : public socketI
{

public:
	t_int32 recvN(t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int32 &recved);

	t_int32 recvN(t_int8 *buff, t_int32 buffLen, t_int32 flags, sockaddr_t *addr, socklen_t *addrLen, t_int32 &recved);


	t_int32 sendN(t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int32 &sended);

	t_int32 sendN(t_int8 *buff, t_int32 buffLen, t_int32 flags, sockaddr_t *addr, socklen_t addrLen, t_int32 &sended);

	t_int32 close();
};




#endif

