#include "main.h"

void prefix_eval(char *prefix)
{
	float stack[20];
	int top = -1;
	reverse(prefix);
	while(*prefix)
	{
		if(isdigit(*prefix))
		{
			top++;
			stack[top] = *prefix - 48;
		}
		else
		{
			float t2 = stack[top--];
			float t1 = stack[top--];
			stack[++top] = evaluation(t1, t2, *prefix);
		}
		prefix++;
	}
	printf(" result : %f\n", stack[0]);
}

//
float evaluation(float t2, float t1, char operators)
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


