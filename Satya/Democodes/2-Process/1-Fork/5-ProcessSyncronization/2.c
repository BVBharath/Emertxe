/*
1. What is the output of the following process
2. wait(): 
	- The parent process waits till the child dies.
3. wait() does number of things,
	- A check is made first to see whether the parebt has any children.
	- If it does not -1 will be returned.
	- If the parent has any ZOMBIES, wait() will removes the stuff from the PROCESS TABLE.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
			wait(0);
			for (j = 0; j < 10; j++)
			{
				printf("Parent: %d\n", j);
				sleep(1);
			}
	}
	return 0;
}
