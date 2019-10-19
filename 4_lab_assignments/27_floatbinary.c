/*
Title: Float_binary
Author: Bharath
Organization: Emertxe
Description: The below programme is to convert the given float number in binary format

*/

#include <stdio.h>

int main()
{
	
	
	//initalize the variables
	int options;
	float a;
	double b;
	char status;

	do
	{
		//promot the user to enter the number
		printf("enter the number\n");
		scanf("%f", &a);
		b = a;
		
		//type casting
		int *p = (int *) &a;
		long *q = (long *) &b;
		unsigned  mask = 1 << ((sizeof(int) << 3) - 1);
		unsigned long mask1 = (unsigned long)1 << ((sizeof(long) << 3) - 1 );
		printf("select one optiond\n1.float\n2.double\n");
		scanf("%d", &options);
	
		switch (options)
		{
			case 1:
					for(; mask; mask >>= 1)
					{
						(*p & mask)? putchar('1'):putchar('0');
						if (mask == 1 << 31 || mask == 1 << 23)
						{
							printf(" ");
						}
					}
					printf("\n");
					break;

			case 2:
				

					for (; mask1; mask1 >>=1)
					{
						*q & mask1 ? putchar('1'):putchar('0');
						if(mask1 == (unsigned long)1 << 63  || mask1 == (unsigned long )1 << 52)
						{
							printf(" ");
						}
					}
					printf("\n");
					break;

			default:
					printf("invalid\n");
		}
	printf("do u want to contonue....press(Yy)\n");
	scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
}
