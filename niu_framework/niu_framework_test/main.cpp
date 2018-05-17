#include "thread/thread.h"
#include <stdio.h>


void* func1(void* param)
{
	printf("This is testThreadCallBack\n");
	return NULL;
}

int main(int argc, char* argv[])
{
	niu::Thread pThread(func1,NULL);

	getchar();
	return 0;
}