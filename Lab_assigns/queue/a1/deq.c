#include "main.h"

int deq(q_array *q, data_t *data)
{
	if(q->front ==  - 1)
	{
		return QUEUE_UNDERFLOW;
	}

	*data = q->array[q->front];
	q->front++;
	if((q->front) > (q->rear))
	{
		q->front = -1;
		q->rear = -1;
	}
	return SUCCESS;
}
