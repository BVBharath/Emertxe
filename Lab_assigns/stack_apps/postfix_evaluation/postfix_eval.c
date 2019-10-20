#include "main.h"

void postfix_eval(char *postfix)
{
	float stack[20];
	int top = -1;
	while(*postfix)
	{
		if(isdigit(*postfix))
		{
			top++;

			stack[top] = *postfix - 48;
			printf("%f \n", stack[top]);
		}
		else
		{
			float t2 = stack[top--];
			float t1 = stack[top--];
			stack[++top] = evaluation(t1, t2, *postfix);
		}
		postfix++;
	}
	printf(" result : %f\n", stack[0]);
}

//
float evaluation(float t1, float t2, char operators)
{
	switch(operators)
	{
		case '+':
			return (t1 + t2);
		case '-':
			return (t1-t2);
		case '*':
			return (t1*t2);
		case '/':
			return (t1/t2);
		case '^':
			return pow(t1, t2);


	}
}


