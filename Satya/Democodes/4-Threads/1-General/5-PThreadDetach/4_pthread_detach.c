#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

void *thread_func(void *arg)
{
	sleep(10);
}

int main(void)
{
	printf("PID : %d\n", getpid());
    int i = 0;
    int err;
    pthread_t tid;

	/* Create thread with default attribute */
    err = pthread_create(&tid, NULL, thread_func, NULL);
    if (err != 0)
	{
        printf("can't create thread :[%s]\n", strerror(err));
        exit(EXIT_FAILURE);
	}

    printf("Thread created successfully\n");
	
	/* Change Thread detach state */
	pthread_detach(tid);
	
	/* Try to join Thread detached */
	err = pthread_join(tid, NULL);
    if (err == 0)
	{
		printf("Thread joining successful\n");
	}
	else
	{
		errno = err;
		perror("pthread_join():");
        printf("Unable to join thread :[%s]\n", strerror(err));
	}

}
