/*
Title: MACROSIZEOF.c
Author: Bharath
Organization: Emertxe
Description: The programme to find the size of datatypes
 without using size of operator using macros definition.

*/


#include <stdio.h>

//macro definition
#define SIZEOF(a) (char *)(&a + 1) - (char *) (&a)

//driver
int main()
{

	int a;
	printf("sizeof(int): %ld\n", SIZEOF(a));

	char b;
	printf("sizeof(char): %ld\n", SIZEOF(b));

	float f;
	printf("sizeof(float): %ld\n", SIZEOF(f));

	double d;
	printf("sizeof(double): %ld\n", SIZEOF(d));

	unsigned int g;
	printf("sizeof(unsigned int): %ld\n", SIZEOF(g));

	long int h;
	printf("sizeof(long int): %ld\n", SIZEOF(h));

	int c[5];
	printf("sizeof(int array of 5 elements): %ld\n", SIZEOF(c));

}
