#include "main.h"

int pop(stack_array *s, data_t *data)
{
	if(s->top == -1)
	{
		return STACK_UNDERFLOW;
	}

	*data = s->array[s->top];

	s->top--;
	return SUCCESS;
}
