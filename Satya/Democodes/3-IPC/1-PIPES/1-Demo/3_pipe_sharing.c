/*
1. A pipe is a one way communication channel.
2. A pipe is created using the system call: pipe()
3. A pipe is shared only between two processes which are related to each other.
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
	
	switch (fork())
	{
		case -1:
			perror("fork()");
			break;
		case 0:
			printf("Child: ");
			printf("p[0]: %d\tp[1]: %d\n", p[0], p[1]);
			break;
		default:
			printf("Parent: ");
			printf("p[0]: %d\tp[1]: %d\n", p[0], p[1]);
	}
}
	

/*
   1. p[0], refers to read end
   2. p[1], refers to write end
 */
