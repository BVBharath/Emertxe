#include "main.h"

int c_enq(q_array *q, data_t data)
{
	if(q->count == CAPACITY)
	{
		return QUEUE_OVERFLOW; 
	}

	if(q->front == -1)
	{
		(q->front)++;
	}
	q->rear = (q->rear + 1) % CAPACITY;
	(q->count)++;
	q->array[q->rear] = data;
	return SUCCESS;
}
