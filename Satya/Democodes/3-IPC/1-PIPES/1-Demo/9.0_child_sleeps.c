/*
1. A pipe is a one way communication channel.
2. A pipe is created using the system call: pipe()
3. A pipe is shared only between two processes which are related to each other.
4. Passing the message between two processes.
5. Closing read end in the parent, write end in the child
6. Child dies, parent hangs.
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
			//Putting the child sleep for 5 seconds
			sleep(5);
			printf("Child: Terminated\n");
			break;
		default:
			printf("Parent is reading..\n");
			//Close the write end for the parent
			close(p[1]);
			read(p[0], buffer, 50);
			printf("Parent: Reading over\n");
	}
}
	

/*
   1. p[0], refers to read end
   2. p[1], refers to write end
   3. The advantage of closing is giving back the file descriptors to the kernel.
   4. For each process, both write and read ends are associated with it.
   5. When the child terminates, child closes both the file descriptors i.e read and write.
   6. For the parent, both are open. Thats why parent was hanging.
   7. Close the write end for the parent and run again.
   8. Since, the write end for the child is still not terminated, hence the parent waits.
   9. After 5 seconds, childs wakes up, and terminates by closing the write and read ends of it. As, a result parent terminates.
 */
