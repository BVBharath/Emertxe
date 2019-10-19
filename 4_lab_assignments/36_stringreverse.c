/*
Title : stringreverse
Author : Bharath
Organization: Emertxe
Description: Reverse of given given string using recursive method ny the use of pointers and functions 

*/

#include <stdio.h>

//prototypes
int string(char *s1);

//driver
int main()
{
	//initialize he variables
	char str1[100], status ;

	do
	{

		//prompt the user to enter he string
		printf("enter the string\n");
		scanf("\n%[^:\n]s", str1);

		//calling function
		string(str1);
		printf("\n");

		printf("do u want continue...press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
}

//functions
int string(char *s1)
{
	if (*s1)
	{
		//calling recursively
		string(s1 + 1);
		printf("%c", *s1);
	}
	return -1;
	
}


