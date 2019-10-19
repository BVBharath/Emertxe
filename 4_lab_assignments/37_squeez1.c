/*
Title: Squeez.c
Author: Bharath
Organozation: Emertxe
DEscription: The below programme is to substact the second string contents from first string and display the resultant string

*/


#include <stdio.h>
//prototypes
void squeez( char *s1,const char *s2);
//driver
int main()
{
	//initialize the variables
	char a1[100], a2[100];
	char status;
	do
	{

		//prompt the user to enter the first string
		printf("Enter the first string\n");
		scanf("%[^\n]s\n", a1);
		getchar();	

		//prompt the user to enter the second  string
		printf("enter the second string\n");
		scanf("%[^\n]s\n", a2);
		getchar();
		
		//calling squeez function
		squeez(a1, a2);
		printf("The resultant string after squeezing:%s\n", a1);
	

		printf("do u want continue....press(Yy)\n");
		scanf("\n%c", &status);
		getchar();
	}while(status == 'Y' || status == 'y');

}

//functions
void squeez( char *s1,const char *s2)
{
	char *u = s1;
	char *t = s1;
	
	while(*s2)
	{
		for(; *s1; s1++)
		{
			if(*s2 != *s1)
			{
				*t++ = *s1;
					
			}
		}
		*t = '\0';
		s2++;
		s1 = u;
		t = u;
		
	}

}
