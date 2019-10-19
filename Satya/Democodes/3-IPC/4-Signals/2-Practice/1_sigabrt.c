#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("My PID: %d\n", getpid());
	printf("I am getting aborted\n");
	printf("You can inspect core dump file\n");
	abort();
}

/*
1. Generate the core dump file by setting the below,
$ulimit -c unlimited.
since by default, core file size is zero.

2. Then run the core file in GDB,
$gdb <executable> <core-file>
Example:
$gdb a.out core

Note: Before generating core file make sure, the program is compiled with the -g option.

*A process is sent this signal when it calls the abort() function. 
*By default, this signal terminates the process with a core dump. 
*This achieves the intended purpose of the abort() call: to produce a core dump for debugging.

*/
