/*
1. wait() is having number of limitations.
	- It blocks the parent process until the child dies.
	- If parent spawns several children, wait returns the moment one of them dies.
	- wait() can't wait for the child with specific ID to die.
2. To overcome the above limitations, waitpid() is introduced.	
3. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int exit_status;
	int exit_value = 10;
	pid_t pid = fork();

	switch (pid)
	{
		case -1:
			printf("fork(): Failed\n");
			exit(1);
		case 0:
			printf("Child: Terminating with exit value: %d\n", 10);
			exit(exit_value);
		default:
			waitpid(pid, &exit_status, 0);
			/*
			1. -1 indicates, waitpid blocks until a child dies or changes the state.
			2. exit_status, the variable which holds the exit status of the child.
			3. 0, indicates waitpid blocks the parent until the child changes the state.
			*/
			printf("Parent: Child terminated with the exit_value: %d\n", WEXITSTATUS(exit_status));
			//printf("Exit value: %X\n", exit_status);
			exit(20);
	}
}
