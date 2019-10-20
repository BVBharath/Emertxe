#include "main.h"


void infix_postfix(char *infix, char *postfix)
{
	char stack[20];
	stack[0] = '#';

	int n, top = 0;
	while(*infix)
	{
	while((stack_precedence(stack[top])) > (infix_precedence(*infix)))
		{
			*postfix = stack[top];
			postfix++;
			top--;
		}

		if( (stack_precedence(stack[top]))	< (infix_precedence(*infix)))
		{
			top++;
			stack[top] = *infix;
		}
	
		else
		{

			top--;
		}
		infix++;
	}

	while(stack[top] != '#')
	{
		*postfix++ = stack[top--];
	}
	*postfix = '\0';
}
