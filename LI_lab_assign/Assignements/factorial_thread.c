#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

//Argument for the thread which we want to execute
typedef struct 
{
	int start;
	int end;
	int rem;
	unsigned long result;
}stat;



//Task of the thread
void *thread(void * ptr)
{
	unsigned long count = 1;
	for(int k = ((stat *)ptr)->start;k <((stat *)ptr)->end;k++)
	{
		count = count * k;
	}
	((stat *)ptr) -> result = count;
	return (void *)(&((stat *)ptr) -> result);
}

//Main function
int main()
{
	//Number of threads to be created
	pthread_t tid[NUM_THREADS];
	//Dynamically allocate memory for the structure
	stat *s = malloc(sizeof(s));
	//Return value
	void *retval;
	unsigned long result = 1;
	int num,n,rem=0;

	//User input
	printf("Enter a number:");
	scanf("%d", &num);
	s-> end = 1;
	s -> rem = 0;
	if(num % 3 != 0)
	{
		s->rem = num % 3;
	}
	n = num/3;
	
	for(int i = 0; i < n ;i++)
	{
		s->start = s->end;
		s->end = s->start+s->rem+3;
		if((pthread_create(&tid[i],NULL,thread,s)) != 0)
		{
			perror("pthread_create");
			exit(i);
		}
		s->rem = 0;
		//Waiting for the created thread's return value
		if((pthread_join(tid[i],&retval)) != 0)
		{
			perror("pthread_join");
		}
		result = result * *(unsigned long *)retval;
	}
	printf("Result : %ld\n",result);
	
}
