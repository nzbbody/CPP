/*
 * JsonRpcFrame.h
 *
 *  Created on: Jun 7, 2012
 *      Author: root
 */

#ifndef JsonRpcFrame_H_
#define JsonRpcFrame_H_
#include <iostream>
#include <json/json.h>
#include <jsonrpc/jsonrpc.h>
using namespace std;
/*
 *  JsonRPC Frame
 *  JsonRpcFrameClient client(1=TCP ,0=UDP, ServerPort)
 *
 *
 */


class JsonRpcFrameClientI
{
public:
	JsonRpcFrameClientI(int nType, std::string servername, int port);
	Json::Value DoRemote(const std::string funName, const Json::Value &param,bool bNotify=false);
	~JsonRpcFrameClientI();

private:
	Json::Rpc::Client *m_client;
	int m_init_result;
};

class JsonRpcFrameServerI
{
public:
	JsonRpcFrameServerI(int nType, int port);
	~JsonRpcFrameServerI();
	Json::Rpc::Server* getServer();
	void start();
private:
	Json::Rpc::Server *m_server;
	int m_error;
};
#define RPC_Server_AddMethod_Macro(Server,RPCClass,RPCInstance,RPCFun,RPCDescFunName) \
		Server.getServer()->AddMethod(new Json::Rpc::RpcMethod<RPCClass>(RPCInstance, RPCFun, RPCDescFunName, a.GetDescription()));


#endif /* JsonRpcFrame_H_ */
