#include "main.h"

int stack_precedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 2;

		case '*':
		case '/':
			return 4;

		case '^':
			return 5;

		case '(':
			return 0;

		case '#':
			return -1;

		default : 
			return 9;
	}
}
