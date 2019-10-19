/*
1. fork() performed a literal duplication of the parent’s data, heap, and stack.
2. vfork, creates a child process of the calling process without copying the page tables of the parent process.
3. Parent process is suspended untill child process terminates or it makes a call to execve(). Until that point, the child shares all memory   with its parent, including the stack.
4. vfork() is expressly designed to be used in programs where the child performs an immediate exec() call.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int val = 10;

	printf("Parent Process,Before vfork- val : %d\n", val);
	pid = vfork();

	if (pid < 0)
	{
		printf ("vfork failed\n");
	}
	else if (pid == 0)
	{
		printf("Child process- Id : %d\n", getpid());
		printf("Initial value of val : %d\n", val);
		val += 10;
		printf("After incrementing value of val : %d\n", val);
		_exit(0);
	}
	else
	{
		printf("Parent Process, After vfork- val : %d\n", val);
	}
}

