/*
1. Code to demonstrate signal handler.
*/

#include <stdio.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void signal_handler(int);

int main()
{
	puts("Type: Ctrl + c");
	signal(SIGINT, SIG_DFL);
	while(1);
}

void signal_handler(int num)
{
	puts("You have pressed: Ctrl+c");
}

/*
1. Default task, when ctrl+c is pressed, the process will be termiated.
*/
