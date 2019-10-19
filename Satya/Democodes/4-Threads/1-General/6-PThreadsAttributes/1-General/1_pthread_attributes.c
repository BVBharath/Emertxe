/*
1. Use top -H -p <pid> 
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
	//Note: No need to call this
	//pthread_detach(pthread_self());
}

int main()
{
	void *retval;
	pthread_t tid;
	pthread_attr_t attr;

	printf("Main-Thread: MyID: %d\n", getpid());

	//Set the initial attributes
	if (pthread_attr_init(&attr) != 0)
	{
		perror("pthread_attr_init()");
		exit(1);
	}

	//Set the attribute to the detached state
	if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0)
	{
		perror("pthread_attr_setdetachstate()");
		exit(2);
	}


	if (pthread_create(&tid, &attr, thread, "Hai") != 0)
	{
		perror("pthread_create()");
		exit(1);
	}

/*
Note: No need of this
	if (pthread_join(tid, &retval) != 0)
	{
		perror("pthread_join()");
		exit(2);
	}
*/
	//Destroy the attr, which is no longer needed after creating the thread
	if (pthread_attr_destroy(&attr) != 0)
	{
		perror("pthread_attr_destroy()");
		exit(4);
	}	

	sleep(3);
	return 0;
}
