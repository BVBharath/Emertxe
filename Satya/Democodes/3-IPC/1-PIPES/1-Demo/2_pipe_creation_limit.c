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

	//To hold the count of the pipes
	int count = 0;

	while (1)
	{
		//Create the pipe
		if (pipe(p) == -1)
		{
			printf("No. of PIPES: %d\n", count);
			perror("PIPE");
			exit(EXIT_FAILURE);
		}
		count++;
		printf("p[0]: %d\tp[1]: %d\n", p[0], p[1]);
	}
}

/*
   1. p[0], refers to read end
   2. p[1], refers to write end
 */
