/*
1. 
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
typedef void (*sighandler_t)(int);
void newhandler(int signum);
int main()
{
	int i;

	//Declare pointer
	void (*oldhandler)(int);

	//Call the signal
	if ((oldhandler = signal(SIGINT, newhandler)) == SIG_ERR)
	{
		perror("signal");
		exit(0);
	}

	//Do something here
	for (i = 0; i < 10; i++)
	{
		printf("i: %d\n", i);
		sleep(1);
	}
#if 1
	//Change the disposition to old handler
	if (signal(SIGINT, oldhandler) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}
#endif
	
	//Do something here
	for (i = 0; i < 10; i++)
	{
		printf("j: %d\n", i);
		sleep(1);
	}

	//Change the disposition to SIG_DFL 
	if (signal(SIGINT, SIG_DFL) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}
#endif
	
	//Do something here
	for (i = 0; i < 10; i++)
	{
		printf("k: %d\n", i);
		sleep(1);
	}

	//Change the disposition to SIG_IGN
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}
#endif
	
	//Do something here
	for (i = 0; i < 10; i++)
	{
		printf("m: %d\n", i);
		sleep(1);
	}



}

void newhandler(int signum)
{
	printf("Signal Caught with number: %d\n", signum);
}
