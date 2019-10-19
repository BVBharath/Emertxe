/*
Title:strtok.c
Author: Bharath
Organization:Emertxe
Description:

*/

#include <stdio.h>
#include <string.h>

//prototype
void mystr(char *p, char *q);

//driver
int main()
{
	//initialize the variables
	char a1[100] = {0}, a2[20], status;


	do
	{
		//Prompt + Read from the user of str1
		printf("Enter first string:");
		scanf("%[^\n]s", a1);
		getchar();

		//Prompt + Read from the user str2
		printf("Enter second string:");
		scanf("%[^\n]s", a2);
		getchar();

	
		//caling function
		mystr(a1, a2);

		//do u want continue part
		printf("do u want to continue...press(Yy)\n");
		scanf("\n%c", &status);
		getchar();
	}while(status =='Y' || status == 'y');
  
}

//functions
void mystr(char *p, char *q)
{

	//initilaize the function local variables
	char *temp1 = q;
	char *temp2 = p;
	int n = strlen(p);
	char *a3[10];
	int init = 0;
	int count = 0;

	//logic
	while(*temp2)
	{
		while(*temp1)
		{
			if(*temp2 == *temp1)
			{
				*temp2 = '\0';
			}
			temp1++;
		}
		temp1 = q;
		temp2++;
	}

	if(*p != '\0')
	{
		a3[init] = p;
		init++;
	}

	while(count < n)
	{
		if(*p++ == '\0' && *p != '\0')
		{
			a3[init] = p;
			init++;
		}
		count++;

	}

	//printing the tokens
	for(int i = 0; i < init; i++)
	{
		printf("token%d: %s\n", i, a3[i]);
	}


}
