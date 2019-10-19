/*
1. Zombie: Child dies, but not removed form the PROCESS TABLE.
2. The kernel empties the process address space but retains the process table entry.
3. Zombie is not the process, hence cannot be killed using the kill command.
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
			break;		
		//Child returns non-zero positive value to the parent	
		default:
			sleep(50);
			printf("I am the parent, my PID: %d\n", getpid());
			printf("I am the parent's parent, my PID: %d\n", getppid());
	}
	
	return 0;
}
