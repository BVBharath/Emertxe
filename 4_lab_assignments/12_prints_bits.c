/*
Title: Print_bits
Author: Bharath
Organization: Emertxe
Descriptions: Print given decimal number in binary form and its negative form in binary form

*/


#include <stdio.h>

int main()

{
	//initialize the variables
	 int num,i;
	 char status;
	
	do
	{

		//promot the user to enter the number
		printf("enter the number\n");
		scanf("%d", &num);

		//logic
		//generating a mask
		unsigned size = sizeof(int)  << 3;
		unsigned mask = 1 << size - 1;
		unsigned mask1 = mask;
		
		//converting decimal into binary using bitwise operations
		printf("Binary[%d]:", num);
		for(i = 0; i < size; i++)
		{
			num & mask? putchar('1'):putchar('0');
			mask >>= 1;
		}
		printf("\n");
		
		//initialize negative form into one variable
		int num2 = - num;
		
		//converting negative decimal into binary using bitwise
		printf("Binary[%d]:", num2);
		for (i = 0; i < size; i++)
		{
			num2 & mask1? putchar('1'):putchar('0');
			mask1 >>= 1;
		}

		printf("\n");


		printf("do u want continue: press(Yy)\n");
		scanf("\n%c", &status);
	}while(status =='Y' || status == 'y');
}
