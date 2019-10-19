/*
1. Three ways of sending the signal to the process.
	- Kernel to process.
	- Process to process
	- Process to itself
2. We will learn, process to process method.	
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);
void signal_handler(int);

int main()
{
	pid_t pid;

	switch (pid = fork())
	{
		case -1:
			perror("fork()");
			break;
		case 0:
			printf("Child-PID: %d\n", getpid());
			signal(SIGINT, signal_handler);
			sleep(2);
			break;
		default:
			sleep(1);
			kill(pid, SIGINT);
			sleep(5);
			printf("Parent Terminated\n");
	}
}

void signal_handler(int num)
{
	printf("Signal received with number: %d\n", num);
}
