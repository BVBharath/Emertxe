/*
Title : Print_ascii
Author : Bharath
Organization : Emertxe
Description :

*/

#include <stdio.h>

int main()
{
	//initialize the variables
	int i;

	printf("decimal:hexadecimal:octal:ASCII\n");

	//i is varing from 0 to 127
	for (i=0; i <= 127; i++)
	{
		printf("%d\t %x\t %o\t", i, i, i);
		if(i <= 32 || i == 127)
		{
			printf(" Non printable\t");
		}
		else
		{
			printf(" %c\t", i);
		}
		printf("\n");
	}
}
