

#ifndef _OS_SOCKET_I_H
#define _OS_SOCKET_I_H

#include <data_types.h>
#include <errno/error_i.h>

#define SOCKADDR_LEN sizeof(sockaddr_t)
#define SOCKADDR6_LEN sizeof(sockaddr6_t);

#ifndef WIN32
#define ipHeader struct ip
#else
typedef struct _iphdr 
{
	//Suppose the BYTE_ORDER is LITTLE_ENDIAN
	unsigned char   ip_hl:4;        // Length of the header
	unsigned char   ip_v:4;      // Version of IP
	unsigned char  ip_tos;            // Type of service
	unsigned short ip_len;      // Total length of the packet
	unsigned short ip_id;             // Unique identification
	unsigned short ip_off;    // Fragment offset
	unsigned char  ip_ttl;            // Time to live
	unsigned char  ip_p;       // Protocol (TCP, UDP etc)
	unsigned short ip_sum;       // IP checksum
	unsigned int   ip_src;       // Source IP
	unsigned int   ip_dst;         // Destination IP
} ipHeader;
#endif

#ifdef WIN32
typedef struct 
{
	t_uint8 ihl:4, version:4;
	t_uint8 tos;
	t_uint16 tot_len;
	t_uint16 id;
	t_uint16 frag_off;
	t_uint8 ttl;
	t_uint8 protocol; 
	t_uint16 check;
	t_uint32 saddr;
	t_uint32 daddr;
}IPHeader, *PIPHeader;
#else
#define IPHeader struct iphdr
#define PIPHeader struct iphdr*
#endif

#ifdef WIN32
typedef struct 
{
	t_uint16 source;
	t_uint16 dest;
	t_uint16 len;
	t_uint32 check;
}UDPHeader, *PUDPHeader;
#else
#define UDPHeader struct udphdr
#define PUDPHeader struct udphdr*
#endif

#ifndef WIN32 
#define icmpStruct struct icmp
struct ethtoolCmd
{
	t_uint32 cmd;
	t_uint32 supported;
	t_uint32 advertising;
	t_uint16 speed;
	t_uint8  duplex;
	t_uint8  port;
	t_uint8  phy_address;
	t_uint8  transceiver;
	t_uint8  autoneg;
	t_uint32 maxtxpkt;
	t_uint32 maxrxpkt;
	t_uint32 reserved[4];
};
#else
typedef struct icmpHeader
{
	BYTE	icmp_type;
	BYTE	icmp_code;
	USHORT	icmp_cksum;
	USHORT	icmp_id;
	USHORT	icmp_seq;
	union
	{
		ULONG its_time;
		unsigned char id_data[1];
	}icmp_dun;
#define icmp_data icmp_dun.id_data;
}icmpStruct;
#endif

namespace OS_SOCKET 
{

	t_int32 socket(t_int32 domain, t_int32 type, t_int32 protocol, iohandle_t &sock);

	t_int32 bind(iohandle_t sock, sockaddr_t *addr, socklen_t addrLen);
	t_int32 bind(iohandle_t sock, sockaddr_t *addr, socklen_t addrLen);

	t_int32 listen(iohandle_t sock, t_int32 backlog);

	t_int32 accept(iohandle_t sock, sockaddr_t *addr, socklen_t *addrLen, iohandle_t &newsock);

	#ifdef WIN32
		int socket_geterror(iohandle_t sock);
	#else
		#define socket_geterror(sock) (errno)
	#endif

	t_int32 connect(iohandle_t sock, sockaddr_t *addr, socklen_t addrLen);

	t_int32 setSockOpt(iohandle_t sock, t_int32 level, t_int32 option, void *optVal, socklen_t optLen);

	t_int32 getSockOpt(iohandle_t sock, t_int32 level, t_int32 option, void *optVal, socklen_t *optLen);

	t_int32 recv(iohandle_t sock, t_int8 *buff, t_int32 buffLen, t_int32 flags);

	t_int32 recv(iohandle_t sock, t_int8 *buff, t_int32 buffLen, t_int32 flags, sockaddr_t *addr, socklen_t *addrLen);

	t_int32 send(iohandle_t sock, t_int8 *buff, t_int32 buffLen, t_int32 flags);

	t_int32 send(iohandle_t sock, t_int8 *buff, t_int32 buffLen, t_int32 flags, sockaddr_t *addr, socklen_t  addrLen);

	t_int32 close(iohandle_t sock);

	t_int32 pair(t_int32 family, t_int32 type, t_int32 protocol, iohandle_t &listener, iohandle_t &connector, iohandle_t &acceptor);

	t_int32 socketPair(t_int32 family, t_int32 type, t_int32 protocol, iohandle_t handle[3]);

};

#endif

