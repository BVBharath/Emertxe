/*
1. How to wait for more than one child to terminate.
2. wait() will returns the value of the child's PID which has been removed from the PROCESS TABLE.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid1;
	pid_t pid2;
	int status;

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
					printf("2nd Child, PID: %d\n", getpid());
					printf("2nd child died\n");
					break;
				default:
					status = wait(0);
					printf("Child with PID: %d died\n ", status);
					status = wait(0);
					printf("Child with PID: %d died\n ", status);

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
