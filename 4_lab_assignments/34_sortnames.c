/*
Title: Sortnames
Author: Bharath
Organization: Emertxe
Description: The below programme is to sort the names in alphabet order.

*/

#include <stdio.h>
#include <string.h>

//prototypes
void print(char (*p)[10], int n);

//driver
int main()
{

	//initialize the variables
	int n;	
	char status;

	do
	{
		//prompt the user to enter number of names
		printf("how many strings u want to enter\n");
		scanf("%d", &n);

		//initilizing the arrays
		char a[n][10];
		char temp[10];
		char (*p)[10] = a;

		//prompt the user to enter the strings
		printf("enter the %d stringsof maximum length 10\n", n);
		for(int i=0; i < n; i++)
		{
			scanf("%s", a[i]);
		}

		//printing the strings before sorting
		printf("\nbefore sorting\n");
		print(a, n);
		putchar('\n');

		//logic
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{

				if(strcmp(a[i], a[j])  > 0)
				{
					strcpy(temp, a[i]);
					strcpy(a[i], a[j]);
					strcpy(a[j], temp);
				}
			}
		}
	
		//printing after sorting
		printf("after sorting\n");
		print(a, n);
		putchar('\n');

		//continue....part
		printf("do u want to continue..press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');


}


//functions
void print(char (*p)[10], int n)
{
	
	for(int i=0; i < n; i++)
	{
		printf("%s\n", p[i]);
	
	}
	
}
