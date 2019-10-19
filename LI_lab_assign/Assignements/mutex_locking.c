#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int sum,max;

typedef struct
{
	int start;
	int end;
	int arr[50];
}array;

void *thread(void *ptr)
{


}

int main()
{
	pthread_t tid[5];
	array *new,i;
	new = &i;

	for(int i = 0; i < 50 ; i++)
	{
		new->arr[i] = rand() % 100;
	}
	new -> end = 0;
	for(int i = 0; i < 5;i++)
	{
		new -> start = new -> end;

		pthread_create(&tid[i],NULL,thread,new);
	}
}
