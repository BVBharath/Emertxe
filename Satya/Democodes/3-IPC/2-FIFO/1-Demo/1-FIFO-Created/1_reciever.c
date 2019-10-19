/*
1. PIPES: Drawbacks
	- Pipes are used for communication between Parent & Child OR Between two processes which are related to each other.
	- Pipes are not PERMANENT, termination of the process leads to destruction of the PIPE.
2. To overcome the above drawbacks, FIFO or Named PIPES are used.
3. FIFO is nothing but regular file.
4. Named PIPE can be created using the command mknod.
	- mknod myfifo p
		- mknod: Command
		- myfifo: Named pipe
		- p: PIPE
	- This command only creates the FIFO, will not open it.	
5. cat < myfifo &
	- cat is trying to read from the file called myfifo, but the file is EMPTY.
	- cat waits, until another process writes something to it.
	- FIFO will be opened only when the other process writes to it.
6. ls -l > myfifo, As soon as ls writes the output to the FIFO, the cat who is waiting will read and print the output.
7. Do, point-6 and point-7 in separate terminals.
*/

/*
Description:
	This is the reciever program, keeps waiting in the loop to read the message send by the sender.
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd;
	char buffer[25];
	int count;

	//Open the file
	if ((fd = open("myfifo", O_RDWR)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if ((count = read(fd, buffer, 25)) > 0)
		{
			printf("MESSAGE: %s\n", buffer);
			memset(buffer, '\0', 25);
		}
	}
}





