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
	if (0 != WSAStartup(dwSockVersion,&wSaData)) //Э�̰汾��
	{
		printf("Arrange Version Failure");
		return -1;
	}
	SOCKET listenSocket;
	listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //����TCP socket
	if (INVALID_SOCKET == listenSocket)
	{
		printf("invalid socket");
		WSACleanup();
		return -1;
	}
	sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr("0.0.0.0");
	sa.sin_port = htons(PORT_NUMBER);//ѡ��һ���˿ں�
	if (bind(listenSocket,(sockaddr *)&sa,sizeof(sa)) < 0) //��
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
			����Ϊʲô�����߳�֮������CloseHandle��
			ԭ���ǣ������̺߳󷵻��߳̾�����´������߳��ں˶������ü�����2��һ�����̱߳���
			һ���Ǵ����̵߳��̣߳�Ҳ����˵��ǰ�̶߳��´������̱߳���һ�����á�
			��ǰ�̵߳���CloseHandle��ʹ���ü�����1�����߳����н��������ü����ټ�1��
			��ʱ��Ϊ0��ϵͳɾ���´������ں˶����������������̡�

			�����ǰ�߳�û�е���CloseHandle�����߳����н��������ü�����1����ʱ��Ϊ1��
			ϵͳ����ɾ���´������ں˶��󡣵�Ȼ�������������н�����ϵͳ���ǻ������Щ�ڴ档
			Ҳ����˵��������CloseHandle���ᵼ�³��������ڼ���ڴ�й¶��

			��Ȼ���⻹Ҫ����ʵ�ʵ���������´������߳����н�����������Ҫʹ�ã��Ͳ�Ҫ����CloseHandle
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