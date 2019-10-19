/*
1. What is the output of the following process
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
	int i, j;
	pid_t pid;

	pid = fork();

	switch(pid)
	{
		case 0:
			for (i = 0; i < 10; i++)
			{
				printf("Child: %d\n", i);
				sleep(1);
			}
			break;
		default:
			for (j = 0; j < 10; j++)
			{
				printf("Parent: %d\n", j);
				sleep(1);
			}
	}
	return 0;
}













