/*
Title: structstudent.c
Author: Bharath
Organization: Emertxe
Description: defining a structure to store the details of students

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//prototypes


typedef struct
{
	char *name;
	int *marks;
	float avg;
	char grade;
}student_t;

void populate(student_t *p, size_t m, size_t n);

void print(student_t *p, size_t m, size_t n);

void sort(student_t *p, size_t m, size_t n, size_t ch );

void prints(student_t *p, size_t m, size_t n, size_t ch);
//driver
int main()
{
	//initialize the variables
	size_t m, n;
	size_t ch;
	char status;

	do
	{

		//prompt + read
		printf("enter the number of students\n");
		scanf("%zu", &m);

		student_t *p = malloc(m * sizeof(student_t));
		if(p == NULL)
		{
			printf("invalid\n");
			return 0;
		}
	
		printf("enter the number of subjects\n");
		scanf("%zu", &n);

		//calling populate function
		populate(p, m, n);

		//printing the details of student
		print(p, m, n);

		//prompting for sorting options
		printf("do u want sorting based on \n1.average\n2.grades\n");
		scanf("%zu", &ch);

		//calling sorting function
		sort(p, m, n, ch);

		//printing in sorting order
		prints(p, m , n , ch);

		//continuee..part
		printf("do u want to continue..press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'y' || status == 'Y');


}


//funnctions
void populate(student_t *p, size_t m, size_t n)
{
	size_t i, j;
	char buffer[20];
	float sum = 0;

	for(i = 0; i < m; i++)
	{
		printf("enter the %zu name: ", i+1);
//		fgets(buffer, 20, stdin);
		scanf("\n%[^\n]s", buffer);
		p[i].name = malloc(strlen(buffer) + 1);

		if(p[i].name == NULL)
		{
			printf("invalid\n");
		}
		strcpy(p[i].name, buffer);

		p[i].marks = malloc(n * sizeof(int));
		if(p[i].marks == NULL)
		{
			printf("invalid\n");
		}

		printf("enter the %zu subjects marks\n", n);
		for(j = 0; j < n; j++)
		{
			printf("enter the subject%zu marks:", j + 1);
			scanf("%d", p[i].marks + j);
			sum += *(p[i].marks + j);

		}
		float avg = sum / n;

		p[i].avg = avg;
		sum = 0;

		switch((int)(p[i].avg))
		{
			case 0 ... 40:
						p[i].grade = 'D';
						break;
			case 41 ... 60:
						p[i].grade = 'C';
						break;
			case 61 ... 75:
						p[i].grade = 'B';
						break;;
			default:
						p[i].grade = 'A';
		}

		memset(buffer, '\0', 20);
		
		
	
	}
}

//

void print(student_t *p, size_t m, size_t n)
{
	size_t i, j, k;

		printf("\nthe detials of students\n");
		for(i = 0; i < m; i++)
		{
			printf("student name: %s\n", p[i].name);
			for(j = 0; j < n; j++)
			{
			printf("student subject(%zu) marks: %d\n", j + 1,*(p[i].marks + j));
			}
		
			printf("student avg: %f\n", p[i].avg);


			printf("student grade: %c\n", p[i].grade);
		}
	}


//
void sort(student_t *p, size_t m, size_t n, size_t ch )
{

	//initialize the variables
	size_t i, j;
	float temp;
	char *temp1;


	switch(ch)
	{

		case 1:
	
				for(i = 0; i < m - 1; i++ )
				{
					for(j = 0; j < m - 1 - i; j++)
					{
						if(p[i].avg > p[i+1].avg)
						{
							temp = p[i].avg;
							temp1 = p[i].name;
							p[i].avg = p[i+1].avg;
							p[i].name = p[i+1].name;
							p[i+1].name = temp1;
							p[i+1].avg = temp;
						}
					}
				}
				break;

		default:
				for(i = 0; i < m - 1; i++ )
				{
					for(j = 0; j < m - 1 - i; j++)
					{
						if(p[i].grade > p[i+1].grade)
						{
							temp = p[i].grade;
							temp1 = p[i].name;
							p[i].grade = p[i+1].grade;
							p[i].name = p[i+1].name;
							p[i+1].name = temp1;
							p[i+1].grade = temp;
						}
					}
				}
			}
}
//
void prints(student_t *p, size_t m, size_t n, size_t ch)
{
	size_t i;

	switch(ch)
	{
		case 1:
				for(i = 0; i < m; i++)
				{
					printf("name: %s\n", p[i].name);
					printf("%s's average: %.2f\n", p[i].name, p[i].avg);
				}
				break;
		default:
				for(i = 0; i < m; i++)
				{
					printf("name: %s\n", p[i].name);
					printf("%s's grade: %c\n", p[i].name, p[i].grade);
				}
	
	}
}
