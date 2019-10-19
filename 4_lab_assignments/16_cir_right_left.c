/*
Title: Circular_right_left
Author: Bharath
Description: Performing below operations in bitwise
1.circular right
2.circular left

*/

#include <stdio.h>

//prtotype
int binary_form(unsigned);

void circular_right(unsigned , int);

void circular_left(unsigned, int);


//driver
int main()
{

	//initialize the variable
	unsigned  num ;
	int times, options;
	char status;

	do
	{

		//prompt the user to enter the number
		printf("enter the number\n");
		scanf("%d", &num);
		
		//providing options to user
		printf("select one option\n1.circular right\n2.circular left\n");
		scanf("%d", &options);		

		printf("enter how many times\n");
		scanf("%d", &times);
		
		switch(options)
		{
			case 1:
					//calling function
					printf("the given number in binary form:");
					binary_form(num);

					//calling ciruclar right function
					 circular_right(num,times);
					break;

			case 2:
			
					//calling function
					printf("the given number in binary form:");
					binary_form(num);

					//calling circular left function
					circular_left( num, times);
					break;

			default:
					printf("invalid\n");
		}
		printf("do u want continue: press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
}


//functions
//binary form function
int binary_form(unsigned num)
{
	unsigned mask = 1 << (sizeof(int) << 3) - 1;
	for( ; mask; mask >>= 1)
	{
		num & mask ? putchar('1') : putchar('0');
	}
	printf("\n");
}


//circular right funation	
void circular_right(unsigned  num, int times)
{
	num= num >> times | num << (sizeof (int) * 8 - times);
	printf("the binary form after circulating right:");
	binary_form(num);
}

//circular left function
void circular_left(unsigned  num, int times)
{
	num= num << times | num >> (sizeof (int) * 8 - times);
	printf("the binary form after circulating left:");
	binary_form(num);
}



	
