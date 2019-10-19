/*
1. In the exec() calls, the main process is terminated by overwriting it by the other process.
2. This gives the blend of both fork() + execl()
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	switch (fork())
	{
		case 0:
			printf("Child: exec starts\n");
			execl("/bin/ls", "ls", "-l", (char *)0);
			printf("This line will not be executed\n");
			break;
		default:
			wait(0);
			printf("Parent: ls -l is completed\n");
	}
}
