/*
Title: print_fibbonacci
Author: Bharath
Organization: Emertxe
Description:Printing the fibbonacci series for both in positive and negative seeries upto given limit

*/

#include <stdio.h>
#include <stdlib.h>

//prototypes
int  print_fibbonacci(int, int, int, int);
int print_fibbonacci_negative(int, int, int, int);

//driver
int main()
{
	//initialize the variables
	int a=0, b=1, sum=0, limit;
	char status;
	
	do
	{
		printf("enter the limit\n");
		scanf("%d", &limit);
		
		//validation
		if(limit == 0)
		{
			printf("invalid range...\n");

		}

		else
		{

			if(limit > 0)
			{

			printf("fibbonacci series is: ");
			printf("%d ", a);

			//calling the positive fibonacci series function
			print_fibbonacci(a, b, sum, limit);
			printf("\n");
			}

			else if(limit < 0)
			{
				printf("negative fibbonacci series is:");
				printf("%d ", a);
				//calling the negative fibonacci series function
				print_fibbonacci_negative(a, b, sum, limit);
				printf("\n");
			}
		}
		printf("do u want continue...press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'y' || status == 'Y');
	return 0;
}
//functions
int print_fibbonacci(int a, int b, int sum, int limit)
{
	if(sum <= limit)
	{
		sum = a + b;
		a = b;
		b = sum;
		printf("%d ", a);

		return print_fibbonacci(a, b, sum, limit);
	}

	return -1;

}

//
int print_fibbonacci_negative(int a, int b, int sum, int limit)
{

	if (abs(sum) <= abs(limit))
	{
		sum = a - b;
		a = b;
		b = sum;
		printf("%d ", a);
		return print_fibbonacci_negative(a, b, sum,limit);
	}
	return -1;
}
