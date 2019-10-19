/*
1. A pipe is a one way communication channel.
2. A pipe is created using the system call: pipe()
3. A pipe is shared only between two processes which are related to each other.
4. Passing the message between two processes.
5. Parent is reading, child is writing.
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
			printf("Child: writing...\n");
			write(p[1], msg, strlen(msg));
			printf("Child: Writing over\n");
			break;
		default:
			sleep(1);
			puts("Parent: reading...\n");
			read(p[0], buffer, 50);
			printf("Parent: Reading over, here is the message...\n");
			printf("%s", buffer);
	}
}
	

/*
   1. p[0], refers to read end
   2. p[1], refers to write end
 */
