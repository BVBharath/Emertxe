/*
1. 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *thread(void * ptr)
{
	puts("New-Thread: Created");
	printf("String: %s\n", (char *)ptr);
	return (char *)strlen(ptr);
}

int main()
{
	void *retval;
	pthread_t tid;

	if (pthread_create(&tid, NULL, thread, "Hai") != 0)
	{
		perror("pthread_create()");
		exit(1);
	}

	if (pthread_join(tid, &retval) != 0)
	{
		perror("pthread_join()");
		exit(2);
	}

	printf("Main-Thread: New-Thread returned with the value: %ld\n", (long)retval);

	return 0;
}
