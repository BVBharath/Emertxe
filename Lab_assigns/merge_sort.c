/*


 */

#include <stdio.h>
#include <limits.h>


//prototypes
int merge_sort(int arr[], int first, int last);

void merge(int arr[], int first, int mid, int last);

//driver
int main()
{
	//initialize the variables
	int n, i;

	//
	printf("enter the size of the array\n");
	scanf("%d", &n);

	int arr[n];

	//
	printf("enter the elements of the array\n");
	for( i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, n-1);

	printf("sorted array : ");
	for( i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');


}

//
int merge_sort(int arr[], int first, int last)
{
	if(first < last)
	{
		int mid = (first + last ) / 2;

		merge_sort(arr, first, mid);

		merge_sort(arr, mid+1, last);

		merge(arr, first, mid, last);
	}

}

//
void merge(int arr[], int first, int mid, int last)
{
	int i, j, k;
	int l_size = mid - first + 1;
	int r_size = last - mid + 0;
	int LA[l_size];
	int RA[r_size];

	for(i = 0; i < l_size ; i++)
	{

		LA[i] = arr[first + i];
	}

	for(j = 0 ; j < r_size; j++)
	{
		RA[j] = arr[mid + 1 + j];
	}

	i = 0; j = 0, k = first;

	while(i < l_size && j < r_size)
	{
		if(LA[i] <= RA[j])
		{
			arr[k] = LA[i];
			i++;
		}
		else
		{
			arr[k] = RA[j];
			j++;
		}
		k++;
	}
	while (i < l_size)
	{
		arr[k++] = LA[i++];
	}
	while (j < r_size)
	{
		arr[k++] =RA[j++];
	}


}
