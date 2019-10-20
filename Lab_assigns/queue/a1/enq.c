#include "main.h"

int enq(q_array *q, data_t data)
{
	if(q->rear == CAPACITY - 1)
	{
		return QUEUE_OVERFLOW;
	}

	q->rear++;
	if((q->front) == -1)
	{
		q->front++;
	}
	q->array[q->rear] = data;
	return SUCCESS;
}
