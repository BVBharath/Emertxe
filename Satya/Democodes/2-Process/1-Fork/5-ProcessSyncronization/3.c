/*
1. How to wait for more than one child to terminate.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid1;
	pid_t pid2;

	pid1 = fork();

	switch(pid1)
	{
		case 0:
			printf("1st Child, PID: %d\n", getpid());
			printf("1st child died\n");
			break;
		default:
			pid2 = fork();

			switch (pid2)
			{
				case 0:
					printf("2st Child, PID: %d\n", getpid());
					printf("2st child died\n");
					break;
				default:
					sleep(20);
					printf("I am the parent, I am dying now\n");				
			}
			
	}
	return 0;
}

/*
Problems:
1. If parent process ended before the children, both children becomes ORPHANs
2. Both children dies, now parent start executing, ending up with ZOMBIEs
*/
