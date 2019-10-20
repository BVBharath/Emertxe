/*

 */


#include <stdio.h>

//prototypes
void bubble_sort(int *p, int n);
void print(int *p, int n);

void selection_sort(int *p, int n);


void insertion_sort(int *p, int n);
int i, j, temp;

//driver
int main()
{
	//initialize the variables
	int n, options;
	char status;

	do
	{
		printf("enter the number of elements in array\n");
		scanf("%d", &n);

		int a[n];

		printf("enter the elements of the array\n");
		for(i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}

		printf("select  the types of sorting technique\n1.bubble sort\n2.selection sort\n3.insertion sort\n");
		scanf("%d", &options);

		switch(options)
		{
			case 1:
				//callling function
				bubble_sort(a, n);
				break;
			case 2:
				//calling function
				selection_sort(a, n);
				break;
			case 3:
				//calling function
				insertion_sort(a, n);
				break;
		}

		print(a, n);
		printf("do u want to continue...press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');

}

//functions
void bubble_sort(int *p, int n)
{
	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - 1 - i; j++)
		{
			if(p[j] > p[j+1])
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;

			}
		}
	}
}

//

void print(int *p, int n)
{
	for( i = 0; i < n; i++)
	{
		printf("%d ", p[i]);
	}
	putchar('\n');
}

//
void selection_sort(int *p, int n)
{
	int index = 0;
	for(i = 0; i < n - 1; i++)
	{
		index = i;
		for(j = i + 1; j < n; j++)
		{
			if(p[j] < p[index])
			{
				index = j;
			}
		}

		temp = p[i];
		p[i] = p[index];
		p[index] = temp;
	}
}


//
void insertion_sort(int *p, int n)
{
	for(i = 1; i < n; i++)
	{
		j = i;
		while(j > 0 && p[j-1] > p[j])
		{
			temp = p[j];
			p[j] = p[j-1];
			p[j-1] = temp;
			j--;
		}
	}
}
