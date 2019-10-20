#include <stdio.h>
#define DATA_NOT_FOUND -1

//
void sort(int *a, int n);

int binary_search(int *a, int n, int key);

//
int binary_search_re(int *a, int key, int f, int l, int m);
int main()
{
	//inititalize the variables
	int n, i, key, found, f, l, m, option;
	printf("enter the length of array\n");
	scanf("%d", &n);

	int a[n];
	printf("enter the elements\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	sort(a, n);
	printf("sorted array\n");
	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');

	printf("enter the key to search\n");
	scanf("%d", &key);

	printf("1.binary_search_iteration\n2.binary_search_recursion\n");	scanf("%d", &option);

	switch(option)
	{
		case 1:
				found = binary_search(a, n, key);
				if(found != -1)
				{
					printf("key found at index: %d\n", found);
				}
				else
				{
					printf("key not found\n");
				}
		case 2:
				f = 0;
				l = n; 
				m = (f + l) / 2;

				found = binary_search_re(a, key, f, l, m);
				if(found != -1)
				{
					printf("key found at index: %d\n", found);
				}
				else
				{
					printf("key not found\n");
				}
				break;

	}
	
	

}

//
void sort(int *a, int n)
{
	int i, j, temp;

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0  ; j < n - 1 - i; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}


//
int binary_search(int *a, int n, int key)
{
	int f, l, m;
	f = 0;
	l = n ;
	m = (f + l) / 2;

	while(f < l)
	{
		if (key == a[m])
		{
			return m;
		}

		if(key > a[m])
		{
			f = m + 1;
		}
		if(key < a[m])
		{
			l = m - 1;
		}
		m = (f + l) / 2;
	}

	return DATA_NOT_FOUND;

}

//
//
int binary_search_re(int *a, int key, int f, int l, int m)
{
	if(f > l)
	{
		return DATA_NOT_FOUND;
	}

	if(key == a[m])
	{
		return m;
	}
	if(key > a[m])
	{

	return 	binary_search_re(a, key, m+1, l, ((m+1) + l) / 2);
	}
	if(key < a[m])
	{

	return 	binary_search_re(a, key, f, m-1, ((m-1) + f) / 2);
	}
}
