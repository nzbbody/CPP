#include "linux_socket.h"
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	SOCKET servSocket = socket_create(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0);
	if(servSocket == -1)
	{
		return -1;
	}
	
	if(socket_bind(servSocket, 9000) == false) 
	{
		return -1;
	}
	
	if(socket_listen(servSocket, 5) == false)
	{
		return -1;
	}

	for(int i = 3;i<1000;++i)
	{
		int flags = fcntl(i,F_GETFL,0);
		fcntl(i,F_SETFD,flags|FD_CLOEXEC);	
	}	
	system("./test.sh");	
	getchar();
	return 0;
}

