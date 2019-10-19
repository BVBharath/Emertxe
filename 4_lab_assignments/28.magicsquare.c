/*
Title:magicsquare.c
Author:Bharath
Organization:Emertxe
Description:WAP to generate magic square for odd numbers

*/

#include<stdio.h>
#include<stdlib.h>

//driver
int main()
{
	system("clear");

	//initialize the variables
	int row,column,i,j;

	//read the odd rows and cols
	printf("\nenter the odd number block size: ");
	scanf("%d",&row);
	column = row;

	//declare the 2-D array
	int a[row][column];

	//initialize all the elements to zero
	for(i = 0;i < row;i++)
	{
		for(j = 0;j < column;j++)
		{
			a[i][j] = 0;
		}
	}

    int count = 1;
    int k = 0;
    int l = (row / 2) ;
    i = k;
    j = l;
    a[k][l] = count++;
    int d = row * row;

    //logic
    while(--d)
	{
		//condition1
		if((i-1) < 0)
		{
			k = row - 1;
		}
		else
		{
			k = i - 1;
		}

		//condition2
		if((j+1) > (column-1))
		{
			l = 0;
		}
		else
		{
			l = j + 1;
		}

		//condition3
		if((a[k][l]) != 0)
		{
			k = i+1;
			l = j;
		}

		//assigning the values to matrix
		a[k][l] = count++;
		i = k;
		j = l;
        
	}
	
	//printing the magic square
	printf("\nmagicsquare is : \n");
	for(i = 0;i < row;i++)
	{
		for(j = 0;j < column;j++)
		{
		printf("%5d ",a[i][j]);
		}
		printf("\n");
	}
}
    

