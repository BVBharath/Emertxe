/*
1. It is forking process, the multii-tasking capability can be exploited.
2. Process ID can be obtained from the getpid() system call.
*/

#include <unistd.h>
#include <stdio.h>

int main()
{
	//Create the child process
	fork();
	
	printf("The pid: %d\n", getpid());

	while (1);
}
