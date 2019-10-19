/*

*/

#include <stdio.h>
#define GENERIC_SWAP(a, b, type) {				 \
									type temp;	\
									temp = a;	\
									a =	b;		\
									b = temp;	\
								}		

int main()
{
	//initialize the variables
	int a, b;
	char status;

	do
	{
	//prompt + read
	printf("enter the numbers to swap\n");

	scanf("%d%d", &a, &b);

	//logic
	printf("before a: %d\t b: %d\n", a, b);
	GENERIC_SWAP(a, b, int);
	
	printf("after a: %d\t b: %d\n", a, b);

	printf("do u want to continuee...press(Yy)\n");
	scanf("\n%c", &status);
	}while(status == 'y' || status == 'Y');
}
