/*
1. Code to demonstrate SIGFPE.
*/

#include <stdio.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void signal_handler(int);

int main()
{
	int a = 0, b = 10;

	signal(SIGFPE, signal_handler);

	//Code generating divide by zero
	int res = b / a;

	while(1);
}

void signal_handler(int num)
{
	printf("Caught: Illegal Instruction with signal number: %d\n", num);
	//signal(SIGINT, SIG_DFL); This is not needed explicity
}

/*
   1. Default task, when ctrl+c is pressed, the process will be termiated.
   2. SIGFPE, SIGSEGV, SIGILL: All will get undefined results.
 */
