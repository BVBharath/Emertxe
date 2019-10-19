/*

*/


#include <stdio.h>
#include <stdlib.h>

//prototypes
int *populate(float **p, int r_size);
void print(float **p, int r_size, int *s);
void average(float **p, int r_size, int *s);
void sort(float **p, int *s, int r_size);


//driver
int main()
{
	int r_size;
		
	//populate the user to enter the row size	
	printf ("Enter row size: ");
	scanf ("%d", &r_size);

	//initilaizing the memory dynamically
	float **p = malloc(r_size * sizeof(float *));

	int *s = populate(p, r_size);
	
	//calling the average functions
	average(p, r_size, s);
	printf ("---------Entered array with averages-------\n");
	putchar ('\n');
	print(p, r_size, s);
	putchar ('\n');

	//calling sorting functions
	sort(p, s, r_size);
	printf ("-----------Sorted array with averages-----------\n");
	putchar ('\n');
	print(p, r_size, s);
}


//populate function
int *populate(float **p, int r_size)
{
	int i, j;

	//static int n[r_size];
	static int *s;
	s = malloc(r_size * sizeof(int));
    
	for (i = 0; i < r_size; i++)
	{
		printf ("Enter no of cols in %d row: ", i);
		scanf ("%d", s + i);

		*(p + i) = malloc((*(s + i) + 1) * sizeof(float));

		printf ("Enter %d items: ", *(s + i));
		for (j = 0; j < *(s + i); j++)
		{
			scanf ("%f", *(p + i) + j);
		}
	
		//return s;
	}	
	return s;
}


//printing functions
void print(float **p, int r_size, int *s)
{
	int i, j;
	for (i = 0; i < r_size; i++)
	{
		for (j = 0; j <= *(s + i); j++)
		{
			printf ("%.2f ", *(*(p + i) + j));
		}
		printf ("\n");
	}
}

//finding average functions
void average(float **p, int r_size, int *s)
{
	int i, j;
	float sum, avg;

	for (i = 0; i < r_size; i++)
	{
		sum = 0;
		avg = 0;
		for (j = 0; j < *(s + i); j++)
		{
			sum = sum + *(*(p + i) + j);
		}
		//printf ("sum: %f\n", sum);
		avg = sum / *(s + i);
		//printf ("avg: %f\n", avg);
		*(*(p + i) + *(s + i)) = avg;
	}
}


//sorting function
void sort(float **p, int *s, int r_size)
{
	int i,j;
	float *temp;
	int temp2;
	for(i=0; i < r_size - 1; i++)
	{
		for(j =	0; j < r_size - 1 - i; j++)
		{
			if( *(*(p + j) + *(s + j)) > *(*(p + (j + 1)) + *(s + (j + 1))) )
			{
				temp = *(p + j);
				temp2 = *(s + j);
				*(p + j) = *(p + j + 1);
				*(s + j) = *(s + j + 1);
				*(p + j + 1) = temp;
				*(s + j + 1) = temp2;
			}
		}
	}
}
