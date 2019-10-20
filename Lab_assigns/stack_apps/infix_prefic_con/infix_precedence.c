#include "main.h"

int infix_precedence(char ch)
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

		case ')':
			return 0;


		default : 
			return 9;
	}
}
