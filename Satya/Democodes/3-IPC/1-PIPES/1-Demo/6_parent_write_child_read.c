/*
1. A pipe is a one way communication channel.
2. A pipe is created using the system call: pipe()
3. A pipe is shared only between two processes which are related to each other.
4. Passing the message between two processes.
Note:
	- Parent is writing one int at a time entered by the user
	- Child is reading and printing.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//Declare to hold the file descriptors
	int p[2];
	int buff;
	int input;

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
			while (1)
			{
				sleep(1);
				read(p[0], &buff, sizeof(int));
				printf("Child: Reading over, value: %d\n", buff);
			}
			break;
		default:
			while (1)
			{
				printf("Enter the value: ");
				scanf("%d", &input);
				write(p[1], &input, sizeof(int));
				printf("Parent: Writing over\n");
			}
	}
}


/*
   1. p[0], refers to read end
   2. p[1], refers to write end
 */
