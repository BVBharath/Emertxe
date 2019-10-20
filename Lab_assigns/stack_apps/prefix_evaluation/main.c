#include "main.h"

int main()
{
	//initialize the variables
	char infix[20], prefix[20];

	//prompt the user to enter the expression
	printf("enter the expession\n");
	scanf("%s", infix);

	infix_prefix(infix, prefix);

	printf("prefix: ");


	reverse(prefix);

	printf("%s\n", prefix);
	
	prefix_eval(prefix);
}
