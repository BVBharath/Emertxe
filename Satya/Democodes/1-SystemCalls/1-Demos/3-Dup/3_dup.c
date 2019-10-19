#include <stdio.h>

int main()
{
	//1. Open the file using open system call


	printf("Hi\n");

	//2. Close the fd #1
	close(1);

	//3. Duplicate the fd #1
	dup(fd);

	//4. This will routed to error.lof file
	printf("This will be routed to error.log file\n");

	//5. Close all the file open
	close(fd);
}
