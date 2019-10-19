#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void *thread_func(void *ignored_argument)
{
	int err;

    /* Disable cancellation for a while, so that we don't
    immediately react to a cancellation request */
    err = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    if (err != 0)
	{
        printf("thread_func(): can't disable cancellation [%s]\n", strerror(err));
        exit(EXIT_FAILURE);
	}
    
    printf("thread_func(): started; cancellation disabled\n");
    
    sleep(5);
    
    /* Enable thread cancellation */
    printf("thread_func(): about to enable cancellation\n");
    err = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    if (err != 0)
	{
        printf("thread_func(): can't enable cancellation [%s]\n", strerror(err));
        exit(EXIT_FAILURE);
	}

	/* Is not a cancellation point, Will not get cancelled in loop */
	while(1);

    /* sleep() is a cancellation point */
	sleep(100);							/* Should get canceled while we sleep */

    /* Should never get here */
    printf("thread_func(): not canceled!\n");

}

int main(void)
{
	pthread_t thr;
    void *res;
    int err;

    /* Create a thread and then send it a cancellation request */
    err = pthread_create(&thr, NULL, &thread_func, NULL);
    if (err != 0)
	{
        printf("main(): can't create thread [%s]\n", strerror(err));
        exit(EXIT_FAILURE);
	}

    /* Give thread a chance to get started */
    sleep(2);           

    /* Send a cancellation request */
    printf("main(): sending cancellation request\n");
    err = pthread_cancel(thr);
    if (err != 0)
	{
        printf("main(): can't send cancellation request[%s]\n", strerror(err));
        exit(EXIT_FAILURE);
	}

    /* Join with thread to see what its exit status was */
    err = pthread_join(thr, &res);
    if (err != 0)
	{
        printf("main(): can't join thread[%s]\n", strerror(err));
        exit(EXIT_FAILURE);
	}
    
	if (res == PTHREAD_CANCELED)
    {
    	printf("main(): thread was canceled\n");
    }    
    else
    {
    	printf("main(): thread wasn't canceled (shouldn't happen!)\n");
	}
}
