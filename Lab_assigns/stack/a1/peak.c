#include "main.h"

int peak(stack_array *s, data_t *data)
{
	if(s->top == -1)
	{
		return STACK_UNDERFLOW;
	}

	*data = s->array[s->top];

	
	return SUCCESS;
}
