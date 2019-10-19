/*
1. The shell, as we know is the process running in the backgroud.
2. This shell is waiting to recieve the input from the user.
3. As soon as the user gives the input, the shell creates the child and the executes the command by using any one of the exec family.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[])
{
	long start, end;
	time(&start);
	switch (fork())
	{
		case 0:
			execvp(argv[1], &argv[1]);
			perror("Program failed");
			break;
		default:
			wait(0);
			time(&end);
			printf("Time taken: %ld\n", end - start);
	}
}
