/*
Title: my_scanf.c
Author: Bharath
Organization: Emertxe
Description: The below programme is used to create own scanf function.

*/

#include <stdio.h>
#include <stdarg.h>

//prototypes
void my_scanf(const char *format, ...);


//driver
int main()
{
	//initialize the variables
	char ch;
	int i;
	float f;
	double d;
	long double ld;
	char status;

	do
	{

	//prompt the user to enter the charatcer
	printf("enter the character:");
	my_scanf("%c", &ch);
	getchar();

printf("entered character is %c \n", ch);
	//prompt the user to enter the integer number
	printf("enter the integer number:");
	my_scanf("%d", &i);


	//prompt the user to enter the float number
	printf("enter the float number:");
	my_scanf("%f", &f);

	//prompt the user to enter the double number
	printf("enter the double number:");
	my_scanf("%lf", &d);
	putchar('\n');



	//printing entered values
//	printf("entered character is %c \n", ch);

	printf("entered integer number is  %d \n", i);

	printf("entered float number is  %f\n", f);

	printf("entered double number is %lf\n", d);

	//
	printf("do u want to continue...press(yY)\n");
	scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
	

}
//functions
void my_scanf(const char *format, ...)
{
	va_list ap;
	char *cptr;
	int *iptr;
	float *fptr;
	double *dptr;
	long double *ldptr;
	char buff[80] = {'\0'};

	//initialize the pointer after the format
	va_start(ap, format);

	const char *p = format;

	while(*p)
	{
		if(*p == '%')
		{
			switch(*++p)
			{
				case 'c':
						cptr =va_arg(ap, char*);
						*cptr = getchar();
						break;

				case 'd':
						iptr = va_arg(ap, int*);
						//*iptr = atoi(fgets(buff, 80, stdin));
						fgets(buff, 80, stdin);
						sscanf(buff, "%d", iptr);
						break;


				case 'f':
						fptr = va_arg(ap, float*);
						//*iptr = atoi(fgets(buff, 80, stdin));
						fgets(buff, 80, stdin);
						sscanf(buff, "%f", fptr);
						break;

				

				case 'l':
						switch(*++p)
						{
							case 'f':
									dptr = va_arg(ap, double*);
									fgets(buff, 80, stdin);
									sscanf(buff, "%lf", dptr);
									break;
						
						
						}

					
				
			}
		}
		else
		{
			p++;
		}
	}
}
