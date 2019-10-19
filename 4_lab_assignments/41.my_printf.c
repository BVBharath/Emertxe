/*
Title: my_printf.c
Author: Bharath
Organization:Emertxe
Description: The below programme is used to create own printf function.

*/

#include <stdio.h>
#include <stdarg.h>

//prototypes
void my_pf(const char *format, ...);
void actio(int *p);

//driver
int main()
{
	//initialize the variables
	char ch = 'A';
	int a = 10;
	float f = 1.2;
	double d = 523652.2364;
	char status;

	do
	{


		my_pf("\nvalues are\nch = %c\na = %d\na = %x\nf = %f\nd =%lf\n", ch, a, a, f, d);
		printf("do u want to continue...press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'y' || status == 'Y');
}

//functions
void my_pf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	char buffer[100] = {'\0'};
	int i;
	char ch;
	float f;
	double d;

	const char *p = format;
	while(*p)
	{
		if(*p == '%')
		{
			switch(*++p)
			{
				case 'c':
							ch = (char) va_arg(ap, int);
							putchar(ch);
							break;

				case 'd':
							i =va_arg(ap, int);
							sprintf(buffer, "%d", i);
							puts(buffer);
							break;

				case 'f':
							f=(float)va_arg(ap, double);
							sprintf(buffer, "%f", f);
							puts(buffer);
							break;

				case 'x':
							i = va_arg(ap, int);
							sprintf(buffer, "%x", i);
							puts(buffer);
				
				case 'l':

						switch(*++p)
						{

							case 'f':
										d =va_arg(ap, double);
										sprintf(buffer, "%lf", d);
										puts(buffer);
										break;
						}
			
			
			}
		}
		
		else
		{
				putchar(*p);
		}
		p++;
	}


}
