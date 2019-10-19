/*
	1. exec loads the new program specified into memory of calling process.
	2. The exec() family of functions replaces the current process image with a new process image.
	3. On success never returns to old process. On failure continues with the old process.
	4. Old and new process will have same PID and PPID.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Before exec my Id : %d\n", getpid());
	printf("Before exec my Parent Id : %d\n", getppid());

	execl("2_exec", "2_exec", (char *)0);

	printf("This line will not be executed\n");
}
