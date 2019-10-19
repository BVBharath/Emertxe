/*
1. Code to demonstrate signal handler with two signal calls in it.
*/

#include <stdio.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void signal_handler(int);

int main()
{
	puts("Type: 'Ctrl + c' OR 'Ctrl + \\'");
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	while(1);
}

void signal_handler(int sig_num)
{
	printf("Signal received with sig-num: %d\n", sig_num);
	signal(SIGINT, SIG_DFL);
}

/*
1. Default task, when ctrl+c is pressed, the process will be termiated.
2. We are overriding the default task by redefining it.
*/
