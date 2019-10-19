/*
Title:Sieve
Author: Bharath
Organization: Emertxe
Descriptions: finding the prime numbers upto limit
by loading the numbers into array and print prime numbers only


*/


#include <stdio.h>

int main()
{
	//initialize the variables
	int i,j,flag=1,n;
	char status;
	do
	{
		//prompt the user to enter limit
		printf("enter the limit\n");
		scanf("%d", &n);

		//checking for validation
		if(n < 0 || n > 1024)
		{
			printf("invalid range\n");
		}
		else
		{
		//initializing the array
		int array[n + 1];

		//assigning the values to array

		for(i=0; i<=n; i++)
		{
			array[i]=i;
		}

		//printing the array
		printf("Elements of array:");
		for(i=0; i<= n; i++)
		{
			printf("%d ", array[i]);

		}
		printf("\n");


		//logic
		printf("Prime numbers:");
		for(i=1; i <=n; i++)
		{
			
				flag=1;
				for(j=2; j< array[i]; j++)
				{
					if(array[i] % j == 0)
					{ 
						flag=0;
						break;
					}
				}
				//printing only prime values
				if(flag)
				{
					printf("%d ", array[i]);
				
				}
			
		}
		}
		printf("\n");
		printf("do u want continue: press[Yy]\n");
		scanf("\n%c",&status );
	}while(status == 'Y' || status == 'y');

}


