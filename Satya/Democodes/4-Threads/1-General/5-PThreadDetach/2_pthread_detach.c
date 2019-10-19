/* Create Detached Thread */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread(void *arg)
{
	printf("New Thread: Hello\n");
//	pause();
}

int main(void)
{
	printf("PID : %d\n", getpid());
    
    int err;
    pthread_t tid;
    pthread_attr_t attr;
	
	/* Prepare attribute with Detached state */
	err = pthread_attr_init(&attr);
    if (err != 0)
	{
        printf("can't set attribute :[%s]\n", strerror(err));
        exit(EXIT_FAILURE);
	}

	err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (err != 0)
	{
        printf("can't set attribute :[%s]\n", strerror(err));
        exit(EXIT_FAILURE);
	}

	/* Create Detached thread */
    err = pthread_create(&tid, &attr, thread, NULL);
    if (err != 0)
	{
        printf("can't create thread :[%s]\n", strerror(err));
        exit(EXIT_FAILURE);
	}

    printf("Thread created successfully\n");

	sleep(2);
	/* Try to join detached Thread */
	err = pthread_join(tid, NULL);
    if (err == 0)
	{
		printf("Thread joining successful\n");
	}
	else
	{
        printf("Unable to join thread :[%s]\n", strerror(err));
	}
}
