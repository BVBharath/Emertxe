/*
1. This code demonstrates the usage of the pthread creation.
2. If the main thread calls pthread_exit() instead of calling exit() or performing a return, then the other threads continue to execute.
3. If main thread exits normally, entire process would terminate.
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int retval;

void *thread(void *ptr)
{
	//sleep(5);
	puts("Hi, I am new thread");
	exit(1);
}

int main()
{
	//Declare the variable to hold the thread ID
	pthread_t tid;

	puts("Hi, I am the main thread");
	puts("Now, I will create the new thread");
	sleep(3);

	//Create the new thread
	if ((pthread_create(&tid, NULL, thread, NULL)) != 0)
	{
		perror("pthread_create");
		exit(1);
	}

	sleep(5);
	pthread_exit(&retval);
	puts("Main-Thread: New thread terminated");
	printf("Return value: %d\n", retval);
	puts("Main-Thread: I am terminating");


	return 0;
}
