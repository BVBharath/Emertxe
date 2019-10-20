#include "main.h"

int peep(stack_array s)
{
	if(s.top == -1)
	{
		return STACK_UNDERFLOW;
	}

	while(s.top > -1)
	{
		printf("data : %d\n", s.array[s.top]);
		(s.top)--;
	}
	return SUCCESS;
}
