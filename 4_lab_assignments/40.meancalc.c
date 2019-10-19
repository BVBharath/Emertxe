/*
Title: meancalc.c
*/

#include <stdio.h>
#include <stdlib.h>

//function
void avg(void *p,  size_t m, size_t n);

void avg1(void *p, size_t m, size_t n);

void avg2(void *p, size_t m, size_t n);

//driver
int main(int argc, char *argv[])
{
	//initialize the variables
	int n = atoi(argv[1]);

	//declaring array for different data types
	int a1[n], i, options;
	short int a2[n];
	float a3[n];
	double a4[n];
	char status;

	do
	{
		//providing choice for selecting a data types
		printf("\nselect one datatype\n1.int\n2.shortint\n3.float\n4.double\n");
		scanf("%d", &options);

		//switch to one of the options
		switch(options)
		{
			case 1:
					//prompt + read integer numbers
					printf("enter the %d integer numbers\n", n);
					for( i = 0; i < n; i++)
					{
						scanf("%d", &a1[i]);
					}

					//calling function	
					avg(a1,  sizeof(a1) / sizeof(a1[0]), sizeof(int)  );
					break;
	
		
			case 2:
					//prompt + read short integer numbers
					printf("enter the %d short int numbers\n", n);
					for( i = 0; i < n; i++)
					{
						scanf("%hd", &a2[i]);
					}

					//calling function
					avg(a2,  sizeof(a2) / sizeof(a2[0]), sizeof(short int)  );
					break;
	
		
			case 3:
					//prompt + read float numbers
					printf("enter the %d numbers\n", n);
					for( i = 0; i < n; i++)
					{
						scanf("%f", &a3[i]);
					}
				
					//calling function
					avg1(a3,  sizeof(a3) / sizeof(a3[0]), sizeof(float)  );
					break;
			case 4:
					//prompt + read double numbers
					printf("enter the numbers\n");
					for( i = 0; i < n; i++)
					{
						scanf("%lf", &a4[i]);
					}

					avg2(a4,  sizeof(a4) / sizeof(a4[0]), sizeof(double)  );
					break;
		
			}

		printf("do u want to continue...press(Yy)\n");
		scanf("\n%c", &status);
		getchar();
	}while(status == 'y' || status == 'Y');
}

//function
void avg(void *p,  size_t m, size_t n)
{
	
	int k = n;
	int l = m ;

	void *q = calloc( n, sizeof(char));
	void *t = q;
	while(m--)
	{
		n = k;
		while(n--)
		{
		
		*(char*)q = *(char *)q + *(char*)p; 
		 q = (char *)q + 1;
	 p = (char *)p + 1;
		}
		q = t;
	
	}
	float sum =  *(int *) q;

	float avg;
	printf("The sum is %f\n", sum);
	avg = sum / l;

	printf("The  average is :%f\n", avg);
}

//
void avg1(void *p, size_t m, size_t n)
{
	float sum = 0;
	void *q = &sum;
	void *t = q;
	int l = m;


	while(m--)
	{
		*(float*) q = *(float*) q + *(float *)p;

		p = (char *)p + n;
	}
	printf("The sum is : %f\n", *(float *)q);
	
	float avg = sum / l;
	printf("The average is : %f\n", avg);
}

//
void avg2(void *p, size_t m, size_t n)
{
	double sum = 0;
	void *q = &sum;
	void *t = q;
	int l = m;


	while(m--)
	{
		*(double*) q = *(double*) q + *(double *)p;

		p = (char *)p + 8;
	}
	printf("The sum is : %lf\n", *(double *)q);
	
	double avg = sum / l;
	printf("The average is : %lf\n", avg);
}

