/*
Title: Float_array
Author: Bharath
Organization: Emertxe
Description:The below programme is to sort the float array without moify oand copy the array.

*/

#include <stdio.h>

//prototypes
void sort(float *p, int n);

//driver
int main()
{
	//initialilze the variables
	int n, i;
	char status;

	do
	{
		//prompt the user to ask how many elements
		printf("how many elements u are entering\n");
		scanf("%d", &n);

		//declaring the array
		float array[n];
	
		//populate the array
		printf("enter %d elements\n", n);
		for( i = 0; i < n; i++)
		{
			scanf("%f", &array[i]);
		}

		putchar('\n');

		printf("The elements before sorting:\n");
		for( i = 0; i < n; i++)
		{
			printf("%.2f\t", array[i]);
		}

		putchar('\n');

		//printing after sorting
		printf("after sorting:\n");

		//calling logic function
		sort(array, n);

		printf("do u want to continue...press(Yy)\n");
		scanf("\n%c", &status);
		getchar();
	}while(status == 'Y' || status == 'y');


	

}

//functions
void sort(float *p, int n)
{
	//initialize the variables
	int q = n;
	float small = *p;
	float next_small = 0;
	float great = 0;
	for(int i = 0; i < n; i++)
	{
		if(great < *(p + i))
		{
			great = *(p + i);
		}
	}

	while(q--)
	{

		small = great;
		for(int i = 0; i < n; i++)
		{
			if(*(p + i) > next_small && *(p + i) < small)
			{
				small = *(p + i);
			}
		}
		next_small = small;
		printf("%.2f\t", next_small);
	}

	putchar('\n');

}
