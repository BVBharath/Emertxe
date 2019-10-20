/*

 */


#include <stdio.h>

//prototypes

void quick_sort(int *arr, int first, int last);

int partition(int arr[], int first, int last);

void swap(int *p, int *q);

//driver
int main()
{
	//initialize the variables
	int n, i;
	char status;

	do
	{
	printf("enter the length of the array\n");
	scanf("%d", &n);

	int arr[n];

	printf("enter the array elements\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	quick_sort(arr, 0, n-1);
	
	printf("sorted array elements : ");

	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');

	printf("do u want to continue....press(yY)\n");
	scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
	
}

//functions
void quick_sort(int *arr, int first, int last)
{
	if(first < last)
	{
		int partition_index = partition(arr, first, last);

		quick_sort(arr, first, partition_index-1);

		quick_sort(arr, partition_index+1, last);
	}

}

//
int partition(int arr[], int first, int last)
{
	int index = first, j = first;
	int pivot = arr[last];

	while(j < last)
	{
		if(arr[j] <= pivot)
		{
			swap(&arr[index], &arr[j]);
			index++;
		}
		j++;
	}
	swap(&arr[index], &arr[last]);
	return index;
}

//
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}




