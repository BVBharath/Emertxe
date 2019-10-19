/*
title: 6_pattern_printing
Author: Bharath
Organization: Emertxe
Description: print the x pattern based on even and odd numbers

*/


#include <stdio.h>

int main()
{

	//initilize the number
	unsigned short num,rows,columns;
	char status;

	do
	{
		//promot the user to enter the number
		printf("enter the number\n");
		scanf("%hd", &num);

		//validation
		if (num <= 0 || num > 32 )
		{
			printf("invalid\n");
		}

		//logic
		else
		{
			if (num & 1)
			{
				for(rows = 0; rows < num; rows++)
				{
					for(columns = 0; columns < num ; columns++)
					{
						if (rows == columns || rows + columns == num - 1)
						{
							if(rows == columns && rows + columns == num - 1 )
							{
								printf("Hello");
							}
							printf("Hello");
						}
						else
						{
							printf(" ");
						}
					}
					printf("\n");
				}
			}
			else
			{
				for(rows = 0; rows < num; rows++)
				{
					for(columns = 0; columns < num ; columns++)
					{
						if (rows == columns || rows + columns == num - 1)
						{
							printf("Hello");
						}
						else
						{
							printf(" ");
						}
					}
					printf("\n");
				}
			}

		}
	printf("do you want continue.....press(Yy):");
	scanf("\n%c", &status);
	} while(status == 'Y' || status == 'y' );
}
