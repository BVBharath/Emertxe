/*
Title: Stringreverse
Author: Bharath
Organization: Emertxe
Description: To perform reversing of a string using functions and pointers.
*/


#include <stdio.h>
#include <string.h>
//prototypes
void string_reverse(char*);
//driver
int main()
{

	//initialize the variable
	char status;
	char string[30];
	do
	{
		printf("enter the string\n");
		scanf("\n%[^:\n]s", string);
	
		string_reverse(string);
		printf("%s\n", string);

		//continue part
		printf("do u want to continue..press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
	return 0;
}
//functions
void string_reverse(char *s1)
{
	
	int n = strlen(s1);
	char *s2 = s1 + n - 1;

	while(s1 < s2)
	{
		char temp = *s2;
		*s2 = *s1;
		*s1 = temp;
		s1++;
		s2--;
	}
	

}
