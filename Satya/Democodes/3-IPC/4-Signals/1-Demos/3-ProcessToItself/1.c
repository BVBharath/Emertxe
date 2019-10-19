/*
1. Three ways of sending the signal to the process.
	- Kernel to process.
	- Process to process
	- Process to itself
2. We will learn, process to itself method.	
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);
void signal_handler(int);

int main()
{
	signal(SIGUSR1, signal_handler);
	sleep(2);
	printf("I am waking-up from the sleep\n");
	printf("I am about to suicide\n");
	kill(getpid(), SIGUSR1);
}

void signal_handler(int num)
{
	printf("Signal Received: %d\n", num);
}
