/*
1. wait system call, makes the parent process to wait till the child process dies.
2. Child process returns the exit status, parent can collect in the status variable.
3. In the status variable, the exit status value returned by the parent will be in lower 2 bytes.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int exit_status;
	int exit_value = 10;

	switch (fork())
	{
		case -1:
			printf("fork(): Failed\n");
			exit(1);
		case 0:
			printf("Child: Terminating with exit value: %d\n", 10);
			exit(exit_value);
		default:
			wait(&exit_status);
			printf("Parent: Child terminated with the exit_value: %d\n", WEXITSTATUS(exit_status));
			//printf("Exit value: %X\n", exit_status);
			exit(20);
	}
}
