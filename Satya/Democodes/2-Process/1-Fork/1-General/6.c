/*
1. It is forking process, the multii-tasking capability can be exploited.
2. Process IDi can be obtained from the getpid() system call.
3. After forking, child will return 0 to itself and returns PID to the parent.
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
			printf("I am the child process, my PID: %d\n", getpid());
			printf("I am the child process, my PPID: %d\n", getppid());
			break;		
		//Child returns non-zero positive value to the parent	
		default:
			printf("I am the parent process, my PID: %d\n", getpid());
	}
	
	return 0;
}




















