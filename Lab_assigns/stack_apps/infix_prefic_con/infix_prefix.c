#include "main.h"


void infix_prefix(char *infix, char *prefix)
{
	char stack[20];
	stack[0] = '#';

	int n, top = 0;

	reverse(infix);
	printf("%s\n", infix);
	while(*infix)
	{
	while((stack_precedence(stack[top])) > (infix_precedence(*infix)))
		{
			*prefix = stack[top];
			prefix++;
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
		*prefix++ = stack[top--];
	}
	*prefix = '\0';
}
