/*
Title: Bitwise_lsb
Author: Bharath
Organization: Emertxe
Description:Read the two integer numbers (num,i) from the user, Read 0 <= a <= b <= 31.Put b-a+1 lsb's of the number into b:a position of i value. print the new i value. 

*/

#include <stdio.h>

//prototype
unsigned bitwise_lsb(unsigned, unsigned, int, int );


//driver
int main()
{
	//initialize the variables
	unsigned num,i;
	int a,b,I1;
	char status;

	do
	{
		//prompt the user to enter the number
		printf("enter the number\n");
		scanf("%d", &num);
		
		//prompt the user to enter other number
		printf("enter the  i value\n");
		scanf("%d", &i);

		printf("enter the a value\n");
		scanf("%d", &a);

		printf("enter the b value\n");
		scanf("%d", &b);

		//validation
		if( a < 0 || a > 31 || b < a || b > 31)
		{
			printf("invalid range\n");
		}
		else
		{
		//calling function and printing
		printf("%d\n", bitwise_lsb(num, i, a, b));
		}
		printf("do u want continue: press(Yy)\n");
		scanf("\n%c", &status);
	} while(status == 'Y' || status == 'y');	
}

//functions
unsigned bitwise_lsb(unsigned num, unsigned i, int a, int b)
{
	int I1= b - a + 1;

	num= (num & ~(~0 << I1 )) << a;
	i = i & ~(~(~0 << I1) << a);
	num = num | i;
	return num;

}

