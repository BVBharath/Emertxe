/*
1. The moment the child dies, it sends the signal to the parent to clear the PCB.
2. The signal sent is SIGCHLD
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);
void signal_handler(int);

int main()
{
	int i;
	switch (fork())
	{
		case -1:
			perror("fork()");
			break;
		case 0:
			sleep(5);
			break;
		default:
			signal(SIGCHLD, signal_handler);
			for (i = 0; i < 10; i++)
			{
				printf("i:%d\n", i);
				sleep(1);
			}
			printf("Parent is terminated\n");
	}
}

void signal_handler(int num)
{
	printf("Child died\n");
}
