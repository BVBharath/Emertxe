/*
1. In execvp, everytning can be passed at the run time.
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("Before exec my Id : %d\n", getpid());
	printf("Before exec my Parent Id : %d\n", getppid());
	
	char *temp[3] = {"2_exec", "2_exec", (char *)0};
	
	execvp(temp[0], temp);

	printf("This line will not be executed\n");
}
