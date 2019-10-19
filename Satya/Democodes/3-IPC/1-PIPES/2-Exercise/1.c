/*
1. Implement ls | wc -l
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	//Declare an array
	int p[2];

	//Create the pipe
	pipe(p);

	switch (fork())
	{
		case -1:
			perror("fork()");
			exit(EXIT_FAILURE);
		case 0:
			//Close the write end from the child
			close(p[1]);
			dup2(p[0], 0);
			execlp("wc", "wc", "-l", (char *)0);
			break;
		default:
			//Close the read end for the parent
			//close(p[0]);
			dup2(p[1], 1);
			execlp("ls", "ls", (char *)0);
	}
}
