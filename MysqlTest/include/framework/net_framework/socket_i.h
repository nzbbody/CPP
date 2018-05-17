
/**
 *	Copyright (C) 2012 ZHEJIANG  DAHUA  SYSTEM ENGINEERING  CO., LTD
 *
 *	@file:			socket_i.h
 * 	@brief:			socket_i.h 定义通用socket类
 * 	@author:			zhang_sunbo 
 *	@note:	
 */




#ifndef _SOCKET_I_H
#define _SOCKET_I_H


#include <data_types.h>
#include <os/os_socket_i.h>
#include <io_data/io_data_i.h>

#define SOCKETRCVBUF (65536*2)
#define SOCKETSNDBUF 65536
class DLL_EXPORT socketCbI
{
public:
	virtual ~socketCbI() {};

public:
	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg)
	{
		(void)handlerId;
		(void)buff;
		(void)buffLen;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onData(t_handler handlerId, t_handler peer, t_int8 *buff, t_int32 buffLen, void *arg)
	{
		(void)handlerId;
		(void)peer;
		(void)buff;
		(void)buffLen;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onClose(t_handler handlerId, void *arg)
	{
		(void)handlerId;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onConnect(t_handler handlerId, void *arg)
	{
		(void)handlerId;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onConnect(t_handler handlerId, t_handler peer, t_int8* remoteIp, t_uint16 remotePort)
	{
		(void)handlerId;
		(void)peer;
		(void)remoteIp;
		(void)remotePort;
		return E_OK;
	}
	virtual t_int32 onDisconnect(t_handler handlerId, void *arg)
	{
		(void)handlerId;
		(void)arg;
		return E_OK;
	}

	virtual t_int32 onAccept(void **handlerId, void *arg)
	{
		(void)handlerId;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onOutput(t_handler handlerId, void* arg)
	{
		(void)handlerId;
		(void)arg;
		return -99;	
	}
	virtual t_int32 onInputTimeout(t_handler handlerId, void *arg)
	{
		(void)handlerId;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onOutputTimeout(t_handler handlerId, void *arg)
	{
		(void)handlerId;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onExpection(t_handler handlerId, void *arg)
	{
		(void)handlerId;
		(void)arg;
		return E_OK;
	}
	virtual t_int32 onConnectFailed(t_handler handlerId, t_int32 errorId, void* arg)
	{
		(void)handlerId;
		(void)errorId;
		(void)arg;
		return E_OK;
	}
};

class DLL_EXPORT socketI : public ioDataI
{

public:
	socketI();
	virtual ~socketI();


public:
	t_int32 open(t_int32 family, t_int32 type, t_int32 protocol);
	t_int32 close();


	t_int32 setOption(t_int32 level, t_int32 option, void *optVal, socklen_t optLen);
	t_int32 getOption(t_int32 level, t_int32 option, void *optVal, socklen_t *optLen);

	t_int32 errCheck();
};

typedef struct socketData
{
	t_int8 *recvbuff;
	t_int32 recvbuffLen;
	
}socketdata_t;


class socketDataI
{
public:
	socketDataI();
	~socketDataI();

private:
	t_int32 dataInit();
	t_int32 dataExit();
public:
	t_int32 getRecvBuff(t_int8 **buff, t_int32 *buffLen);

private:
	thread_key_t socketKey;

	t_int32 recvbuffLen;
};


t_int32 socketGetRecvbuff(t_int8 **buff, t_int32 *buffLen);
t_int32 socketPair(t_int32 handle[2]);

#endif

