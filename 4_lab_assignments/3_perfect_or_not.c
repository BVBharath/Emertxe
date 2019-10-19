/*
title:1_perfect_or_not
author:Bharath
organization:Emertxe
description:To check whether the given number is perfect or not using for loop and if statements
*/

#include <stdio.h>

int main()
{

	//initialize the variables
	int i,num,sum=1;
	char status;

	do
	{

		//prompt the user to enter the value
		printf("enter the number:");
	
		//read the number
		scanf("%d", &num);
		
		//validating the number
		if (num <= 0 )
		{
			printf("invalid\n");
		}
		else
		{
			//logic
			for ( i = 2; i < num ; i++)
			{
				if (num % i == 0 )
				{
					sum = sum + i;
				}
			}
	
			if ( sum == num )
			{
				printf("the %d is perfect number\n", num);
			}	
			else
			{
				printf("the %d not perfect number\n", num);
			}
		}
		printf("do you want continue......press(Yy):");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y' );
}
