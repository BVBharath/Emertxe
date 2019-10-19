/*
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *thread(void *ptr)
{
	int i;
	printf("New-Thread: Created\n");

	for (i = 0; ;i++)
	{
		printf("Loop %d\n", i);
		sleep(1);
	}

	//This point will not reach
	return NULL;
}

int main()
{
	pthread_t tid;
	void *res;

	if (pthread_create(&tid, NULL, thread, NULL) != 0)
	{
		perror("pthread_create()");
		exit(1);
	}
	
	sleep(3);

	if (pthread_cancel(tid) != 0)
	{
		perror("pthread_cancel()");
		exit(2);
	}

	if (pthread_join(tid, &res) != 0)
	{
		perror("pthread_join()");
		exit(3);
	}

	if (res == PTHREAD_CANCELED)
	{
		puts("Thread Cancelled");
	}
	else
	{
		puts("Thread not Cancelled");
	}

	return 0;
}
