/*
Title - fibonacci_series.C
Author - Bharath
Organization - Emertxe
Description - print the positive and negative fibonacci series up to given limit using while loops
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Declare the variables here
	int result,a,b,limit;
	char status;

    //logic
	do
	{
		//Initialization
		a = 0;
		b = 1;
		result = 0;
	

		//Prompt the user to enter the limit
		printf("Enter the limit:");

		//Read the limit
		scanf("%d", &limit);

		//validation

		if ( limit == 0 )
		{
			printf("invalid input\n");
		}
		else
		{
			//Logic for positive
			if (limit > 0)
			{
				printf ("positive fibonacci series is\n");
				printf ("%d ", a);
				while (result <= limit)
				{
					result = a + b;
					a=b;
					b=result;
			    	 printf ("%d ", a);
				}
				printf ("\n");
			}

			//Logic for negative
			else if (limit < 0)
			{
				printf ("negative fibonacci series is\n");
				printf ("%d ", a);
				while (abs(result) <= abs(limit))
				{
					result = a - b;
					a=b;
					b=result;
					printf ("%d ", a);
				 }
				printf ("\n");
			}
		}
		printf("do you want continue......press(Yy):");
		scanf("\n%c", &status);

	}while(status == 'Y' || status == 'y');
}
