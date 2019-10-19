/*
title:size_of_basic_datatype
author:bharath
organization:emertxe
description:To find the size of basic data types using size_t option and checking for every possible sizes
*/

#include <stdio.h>

int main()
{
	printf("ths sizeof (char): %zu\n", sizeof(char));
	printf("ths sizeof (signed char): %zu\n", sizeof(signed char));
	printf("ths sizeof (unsigned char): %zu\n", sizeof(unsigned char));
	
	printf("ths sizeof (int): %zu\n", sizeof(int));
	printf("ths sizeof (signed int): %zu\n", sizeof(signed int));
	printf("ths sizeof (unsigned int): %zu\n", sizeof(unsigned int));
				
    printf("ths sizeof (short int): %zu\n", sizeof(short int));
	printf("ths sizeof (long int): %zu\n", sizeof(long int));
	printf("ths sizeof (long long int): %zu\n", sizeof(long long int));
				
	printf("ths sizeof (short unsigned int): %zu\n", sizeof(short unsigned int));
	printf("ths sizeof (long unsigned int): %zu\n", sizeof(long unsigned int));
	printf("ths sizeof (long long unsigned int): %zu\n", sizeof(long long unsigned int));
	
	printf("ths sizeof (float): %zu\n", sizeof(float));
	printf("ths sizeof (double): %zu\n", sizeof(double));
	printf("ths sizeof (long double): %zu\n", sizeof(long double));
	printf("ths sizeof (long long): %zu\n", sizeof(long long));
	return 0;
}
