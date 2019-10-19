/*
Title: Median
Author: Bharath
Organization: Emertxe
Descriptions:finding median of two arrays
1.find median of one array
2.find median of second array
3.find and print median of both arrays

*/


#include <stdio.h>

//prototypes
int sorting(int a1[], int);


//driver
int main()
{
	//declare the variables here
	int n1, i, j, n2;
	float median1, median2, median;
	char status;
	do
	{
		//promot the user
		printf("enter the length of array1\n");
		scanf("%d", &n1);

		//now,decalre the array1
		int a1[n1];

		//promot the user 
		printf("enter the length of array2\n");
		scanf("%d", &n2);

		//now,decalre the array2
		int a2[n2];

		//populate the array1
		printf("enter the %d items: \n", n1);
		for (i=0; i < n1; i++)
		{
			scanf("%d", &a1[i]);
		}

		//populate the array2
		printf("enter the %d items: \n", n2);
		for (i=0; i < n2; i++)
		{
			scanf("%d", &a2[i]);
		}

		//print the array1
		printf("The contents of first array: ");
		for(i=0; i < n1; i++)
		{
			printf("%d ", a1[i]);
		}
		printf("\n");
		
		//print the array2
		printf("the contents of second array: ");
		for(i=0; i< n2; i++)
		{
			printf("%d ", a2[i]);
		}
		printf("\n");
		
		//calling the function
		sorting(a1, n1);

		//calling the function
		sorting(a2, n2);

		//printing sorted arrays
		printf("sorting of first array:");
		for (i=0; i< n1; i++)
		{
			printf("%d ", a1[i]);
		}

		printf("\n");

		printf("sorting of second array:");
		for (i=0; i< n2; i++)
		{
			printf("%d ", a2[i]);
		}

		printf("\n");

		//logic for medians
		if(n1 & 1)
		{
			median1=a1[n1/2];
		}
		else
		{
			median1=(a1[n1/2]+a1[n1 / 2 - 1]) / 2.0;
		}
		printf("median1: %.3f\n", median1);

		if(n2 & 1)
		{
			median2=a2[n2/2];
		}
		else
		{
			median2=(a2[n2/2]+a2[n2/ 2 - 1]) / 2.0;
		}
		printf("median2: %.3f\n", median2);

		//caluculating the final median
		median=(median1 + median2)/2.0;

		printf("%.3f\n", median);

		printf("do u want continue: press(Yy)\n");
		scanf("\n%c", &status);

	}while (status == 'Y' || status == 'y');



}

//functions
int sorting(int a1[], int n1)
{

	int i, j, temp;
		//sorting the array1
		for(j=0; j< n1 - 1; j++)
		{
			for (i= 0; i< n1 - 1 - j  ; i++)
			{
				if(a1[i] > a1[i + 1])
				{
					temp=a1[i];
					a1[i]=a1[i + 1];
					a1[i + 1]=temp;

				}
			}
		}
}
