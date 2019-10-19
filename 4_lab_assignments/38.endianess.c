/*
Title:endianess.c
Author: Bharath
Organization:Emertxe
Description: To check whether the given processor is little or big endianess.
*/

#include <stdio.h>

typedef union
{
	int a;
	 unsigned char b;
}endianess_t;

endianess_t x;

int main()
{
	x.a = 0x1A2B3C4D;

	if(x.b == 0x4D)
	{
		printf("little endianess\n");
	}
	else
	{

		printf("big endianess\n");
	}
}
