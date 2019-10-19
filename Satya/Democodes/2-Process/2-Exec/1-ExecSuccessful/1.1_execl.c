/*
	1. exec loads the new program specified into memory of calling process.
	2. The exec() family of functions replaces the current process image with a new process image.
	3. On success never returns to old process. On failure continues with the old process.
	4. Old and new process will have same PID and PPID.
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("Before exec my Id : %d\n", getpid());
	printf("Before exec my Parent Id : %d\n", getppid());

	//execl("/bin/ls", "ls", "-l", (char *)NULL);
	//execlp(argv[1], argv[2], argv[3], (char *)NULL);
	execvp(argv[1], &argv[2]);

	printf("This line will not be executed\n");
}
