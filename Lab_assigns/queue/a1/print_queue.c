#include "main.h"

int print_queue(q_array q)
{
	if(q.front == -1)
	{
		return QUEUE_UNDERFLOW;
	}

	while(q.front <  CAPACITY)
	{
		printf("data : %d\n", q.array[q.front]);
		(q.front)++;
	}
	return SUCCESS;
}
