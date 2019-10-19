/*
Title: Variance
Author: Bharath
Organization: Emertxe
Description:1.The below programme is to find the sum and average of  given intger array
2.generate the variance array by every element of input intger array with average find out in first step
3.Then found the sum and average of variance array
*/

#include <stdio.h>
#include <stdlib.h>

//prototypes
void populate(int *p, int n);
void print(int *p, int n, float *sum, float *avg);
void avg_sum1(int *p, float *q, int n, float *avg);
void printfl(float *p, int n, float *sum ,float *avg);

//driver
int main()
{
	//initialize the variables
	int n;
	float sum, avg;
	char status;
	int choice;

	do
	{

		//prompt the user to how many numbers
		printf("how many numbers u are entering\n");
		scanf("%d", &n);



		//providing a options for user
		printf("enter  ur choice\n1.static memory allocation\n2.dynamic memory allocatio\n");
		scanf("%d", &choice);
	
		//validation
		if(choice  < 1 || choice > 2)
		{
			printf("invalid input...enter 1 or 2 only\n");
		}
		else
		{
			if (choice == 1)
			{

				//declaring a array statically
				int a[n];

				//populate input array
				printf("enter %d numbers\n", n);
				populate(a, n);
			
				//printing input array and finding sum and average
				printf("\ninput(X)\n");
				print(a, n, &sum, &avg);

				//creating variance array statically
				float d[n];

				//forming variance array
				avg_sum1(a, d, n, &avg);
			
				//printing variance array and finding sum and average
				printf("\nD2 = (X - mean) * 2\n");
				printfl(d, n, &sum, &avg);
			}
			else if(choice == 2)
			{
				//declaring a array dynamically
				int *a = malloc(n * sizeof(int));

				//populate
				printf("enter %d numbers\n", n);
				populate(a, n);
				//printing and finding avg and sum
				printf("\ninput(X)\n");
				print(a, n, &sum, &avg);

				//creating a variance array dynamically
				float *d = malloc(n * sizeof(float));
				avg_sum1(a, d, n, &avg);
					
				//printing variance array and finding sum and avg	
				printf("\nD2 = (X - mean) * 2\n");
				printfl(d, n, &sum, &avg);
			}
		}
	printf("do u want to continue....press(Yy)\n");
	scanf("\n%c", &status);
	getchar();

	}while(status == 'Y' || status == 'y');
	


	
	
}

//functions
void populate(int *p, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		

	}
	
}

//
void print(int *p, int n, float *sum, float *avg)
{
	int i;
	*sum = 0;
	*avg = 0;
	for(i = 0; i < n; i++)
	{
		printf("%d\n", p[i]);

		*sum += p[i];
	}
	*avg = *sum / n;

	
	printf("The sum is: %.2f\n", *sum);
	
	printf("The average is : %.2f\n", *avg);
}



//
void avg_sum1(int *p, float *q, int n, float *avg)
{
	int i;
	float temp;
	for(i = 0; i < n; i++)
	{
		temp = p[i] - *avg;
		*(q + i) = temp * temp;
	}
}

//
void printfl(float *p, int n, float *sum, float *avg)
{
	int i;
	*sum = 0;
	*avg = 0;
	for(i = 0; i < n; i++)
	{
		printf("%.2f\n", p[i]);
		*sum += p[i];
	}
	*avg = *sum / n;

	printf("The sum is: %.2f\n", *sum);

	printf("The variance is : %.2f\n", *avg);
}



