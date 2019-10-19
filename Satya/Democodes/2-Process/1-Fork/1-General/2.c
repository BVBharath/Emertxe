/*
1. It is forking process, the multi-tasking capability can be exploited.
*/

#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("This statement will be executed only by the parent\n");

	//Create the child process
	fork();

	printf("Hello World\n");
}
