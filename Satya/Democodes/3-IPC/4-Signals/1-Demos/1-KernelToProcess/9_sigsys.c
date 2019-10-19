/*
1. Code to demonstrate SIGSYS.
*****NOT WORKING*****
*/

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


typedef void (*sighandler_t)(int);

void signal_handler(int);

int main()
{
	signal(SIGSYS, signal_handler);

	//Code to generate SIGSYS
	int fd = open("sample.txt", O_RDONLY);
	lseek(fd, 1, 1905);

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
