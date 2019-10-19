/*
1. A pipe is a one way communication channel.
2. A pipe is created using the system call: pipe()
3. A pipe is shared only between two processes which are related to each other.
4. Passing the message between two processes.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//Declare to hold the file descriptors
	int p[2];
	char *msg = "Hello, how are you!!!\n";
	char buffer[50];

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
			sleep(1);
			puts("Child is reading...\n");
			read(p[0], buffer, 50);
			printf("Child: Reading over, here is the message...\n");
			printf("%s", buffer);
			break;
		default:
			printf("Parent is writing...\n");
			write(p[1], msg, strlen(msg));
			printf("Parent: Writing over\n");
	}
}
	

/*
   1. p[0], refers to read end
   2. p[1], refers to write end
 */
