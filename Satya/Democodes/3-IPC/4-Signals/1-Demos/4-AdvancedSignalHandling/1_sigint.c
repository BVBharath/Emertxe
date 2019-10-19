/*
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void new_handler(int signum);

void old_handler(int signum);
int main()
{
	struct sigaction act, oldact;
	//act.sa_handler = new_handler; 
	//oldact.sa_handler = SIG_DFL;

	act.sa_handler = new_handler; 
	oldact.sa_handler = old_handler;
	//sigaction(SIGINT, &act, NULL);
	//sigaction(SIGINT, NULL, &oldact);
	sigaction(SIGINT, NULL, NULL);
	
	puts("Type ctrl + c\n");

	while (1);
}

void old_handler(int signum)
{
	printf("Signal Caught with number: %d\n", signum);
	signal(SIGINT, SIG_DFL);
}
void new_handler(int signum)
{
	printf("Signal Caught with number: %d\n", signum);
	signal(SIGINT, SIG_DFL);
}
