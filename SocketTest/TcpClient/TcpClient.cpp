#include "stdafx.h"
#include <Winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#define MAX_BUF_SIZE 1024
#define PORT_NUMBER 12345
int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wSaData;
	WORD dwSockVersion = MAKEWORD(2,2);
	if (0 != WSAStartup(dwSockVersion,&wSaData)) //协商版本号
	{
		printf("Arrange Version Failure");
		return -1;
	}

	sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr("127.0.0.1");
	sa.sin_port = htons(PORT_NUMBER);

	for(int i = 0;i<5; ++i)
	{
		SOCKET nSocket;
		nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //创建TCP socket
		if (INVALID_SOCKET == nSocket)
		{
			printf("invalid socket");
			WSACleanup();
			return -1;
		}

		if ( 0 != connect( nSocket,( const SOCKADDR * )&sa, sizeof(sa) ) )
			return -1;
		char buf[MAX_BUF_SIZE] = {0};
		char tmp[MAX_BUF_SIZE] = {0};
		strcpy(tmp,"this is Client!");
		int nRecv = 0;
		nRecv = recv(nSocket, buf, MAX_BUF_SIZE, 0);
		if (nRecv > 0)
		{
			printf("Client Peer[%d] Recv[%s]\n",nSocket,buf);
			send(nSocket, tmp, (int)strlen(tmp), 0);
		}

	}

	
	

	//closesocket(nSocket);
	//WSACleanup();

	system("pause");
	return 0;
} 