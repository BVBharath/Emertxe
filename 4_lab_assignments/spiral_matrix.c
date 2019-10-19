/*


*/

#include <stdio.h>

void spiral_print(int m, int n, int a[m][n])
{
	int i, k = 0, l = 0;

	/* k = for starting row index
		m = ending row index
		l = starting column index
		n = ending column index
		i = iterator

	*/

	while(k <  m && l < n)
	{
		//print the first row from the remaining rows
		for(i = 0; i< n ; ++i )
		{
			printf("%d ", a[k][i]);
		}
		k++;

		//print the last column from the remaining columns
		for(i = k; i < m; i++)
		{

			printf("%d ", a[i][n - 1]);
		}
		n--;
		
		//print the last rows from the remaining rows

		if(k < m)
		{
		for(i = n-1; i >= l; --i)
		{

			printf("%d ", a[m-1][i]);
		}
		m--;
}		
		//print the first column from the remaining rows
		if(l < n)
		{
		for(i = m-1; i >= k; --i)
		{

			printf("%d ", a[i][l]);
		}
		l++;



	}
	}
}

//driver

int main()
{
	//initialize the variables
	int rows, columns;

	printf("enter the rows\n");
	scanf("%d", &rows);
	printf("enter the columns\n");
	scanf("%d", &columns);

	int a[rows][columns];

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	spiral_print(rows, columns, a);


}
