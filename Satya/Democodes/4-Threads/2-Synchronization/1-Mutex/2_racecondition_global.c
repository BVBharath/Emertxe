/*
Demo: To show the race condition

Compile & Run
./a.out 10000000
*/

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Declare variable as global */
long global;

/* Define the thread function */
void *thread(void *ptr)
{
	int loop = *(int *)ptr;
	long local;
	int i;

	for (i = 0; i < loop; i++)
	{
		global++;
		//sleep(2);
		//printf("%d\n", global);
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	/* Declare two threads */
	pthread_t tid1, tid2;
	
	/* Convert the string to int */
	int n = atoi(argv[1]);

	/* Create thread one */
	if ((errno = pthread_create(&tid1, NULL, thread, &n)) != 0)
	{
		perror("pthread_create()");
		exit(1);
	}

	/* Create thread two */
	if ((errno = pthread_create(&tid2, NULL, thread, &n)) != 0)
	{
		perror("pthread_create()");
		exit(2);
	}

	/* Join thread one */
	if ((errno = pthread_join(tid1, NULL)) != 0)
	{
		perror("pthread_join()");
		exit(3);
	}

	/* Join thread two */
	if ((errno = pthread_join(tid2, NULL)) != 0)
	{
		perror("pthread_join()");
		exit(4);
	}
	
	printf("Global: %ld\n", global);
}
