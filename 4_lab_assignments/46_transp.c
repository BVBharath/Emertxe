/*
Title: Transmult.c
Author: Bharath
Organization: Emertxe
Description: The below programme is to transpose the given matrix, then multiply the orginal matrix and transpose matrix and store it in another matrix.

*/

#include <stdio.h>
int main()
{
	//initialize the variables
	int R, C,i,j,k;
	char status;

	do
	{
		//prompt th user to enter number of rows
		printf("enter the rows of the matrix\n");
		scanf("%d", &R);

		//prompt the user to enter the number of columns
		printf("enter the columns of the matrix\n");
		scanf("%d", &C);

		//initializes the matrices
		int mat1[R][C], mat2[C][R], mat3[R][R];

		//prompt the user to enter the matrix
		printf("enter the matrix\n");
		for(i=0; i < R; i++)
		{
			printf("enter %d th row elements:", i);
			for(j=0; j < C; j++)
			{
				scanf("%d", &mat1[i][j]);
			}
		}

		//printing the input matrix
		printf("The input matrix is:\n");
		for(i=0; i < R; i++)
		{
	
			for(j=0; j < C; j++)
			{
				printf("%5d", mat1[i][j]);
			}
			putchar('\n');
		}
		
		//coverting input matrix into transpose
		for(i=0; i < R; i++)
		{
			for(j=0; j < C; j++)
			{
				mat2[j][i] = mat1[i][j];
			}
		}
		

		//printing the transpose version of input matrix
		printf("The transpose of given matrix\n");	
		for(i=0; i < C; i++)
		{
			for(j=0; j < R; j++)
			{
				printf("%5d", mat2[i][j]);
			}
				printf("\n");
		}

		printf("\n");

		//logic to perform the multiplication of transpose and input matrices
		printf("the multiplication of two matrices\n");
		for(i = 0; i < R; i++)
		{
			for(j = 0; j < R; j++)
			{
				mat3[i][j]=0;
				for(k=0; k < C; k++)
				{
					mat3[i][j]+=mat1[i][k]*mat2[k][j];
				}
			}
		}
		

		//printing the multiplication matrix
		for(i=0; i < R; i++)
		{
			for(j=0; j < R; j++)
			{
				printf("%5d", mat3[i][j]);
			}
				printf("\n");
		}

		//continue...part
		printf("do u want to continue...press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');


		
}
