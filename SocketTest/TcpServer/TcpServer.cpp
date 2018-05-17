#include "stdafx.h"
#include <Winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#define PORT_NUMBER 12345
#define MAX_BUF_SIZE 1024



DWORD WINAPI CommWithClient(PVOID param)
{
	char sendBuf[MAX_BUF_SIZE] = {0};
	char recvBuf[MAX_BUF_SIZE] = {0};
	strcpy(sendBuf,"this is server");

	SOCKET* acceptSocket = (SOCKET*)(param);
	send(*acceptSocket, sendBuf, (int)strlen(sendBuf), 0);

	while(1)
	{
		memset(sendBuf,0,MAX_BUF_SIZE);
		memset(recvBuf,0,MAX_BUF_SIZE);
		int nRecv = recv(*acceptSocket, recvBuf, MAX_BUF_SIZE, 0);
		if (nRecv > 0)
		{
			printf("Server Peer[%d] Recv[%s]\n",*acceptSocket,recvBuf);
			// echo client
			send(*acceptSocket, recvBuf, (int)strlen(recvBuf), 0);

			if(strcmp(recvBuf,"bye") == 0)
			{
				closesocket(*acceptSocket);
				break;
			}
		}
	}

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wSaData;
	WORD dwSockVersion = MAKEWORD(2,2);
	if (0 != WSAStartup(dwSockVersion,&wSaData)) //协商版本号
	{
		printf("Arrange Version Failure");
		return -1;
	}
	SOCKET listenSocket;
	listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //创建TCP socket
	if (INVALID_SOCKET == listenSocket)
	{
		printf("invalid socket");
		WSACleanup();
		return -1;
	}
	sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr("0.0.0.0");
	sa.sin_port = htons(PORT_NUMBER);//选择一个端口号
	if (bind(listenSocket,(sockaddr *)&sa,sizeof(sa)) < 0) //绑定
	{
		closesocket(listenSocket);
		return -1;
	}
	listen(listenSocket,2);
	sockaddr_in addr_client;
	int nAddrLen = sizeof(addr_client);
	while(TRUE)
	{
		//SOCKET acceptSocket = accept(nSocket,(sockaddr *)&amp;addr_client,&amp;nAddrLen);
		SOCKET acceptSocket = accept(listenSocket,NULL,NULL);
		if (INVALID_SOCKET == acceptSocket)
		{
			printf("failure to accept");
			continue;
		}
	
		/*
			这里为什么创建线程之后，马上CloseHandle？
			原因是：创建线程后返回线程句柄，新创建的线程内核对象引用计数是2，一个是线程本身，
			一个是创建线程的线程，也就是说当前线程对新创建的线程保持一个引用。
			当前线程调用CloseHandle，使引用计数减1，新线程运行结束后，引用计数再减1，
			这时候为0，系统删除新创建的内核对象，这是正常的流程。

			如果当前线程没有调用CloseHandle，新线程运行结束后，引用计数减1，这时候为1，
			系统不会删除新创建的内核对象。当然，整个程序运行结束后，系统还是会回收这些内存。
			也就是说，不调用CloseHandle，会导致程序运行期间的内存泄露。

			当然，这还要考虑实际的需求，如果新创建的线程运行结束，后续还要使用，就不要调用CloseHandle
		*/
		HANDLE hThread = CreateThread(NULL,0,CommWithClient,&acceptSocket,0,NULL);
		CloseHandle(hThread);
		
		//char sendBuf[MAX_BUF_SIZE] = {0};
		//char recvBuf[MAX_BUF_SIZE] = {0};
		//strcpy(sendBuf,"this is server");
		//send(acceptSocket, sendBuf, (int)strlen(sendBuf), 0);
		//int nRecv = recv(acceptSocket, recvBuf, MAX_BUF_SIZE, 0);
		//if (nRecv > 0)
		//{
		//	printf("Server Peer[%d] Recv[%s]\n",acceptSocket,recvBuf);

		//	if(strcmp(recvBuf,"bye") == 0)
		//	{
		//		closesocket(acceptSocket);
		//	}
		//}			
	}


	system("pause");
	return 0;
}