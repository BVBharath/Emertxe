/*

 */
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

pthread_mutex_t mtx;

typedef struct thread_data
{
	short m1_row;
	short m1_col;
	short m2_col;
	int **matrix1;
	int **matrix2;
	int **result;
	short cur_row;
}thread_data_t;

thread_data_t mul;

//thread function
void *thread(void *ptr)
{
	
	int i = mul.cur_row;
	mul.cur_row++;
	for(int j = 0; j < mul.m2_col; j++)
	{
		mul.result[i][j] = 0;

		for(int k = 0; k < mul.m1_col; k++)
		{
			mul.result[i][j] += mul.matrix1[i][k] * mul.matrix2[k][j];
		}
	}



}

void print_matrix(int **ptr, int row, int col);
//driver
int main()
{
	//prompting the user to enter
	printf("enter the row of matrix1\n");
	scanf("%hd", &mul.m1_row);

	printf("enter the column of matrix1\n");
	scanf("%hd", &mul.m1_col);

	printf("enter the column of matrix2\n");
	scanf("%hd", &mul.m2_col);

	//allocate the memory dynamically
	mul.matrix1 = malloc(mul.m1_row  *  sizeof(int *));
	for(int i = 0; i < mul.m1_col; i++)
	{
		mul.matrix1[i] = malloc(mul.m1_col * sizeof(int *));
	}
	//	printf("size of matrix1 : %ld\n", sizeof((mul.matrix1)));
	if(mul.matrix1 == NULL)
	{
		printf("memory1 is not allocated\n");
	}


	mul.matrix2 = malloc(mul.m1_col * sizeof(int));
	for(int i = 0; i < mul.m1_col; i++)
	{
		mul.matrix2[i] = malloc(mul.m2_col * sizeof(int *));
	}

	if(mul.matrix2 == NULL)
	{
		printf("memory2 is not allocated\n");
	}


	mul.result = malloc(mul.m1_row *  sizeof(int *));
	for(int i = 0; i < mul.m1_row; i++)
	{
		mul.result[i] = malloc(mul.m2_col * sizeof(int *));
	}


	if(mul.result == NULL)
	{
		printf("memory3 is not allocated\n");
	}

	//prompt the user to enter the elements
	for(int i = 0; i < mul.m1_row; i++)
	{
		printf("matrix 1 row%d elements\n", i);
		for(int j = 0; j < mul.m1_col; j++)
		{
			scanf("%d", &(mul.matrix1[i][j]));
		}
	}

	//matrix2
	for(int i = 0; i < mul.m1_col; i++)
	{
		printf("matrix 2 row%d elements\n", i);
		for(int j = 0; j < mul.m2_col; j++)
		{
			scanf("%d", &(mul.matrix2[i][j]));
		}
	}


	//number of threads to create
	pthread_t tid[mul.m1_row];

	/* Create thread one */
	for(int i = 0; i < mul.m1_row; i++)
	{


		if ((errno = pthread_create(&tid[i], NULL, thread, NULL )) !=     0)
		{
			perror("pthread_create()");
			exit(1);
		}
	}

	for(int i = 0; i < mul.m1_row ; i++)
	{

		pthread_join(tid[i], NULL);
	}

	//resultant matrix
	printf("matrix1:\n");
	print_matrix(mul.matrix1, mul.m1_row, mul.m1_col);
	putchar('\n');
	printf("matrix2:\n");
	print_matrix(mul.matrix2, mul.m1_col, mul.m2_col);
	putchar('\n');
	printf("result matrix:\n");
	print_matrix(mul.result, mul.m1_row, mul.m2_col);
	putchar('\n');
}

//

void print_matrix(int **ptr, int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%4d", ptr[i][j]);

		}
		putchar('\n');
	}


}
