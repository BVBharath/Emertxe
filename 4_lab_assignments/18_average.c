/*
title: avg.c
Author: Bharath
Organization:Emertxe
Description: The below programme is to calucalte the average in three methods.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes


//driver
int main(int argc, char *argv[], char *env[])
{
	//initialize the variables
	int sum = 0, i, count = 0;
	int n = atoi(argv[1]), options;
	float avg = 0;
	int a[n];
	char p[10];
	
	printf("select the method to calucalte the average\n1.Scan from the keyboard\n2.procesed with command line argument\n3.environment variables\n");
	scanf("%d", &options);

	switch(options)
	{
	
		case 1:
				printf("enter the %d numbers\n", n);
				for(i = 0; i < n; i++)
				{
					scanf("%d", &a[i]);
					sum += a[i];
				}
		
				avg = sum / n;
	
				printf("sum is %d\n", sum);
				printf("avg is %.2f\n", avg);
				break;	

		case 2:

				for( i = 1; i < argc; i++)
				{
					sum += atoi(argv[i]);
				}

				avg = (float)sum / (argc - 1);
				printf("sum is %d\n", sum);
				printf("avg is %.2f\n", avg);
				break;

		case 3:
				for(i = 0; env[i]; i++)
				{
					if(strncmp(env[i], "ARR", 3) == 0)
					{
						printf("%s\n", env[i]);
						strcpy(p, env[i]);
					}
				}
				char *q = p;
				char *d;

				while(q)
				{
					if(*q >= '0' && *q <= '9')
					{
						d = p;
						break;
					}
					q++;
				}

				while(*d)
				{
					sum += atoi(d);
					d = d + 2;
					count++;
				}
				avg = (float)sum / count;
				printf("sum is %d\n", sum);
				printf("avg is %.2f\n", avg);
				break;
		}
}
