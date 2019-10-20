#include "main.h"

int c_deq(q_array *q, data_t *data)
{
	if(q->count == 0)
	{
		return QUEUE_UNDERFLOW; 
	}

	*data = q->array[q->front];
	q->front = (q->front + 1) % CAPACITY;
	(q->count)--;
	
	return SUCCESS;
	
}
