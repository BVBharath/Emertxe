/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpstringp(const void *p, const void *p2);
int main()
{

	//initialize the variables
	char **a;
	int n, i;

	printf("how many strings u want to enter\n");
	scanf("%d", &n);

	//
	printf("enter the strings\n");
	a = malloc(n * sizeof(char *));

	for(i = 0; i < n; i++)
	{
		a[i] = malloc(10);
		printf("enter the string%d:", i+1);
		scanf("%s", a[i]);
	}
	qsort(a, n, sizeof(char *), cmpstringp);
	for(i = 0; i < n; i++)
	{
		printf("%s\n", a[i]);
	}
	
}

//
int cmpstringp(const void *p, const void *p2)
{
	return strcmp(*(char * const *)p, *(char * const *) p2);
}
