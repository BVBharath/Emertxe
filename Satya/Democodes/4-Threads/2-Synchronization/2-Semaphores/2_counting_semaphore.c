#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

sem_t count;

void *thread(void *ptr)
{
	int k = 5;
	int value;

	/* Acquire the lock */
	sem_wait(&count);

	/* Entering critical section */
	sem_getvalue(&count,&value);
	printf("The semaphore count before loop: %d\n", value);
	//exit(1);
	while(k)
	{
		printf("Inside loop, Value of K=%d\n", k);
		k--;
		sleep(1);
	}

	/* Release the lock */
	sem_post(&count);

	/* Exiting critical section */
	sem_getvalue(&count,&value);
	
	printf("The semaphore count after loop: %d\n", value);		 
}

int main()
{
	int i;
	pthread_t tid[3];

	sem_init(&count, 0, 3);

	for(i = 0; i < 3; i++)
		pthread_create (&tid[i], NULL, &thread, NULL);

	for(i = 0; i < 3; i++)
		pthread_join(tid[i], NULL);

	/*
	 * TODO:  1. Change the value of loop index (i) to 5 and see change in print pattern
	 *        2. Change the semaphore initial value to 5 and see change in print pattern
	 *        3. Change the semaphore initial value to 2 and see change in print pattern
	 *        4. Change the semaphore initial value to 1 (Binary Mutex) and see change in print pattern
	 */

	return 0;
}
