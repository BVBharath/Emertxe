/*
1. This code demonstrates the usage of the pthread creation.
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *thread(void *ptr)
{
	puts("Hi, I am new thread");
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

	sleep(2);
	puts("Main-Thread: I am terminating");

	return 0;
}
