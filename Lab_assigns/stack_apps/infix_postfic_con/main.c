#include "main.h"

int main()
{
	//initialize the variables
	char infix[20], postfix[20];

	//prompt the user to enter the expression
	printf("enter the expession\n");
	scanf("%s", infix);

	infix_postfix(infix, postfix);

	printf("postfix: ");

	printf("%s\n", postfix);
}
