/*
Title:
Author:Bharath
Organization:Emertxe
Description: To print the integer part of float value without using integer variable

*/


#include <stdio.h>


//prototypes
typedef struct
{
	unsigned mantessa:23;
	unsigned exp:8;
	unsigned sign:1;
}data_t;

void print_bits(unsigned num, int n);

//driver
int main()
{
	float f ;
	char status;

	do
	{
		//prompt + read from the user
		printf("enter the float value\n");
		scanf("%f", &f);

		//creating a structure pointer and assign float address
		data_t *p = (data_t*) &f;

		//printing mantess part
		printf("mantessa: ");
		print_bits(p->mantessa, 23);

		//printing exponent part
		printf("exponent: ");
		print_bits(p->exp, 8);
		
		//printing a sign part
		printf("sign: ");
		print_bits(p->sign, 1);


		unsigned n = p->exp - 127;
		unsigned d_value = p->mantessa >> (23 - n) | (1 << n);
	//	print_bits(d_value, 4);
		printf("integer part: %d\n", d_value);
	
	//	printf("integer part: %d\n", p->exp);
		printf("do u want to continuee...press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'y' || status == 'Y');

}

//functions
void print_bits(unsigned num, int n)
{
	unsigned mask = 1 << n - 1;
	for(; mask; mask >>= 1)
	{
		num & mask? putchar('1') : putchar('0');
	}
	putchar('\n');
}
