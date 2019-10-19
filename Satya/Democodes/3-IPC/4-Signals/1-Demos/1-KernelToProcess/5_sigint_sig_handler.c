/*
1. Code to demonstrate signal handler repeatedly.
*/

#include <stdio.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void signal_handler(int);

int main()
{
	puts("Type: Ctrl + c");
	signal(SIGINT, signal_handler);
	while(1);
}

void signal_handler(int num)
{
	puts("You have pressed: Ctrl+c");
	//signal(SIGINT, signal_handler);
	signal(SIGINT, SIG_DFL);
}

/*
1. Default task, when ctrl+c is pressed, the process will be termiated.
2. We are overriding the default task by redefining it.
3. In the function again calling the signal.
*/
