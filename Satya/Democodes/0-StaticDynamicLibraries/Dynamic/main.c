#include "common.h"

int main()
{
	int a, b;

	printf("Enter two nos.\n");

	scanf("%d%d", &a, &b);

	printf("Sum: %d\n", add(a, b));
	printf("Prod: %d\n", mul(a, b));

	return 0;
}
