#include "main.h"

int push(stack_array *s, data_t data)
{
	if(s->top == CAPACITY - 1)
	{
		printf("stack is full\n");
		return FAILURE;
	}

	(s->top)++;

	s->array[s->top] = data;
	return SUCCESS;

}
