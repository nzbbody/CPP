

#ifndef _EZ_NET_SHELL_H
#define _EZ_NET_SHELL_H



#include <ez/ez_shell.h>

#include <net_framework/tcp_listen_i.h>

#include <ez/ez_shell_tree.h>

#include <ez/ez_vty.h>


class ezAgentShell;
class ezPtyShell : public ezShell, public socketCbI
{
public:

public:
	ezPtyShell(ezAgentShell *agent);

	virtual ~ezPtyShell();

public:
	virtual t_int32 onData(t_handler handlerId, t_int8 *buff, t_int32 buffLen, void *arg);
		
	virtual t_int32 onConnect(t_handler handlerId, void *arg);
	
	virtual t_int32 onInputTimeout(t_handler handlerId, void *arg);
	

public:
	t_int32 start();
	t_int32 stop();
	
	t_int32 ptyInit();
	t_int32 ptyExit();

	

	t_int32 output(t_int8 *buffer, t_int32 bufferLength);
	

public:
	peerStreamI _peer;
private:

	ezAgentShell *mAgent;

	ezVty *mVty;
	
};


class ezPtyManagerI
{
public:
	t_int32 add(ezPtyShell *pty);
	t_int32 del(ezPtyShell *pty);
	t_int32 closeAll();

private:
	listI<ezPtyShell *> ezPtyList;
};


/**
	网络shell 实现类型
*/
class ezAgentShell : public socketCbI, public ezPtyManagerI
{

	
public:
	ezAgentShell();
	virtual ~ezAgentShell();


public: 
	virtual t_int32 onAccept(void **handleId, void *arg);
	
public:
	t_int32 start();
	t_int32 start(t_int32 agentPort);
	t_int32 stop();

	t_int32 agentInit();
	t_int32 agentInit(t_int32 agentPort);
	t_int32 agentExit();

	
public:
	t_int32 addPty(ezPtyShell *pty);
	t_int32 delPty(ezPtyShell *pty);
	t_int32 closeAllPty();

private:
	tcpListenI *_listener;
	
};

#endif

