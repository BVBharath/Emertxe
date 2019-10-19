/*
title: even_odd_pos_neg
author: bharath
organization: emertxe
description: To check the whether the given number is evenpositive,evennegative, oddpositive or oddnegative
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	//initialize the variables'
	int num;
	char status;
	do
	{
		//prompt the users to enter the value
		printf("enter the number\n");
		scanf("%d", &num);

		//logic

		if(num == 0)
		{
			printf("invalid\n");
	    
		}
		else
		{
			if( num > 0 )
			{
				if(num % 2)
				{
					printf("the number is posodd\n");
				}
				else 
				{
					printf("the num is poseven\n");

				}
			}
			if (num < 0)
			{
				if(num % 2)
				{
					printf("the number is negodd\n");
				}
				else
				{
					printf("the number is negeven\n");
				}
			}
		}
	printf("do you want continue.....press(Yy):");
	scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
}


