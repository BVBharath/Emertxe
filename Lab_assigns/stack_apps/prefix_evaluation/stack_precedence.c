#include "main.h"

int stack_precedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
			return 3;

		case '^':
			return 6;

		case '(':
			return 0;

		case '#':
			return -1;

		default : 
			return 7;
	}
}
