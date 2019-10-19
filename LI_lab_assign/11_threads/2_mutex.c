/*

 */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Declare variable as global */
long sum, max;

/* Declare the mutex */
pthread_mutex_t mtx;

struct addition
{
	int start;
	int end;
	int *a;
}s;


/* Define the thread function */
void *thread(void *ptr)
{
	/* Lock the mutex */
	if (pthread_mutex_lock(&mtx) != 0)
	{
		puts("Unable to lock the mutex");
		exit(1);
	}

	for(int i = s.start; i <= s.end; i++)
	{
		
		if(s.a[i] > max)
		{
			max = s.a[i];
		}
		sum += s.a[i];

	}
	s.start = s.start + 10;
	s.end = s.end + 10;

	/* Unlock the mutex */
	if (pthread_mutex_unlock(&mtx) != 0)
	{
		puts("Unable to unlock the mutex");
		exit(2);
	}



	return NULL;
}

//driver
int main( )
{
	/* Declare five threads */
	pthread_t tid[5];

	s.a = malloc(50 * sizeof(int));
	s.start = 0;
	s.end = 9;

	for(int j = 0; j < 50; j++)
	{
		s.a[j] = rand() % 200;
		printf("%d\t", s.a[j]);
	}
	/* Dynamic Init of the mutex */
	if (pthread_mutex_init(&mtx, NULL) != 0)
	{
		printf("\nPthread: mutex init failed\n");
		return 1;
	}

	/* Create thread one */
	for(int i = 0; i < 5; i++)
	{
		if ((errno = pthread_create(&tid[i], NULL, thread, NULL)) != 0)
		{
			perror("pthread_create()");
			exit(1);
		}
	}
	
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	pthread_join(tid[4], NULL);

	/* Destroy the mutex */
	pthread_mutex_destroy(&mtx);

	printf("max : %ld\n", max);
	printf("sum : %ld\n", sum);
}

