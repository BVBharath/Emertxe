/*
1. Code to demonstrate SIGILL.
**********NOT WORKING*******
*/

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

void signal_handler(int);

typedef void (*foo)(void);

int main()
{
	signal(SIGILL, signal_handler);
	
	//Code to generate SIGILL
	int *bad = malloc(16);
	memset(bad, 255, 16);
	((foo)bad)();

	while(1);
}

void signal_handler(int num)
{
	printf("Caught: Illegal Instruction with signal number: %d\n", num);
}

/*
   1. Default task, when ctrl+c is pressed, the process will be termiated.
   2. SIGFPE, SIGSEGV, SIGILL: All will get undefined results.
 */
