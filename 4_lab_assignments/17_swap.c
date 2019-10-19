/*
Title: swap
Author: Bharath
Organization: Emertxe
Descriptions: Swapping the two numbers by passing the address to pointer and making the swapping in the function.

*/

#include <stdio.h>
//prototypes
void swap(int*, int*);
//driver
int main()
{
	//initialize the variabels
	int num1, num2;
	char status;
	do
	{

		//prompt the user to enter the numbers
		printf("enter the number1\n");
		//reading num1
		scanf("%d", &num1);

		printf("enter the number2\n");
		//reading num2
		scanf("%d", &num2);

		printf("initial values before swapping\n");
		printf("num1 : %d\n num2 : %d\n", num1, num2);

		//calling swap function
		swap(&num1, &num2);

		printf("initial values after swapping\n");
		printf("num1 : %d\nnum2 : %d\n", num1, num2);

		printf("do u want to continue.. press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');

}

//function
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}

