#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutexA;
pthread_mutex_t mutexB;


void* thread_func1(void*)
{
	pthread_mutex_lock(&mutexA);
	printf("thread1 lock A\n");
	sleep(5);

	{
		pthread_mutex_lock(&mutexB);
		printf("thread1 lock B\n");
		sleep(5);
		pthread_mutex_unlock(&mutexB);
	}

	pthread_mutex_unlock(&mutexA);
}
void* thread_func2(void*)
{
	sleep(10);
	pthread_mutex_lock(&mutexB);
	printf("thread2 lock B\n");
	sleep(5);

	{
		pthread_mutex_lock(&mutexA);
		printf("thread2 lock A\n");
		sleep(5);
		pthread_mutex_unlock(&mutexA);
	}

	pthread_mutex_unlock(&mutexB);
}


int main()
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_mutex_init(&mutexA,NULL);
	pthread_mutex_init(&mutexB,NULL);


	if(pthread_create(&thread1,NULL,thread_func1,NULL) == -1)
	{
		printf("create thread1 error !\n");
		exit(1);
	}

	if(pthread_create(&thread2,NULL,thread_func2,NULL) == -1)
	{
		printf("create thread2 error!\n");
		exit(1);
	}

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	pthread_mutex_destroy(&mutexA);
	pthread_mutex_destroy(&mutexB);

	return 0;
}

