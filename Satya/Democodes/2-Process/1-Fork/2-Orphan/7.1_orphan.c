/*
1. Orphan: Parent dies before the child termination
2. Orphan child will be adopted by the process dispatcher(upstart)
*/

#include <unistd.h>
#include <stdio.h>

int main()
{
	//Declare the variable
	pid_t pid;


	//Create the child process
	pid = fork();

	switch (pid)
	{
		//On error, fork() returns -1
		case -1:
			printf("Fork() system call failed\n");
			break;
		//Child return 0 to itself	
		case 0:
			printf("I am the child, my PID: %d\n", getpid());
			printf("I am the child's parent, my PID: %d\n", getppid());
			sleep(20);
			printf("I am the child, my PID: %d\n", getpid());
			printf("I am the child's parent, my PID: %d\n", getppid());
			break;		
		//Child returns non-zero positive value to the parent	
		default:
			printf("I am the parent, my PID: %d\n", getpid());
			printf("I am the parent's parent, my PID: %d\n", getppid());
	}
	 printf("Hello\n");
	
	return 0;
}
