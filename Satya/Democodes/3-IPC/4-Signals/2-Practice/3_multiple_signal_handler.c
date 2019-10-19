/*
1. Press ctrl + c for SIGINT
2. Press ctrl + \ for SIGQUIT
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
typedef void (*sighandler_t)(int);
void signal_handler(int signum);
int main()
{
	int i;

	//Call the signal
	if (signal(SIGINT, signal_handler) == SIG_ERR)
	{
		perror("signal");
		exit(0);
	}

	if (signal(SIGQUIT, signal_handler) == SIG_ERR)
	{
		perror("signal");
		exit(0);
	}

	/* Loop forever, waiting for signals */
	for (;;)
	{
		/* Block until a signal is caught */
		pause();
	}
}

void signal_handler(int signum)
{
	printf("Signal Caught with number: %d\n", signum);

	static int count = 0;
	
	if (signum == SIGINT) 
	{
		count++;
		printf("Caught SIGINT (%d)\n", count);
		return;
		/* Resume execution at point of interruption */
	}
	
	/* Must be SIGQUIT - print a message and terminate the process */
	printf("Caught SIGQUIT - that's all folks!\n");
	exit(EXIT_SUCCESS);
}
