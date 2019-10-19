/*
Title: Space.c
Author: Bharath
Organization: Emertxe
Description: The below programme is to remove the extra spaces between the substrings in single statemnt. Make it as one meaning full sentence by giving one space gap between the substring.

*/

#include <stdio.h>

//prototyps
void space(char *s1);

//driver
int main()
{
	//initalize the variables
	char status;
	do
	{
		char a[40]= {0};

		//prompt the user to enter the string
		printf("enter the string\n");
		scanf("\n%[^\n]s", a);

		//calling the function
		space(a);
		printf("%s\n", a);
		printf("do u want continue...press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');

}
//functions
void space(char *s1)
{
	char *s2 = s1;
	int count=0;
	while(*s1)
	{
	
		if(*s1 != ' ')
		{
			count = 1;
			*s2 = *s1;
			s2++;
		}
		s1++;
		if(*s1 == ' ' && count)
		{
			*s2 = ' ';
			count = 0;
			s2++;
		}
	}
	*s2 = '\0';
}
