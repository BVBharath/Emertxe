/*
1. A pipe is a one way communication channel.
2. A pipe is created using the system call: pipe()

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	//Declare to hold the file descriptors
	int p[2];

	//Create the pipe
	if (pipe(p) == -1)
	{
		perror("PIPE");
		exit(EXIT_FAILURE);
	}

	printf("p[0]: %d\np[1]: %d\n", p[0], p[1]);
}

/*
1. p[0], refers to read end
2. p[1], refers to write end
*/
