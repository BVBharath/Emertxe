/* system()  executes  a  command specified, and returns after the command has been completed. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int status;

	status = system(argv[1]);
	
	if (status == -1)
	{
		perror("System");
	}

	else
	{
		printf("Success : %d\n", status);
	}
}
