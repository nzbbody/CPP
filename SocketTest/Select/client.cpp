#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#define MAXLINE 1024
#define IPADDRESS "127.0.0.1"
#define SERV_PORT 8787

#define max(a,b) (a > b) ? a : b

static void handle_recv_msg(int sockfd, char *buf) 
{
	printf("client recv msg is:%s\n", buf);
	sleep(5);
	write(sockfd, buf, strlen(buf) +1);
}

static void handle_connection(int sockfd)
{
	char sendline[MAXLINE],recvline[MAXLINE];
	int maxfdp,stdineof;
	fd_set readfds;
	int n;
	struct timeval tv;
	int retval = 0;

	while (1) {

		FD_ZERO(&readfds);
		FD_SET(sockfd,&readfds);
		maxfdp = sockfd;

		tv.tv_sec = 5;
		tv.tv_usec = 0;

		retval = select(maxfdp+1,&readfds,NULL,NULL,&tv);

		if (retval == -1) {
			return ;
		}

		if (retval == 0) {
			printf("client timeout.\n");
			continue;
		}

		if (FD_ISSET(sockfd, &readfds)) {
			n = read(sockfd,recvline,MAXLINE);
			if (n <= 0) {
				fprintf(stderr,"client: server is closed.\n");
				close(sockfd);
				FD_CLR(sockfd,&readfds);
				return;
			}

			handle_recv_msg(sockfd, recvline);
		}
	}
}

int main(int argc,char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET,IPADDRESS,&servaddr.sin_addr);

	int retval = 0;
	retval = connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if (retval < 0) {
		fprintf(stderr, "connect fail,error:%s\n", strerror(errno));
		return -1;
	}
	
	sockaddr_in clientAddr;
	sockaddr_in serverAddr;
	socklen_t addrLen = sizeof(sockaddr_in);

	// ��ȡ����ip��port
	getsockname(sockfd, (struct sockaddr*)&clientAddr, &addrLen);
	// ��ȡ�Զ�ip��port
	getpeername(sockfd, (struct sockaddr*)&serverAddr, &addrLen);

	printf("client[%s:%d] connect server[%s:%d]\n",
		inet_ntoa(clientAddr.sin_addr),
		ntohs(clientAddr.sin_port),
		inet_ntoa(serverAddr.sin_addr),
		ntohs(serverAddr.sin_port));

	printf("client send to server.\n");

	char data[64] ={0};
	sprintf(data,"hello server[%s:%d],this is client[%s:%d]",
		inet_ntoa(serverAddr.sin_addr),
		ntohs(serverAddr.sin_port),
		inet_ntoa(clientAddr.sin_addr),
		ntohs(clientAddr.sin_port));
	write(sockfd, data, 64);

	handle_connection(sockfd);

	return 0;
}