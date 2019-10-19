/*
title:9_year_first_day
Author:Bharath
Organization:Emertxe
Descripion:TO check the day  of the year for the given date

*/

#include <stdio.h>

int main()
{
	//initialize the variables
	int search_day,first_day,logic;
	char status;

	do
	{
		//prompt the user to enter the inputs
		printf("choose the  first_diay:\n1.sunday\n2.monday\n3.tuesday\n4.wednesday\n5.thursday\n6.friday\n7.saturday\n\n");
		 printf("enter first day:\n");	
    	scanf("%d", &first_day);
	
		




		//validation for first_days
		if( first_day < 1 || first_day > 7)
		{
			printf("invalid: enter first day only from 1 to 7\n");
			return -1;
		}
    
		//prompt the user to enter day they want to search
		printf("choose day u want to search:\n");
		scanf("%d", &search_day);


		//validation for search day
		 if ( search_day < 1 || search_day > 365)
		{
				printf("invalid:enter only search_days 1 to 365\n");
				return -1;
		}

		
		//logic

		logic = (search_day + first_day - 1) % 7;

	    switch(logic)
		{
			case 1:
			       printf("%d is sunday:\n", search_day);
				   break;
		      
			case 2:
			       printf("%d is monday:\n", search_day);
			       break;

			case 3:
			       printf("%d is tuesday:\n", search_day);
				   break;

			case 4:
			       printf("%d is wednesday:\n", search_day);
			       break;

			case 5:
			       printf("%d is thursday:\n", search_day);
				   break;

			case 6:
			       printf("%d is friday:", search_day);
				    break;

			default:
			       printf("%d is saturday:\n", search_day);
		}
		
  
		printf("do you want continue.....press(Yy)\n");
	
		scanf("\n%c", &status);
	}while(status == 'y' || status == 'Y');
}
