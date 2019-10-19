/*
1. Use top -H -p <pid> 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_attr_t attr;
size_t stacksize;
void *thread(void * ptr)
{
	size_t mystacksize;

//	printf("thread stack size: %lu\n", stacksize);
	puts("New-Thread: Created");
	pthread_attr_getstacksize (&attr, &mystacksize);

	/* Print the stack size */
	printf("Default stack size: %lu\n", mystacksize);
}

int main()
{
	void *retval;
	pthread_t tid;
//	size_t stacksize;

	printf("Main-Thread: MyID: %d\n", getpid());

	/* Set the initial attributes */
	if (pthread_attr_init(&attr) != 0)
	{
		perror("pthread_attr_init()");
		exit(1);
	}

	/* Get the stack size */
	if (pthread_attr_getstacksize(&attr, &stacksize) != 0)
	{
		perror("pthread_attr_setdetachstate()");
		exit(2);
	}

	/* Print the default stack size */
	printf("Default stack size: %lu\n", stacksize);
#if 1
	/* Calculate the new stack size */
	stacksize = stacksize * 2;

	/* Change the stack size to double of the previous size */
	pthread_attr_setstacksize(&attr, stacksize);

	/* Print the default stack size */
	printf("Default stack size: %lu\n", stacksize);
	
	/* Create the new thread */
	if (pthread_create(&tid, &attr, thread, "Hai") != 0)
	{
		perror("pthread_create()");
		exit(1);
	}
	sleep(3);
#endif
	return 0;
}
