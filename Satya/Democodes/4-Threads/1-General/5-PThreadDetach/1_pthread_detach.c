/*
1. Use top -H -p <pid> 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void *thread(void * ptr)
{
	pthread_detach(pthread_self());
	puts("New-Thread: Created");
	printf("String: %s\n", (char *)ptr);
	sleep(2);
}

int main()
{
	void *retval;
	pthread_t tid;
	int errno;

	printf("Main-Thread: MyID: %d\n", getpid());

	if (pthread_create(&tid, NULL, thread, "Hai") != 0)
	{
		perror("pthread_create()");
		exit(1);
	}

	sleep(3);
	if ((errno = pthread_join(tid, &retval)) != 0)
	{
		if (errno == EINVAL)
		{
			printf("Thread is already detached\n");
			exit(2);
		}
	}
	

	return 0;
}
