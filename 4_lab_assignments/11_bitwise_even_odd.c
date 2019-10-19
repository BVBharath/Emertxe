/*
title:2_bitwise_even_odd
author:bharath
organization:emertxe
description:To check whether the given positive number is even or odd by bitwise using if and else statements
*/

#include <stdio.h>

int main()
{

	//initializing the variables
	int num;
	char status;
	
    do
	{
		//prompt the user to enter the number
		printf("enter the number\n");
		scanf("%d", &num);

		if (num <= 0)
		{
			printf("invalid:enter only above 0 numbers \n");
		}

		else
		{

			 //logic
			if (num & 1)
			{
				printf("num %d is odd\n", num);
			}
			else
			{
				printf("num %d is even\n", num);
			}
         
		}

		//continue part
		printf("do u want continue....press(Yy)\n");
			
		scanf("\n%c", &status);

	}while(status == 'Y' || status == 'y');
}
