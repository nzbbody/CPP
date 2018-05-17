#ifndef ICMP_CONNECT_I_H
#define ICMP_CONNECT_I_H

#include "data_types.h"
#include "event_handler_i.h"
#include "socket_i.h"
#include "socket_stream_i.h"
#include "trace/trace_i.h"
#include "udp_unicast_i.h"
#include <mutex_i.h>

typedef enum
{
	RAWSOCKET_CLOSED = 0,
	RAWSOCKET_CONNECTING,
	RAWSOCKET_CONNECTED,

}ICMPSOCKSTATUS;

struct IcmpEchoReply {
	int icmpSeq;
	int icmpLen;
	int ipTtl;
	double rtt;
	std::string fromAddr;
	bool isReply;
};
#define ICMP_ECHO 8
#define ICMP_ECHOREPLY 0
#define ICMP_MIN  8

//icmp连接默认超时时间
#define ICMP_DEFAULT_TIMEOUT	1000


class DLL_EXPORT IcmpConnectI : public eventHandlerI
{
public:
	IcmpConnectI();
	virtual ~IcmpConnectI();

public:
	t_int32 open(t_int8* localIp = NULL, t_uint16 localPort = 0);
	t_int32 close();

	t_int32 send(t_int8 *buff, t_int32 buffLen, t_int32 flags, t_int8 *remoteIp, t_uint16 remotePort, t_int32 &sended);
	t_int32 sendto(t_int8* dstIp, t_uint16 dstPort, t_int8* buffer, t_int32 bufferLen);

	t_int32 setCallback(socketCbI* callback, void* args);
	t_int32 setTimeOut(t_int32 timeout);

	t_int8* getRemoteIp(t_handler peerId);
	t_uint16 getRemotePort(t_handler peerId);

public:
	t_int32 peerAdd(t_int8* remoteIp, t_uint16 remotePort);
	t_int32 peerDel(t_handler peerId);

public:
	t_int32 handleInput(iohandle_t handle);
	t_int32 handleInputTimeout(iohandle_t handle);
	t_int32 handleOutput(iohandle_t handle);
	//t_int32 handleOutputTimeout(iohandle_t handle);

	t_int32 getHandle();
	
public:
	int packIcmp(int pack_no, icmpStruct* icmp);

private:
	t_int32 complate();
	t_int8* buildPacket(t_int8* buffer, t_int32 bufferLen, t_int32 rawPacketLen);
	t_int32 connect(t_int8* ip, t_uint16 port, t_handler &peer);
	t_int32 getClientId();
	prosessId osGetpid();
	
	//unsigned short checksum(unsigned short *buffer, int size);
	//void CalculateCheckSum(void* ipdhr, PUDPHeader udphdr, char* payload, int payloadLen);
	//t_int8* parse(t_int8* buffer, t_int32 bufferLen, t_int32 payloadLen);
	t_int32 unpackIcmp(char *buf,int len, struct IcmpEchoReply *icmpEchoReply);
	unsigned short getChksum(unsigned short *addr,int len);
	struct timeval tvSub(struct timeval timeval1,struct timeval timeval2);
private:

	socketStreamI	m_icmpSocket;
	sockaddr_t		m_dstAddr;
	sockaddr_t		m_localAddr;
	t_int8			m_localIp[sizeof("255.255.255.255")];
	t_uint16		m_localPort;
	t_int8			m_dstIp[sizeof("255.255.255.255")];
	t_uint16		m_dstPort;
	t_int32			m_icmp_seq;
	t_int32			m_datalen;
	prosessId		m_pid;

private:
	ICMPSOCKSTATUS	m_status;

private:
	socketCbI*	m_callback;
	void*		m_args;
	t_int32		m_timeOut;

private:
	udpClientList	m_client;						//远程客户端管理
	t_int32			m_clientId;
	mutexI			m_clientMutex;
};




#endif
