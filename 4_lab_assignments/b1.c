/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

//prototypes

int compare(const void *p, const void *q);
//driver
int main()
{
	//initilaize the variables
	float a2[5];

	printf("enter the float array\n");
	for(int i = 0; i < 5; i++)
	{
		scanf("%f", &a2[i]);
	}

	float key;

	printf("enter the key to search\n");
	scanf("%f", &key);

	int (*comp) (const void*, const void*) = compare;
	qsort(a2, sizeof(a2) / sizeof(a2[0]), sizeof(a2[0]), *comp);
	for(int i = 0; i < 5; i++)
	{
		printf("%f\n", a2[i]);
	}

				//binary search

	int (*comp1) (const void*, const void*) = compare;
				if(bsearch(&key,a2, sizeof(a2) / sizeof(a2[0]), sizeof(a2[0]), *comp1) == NULL)
				{
					printf("key not found2\n");
				}
				else
				{
					printf("key is  found1\n");
				}
			


}

int compare(const void *p, const void *q)
{
	int a, b;

	a = *(float*)p;
	b = *(float*)q;

	if(a > b)
	{
		return 1;
	}
	else if(a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
