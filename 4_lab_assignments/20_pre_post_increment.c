/*
Title: Pre_Post_increment
Author: Bharath
Organization: Emertxe
Description:The below programme is used to increment the given number using bitwise operations.
*/

#include <stdio.h>

//prototypes
int preincrement(int*);
int postincrement(int*);
//driver
int main()
{
	//intialize the variables
	int num, options, i;
	char status;

	do
	{
	
		//prompt the user to enter the number
		printf("enter the number\n");
		//reading the number
		scanf("%d", &num);

		printf("select one operatiob:\n1.pre increment\n2. post increment\n");
		//reading the options
		scanf("%d", &options);
		switch(options)
		{
			case 1:
					//callling preincrement function
					i = preincrement(&num);
					printf("i = %d\n num = %d\n", i, num);
					break;

			case 2:
					//calling postincrement function
					i = postincrement(&num);
					printf("i = %d\n num = %d\n", i, num);
					break;

			default: 
					printf("invalid");
		}

		printf("do u want continue..press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
}
//functions
//preincrement function
int preincrement(int *p)
{
	int count=0, i;
	if(!(*p & 1))
	{
		*p = *p | 1;
	}
	else
	{
		for(i=1; i < 32; i++)
		{
			count++;
			if(!(*p & (1 << i)))
			{
				break;
			}
		}
		*p = *p | (1 << count);
		*p = *p & (~0 << count);
	}
	return *p;
}

//post increment function
int postincrement(int *p)
{
	
	int count=0, i, j = *p;
	if(!(*p & 1))
	{
		*p = *p | 1;
	}
	else
	{
		for(i=1; i < 32; i++)
		{
			count++;
			if(!(*p & (1 << i)))
			{
				break;
			}
		}
		*p = *p | (1 << count);
		*p = *p & (~0 << count);
	}
	return j;
}
