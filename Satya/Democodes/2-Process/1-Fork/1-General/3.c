/*
1. It is forking process, the multi-tasking capability can be exploited.
*/

#include <unistd.h>
#include <stdio.h>

int main()
{
	//Create the child process
	fork();
	fork();
	fork();

	printf("Hello World\n");
}
