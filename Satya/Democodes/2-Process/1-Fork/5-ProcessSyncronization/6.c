/*
1. Altering the global variable
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int i = 10;

int main()
{
	switch(fork())
	{
		case 0:
			printf("Child PID: %d\n", getpid());
			printf("Before: i: %d\n", i);
			i = i + 10;
			printf("After: i: %d\n", i);
			break;
		default:
			wait(0);
			printf("Parent: PID: %d\n", getpid());
			printf("i: %d\n", i);
			
	}
	return 0;
}

/*
Conclusion:
	Change in one process will not reflect in other
*/
