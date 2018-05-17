


#ifndef _INET_ADDR_I_H
#define _INET_ADDR_I_H

#include <data_types.h>


#include <os/os_socket_i.h>



t_int32 DLL_EXPORT inetAddr(t_int8 *ip, t_int16 port, sockaddr_t *sockaddr, socklen_t *socklen);
t_int32 DLL_EXPORT inetAddr(t_int8 *ip, t_uint16 port, sockaddr6_t *sockaddr, socklen_t *socklen);

/** 不可重入*/
t_int8 DLL_EXPORT *inetNtop(sockaddr_t *sockaddr);
t_int8 DLL_EXPORT *inetNtop(sockaddr_t *sockaddr, t_int8 *buf);
t_uint16 DLL_EXPORT inetNtohs(sockaddr_t *sockaddr);



#endif

