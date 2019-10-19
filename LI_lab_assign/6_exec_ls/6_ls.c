/*
Title: exec.c
Name : Bharath


*/

#include "common.h"


//driver
int main(int argc, char *argv[])
{
	//initialize the variables
	int wstatus;	
	

	//validation of input
	if(argc == 1)
	{
		printf("give sufficient inputs....\n");
		exit(1);
	}


	//creation of child process
	pid_t pid = fork();

	switch(pid)
	{
		case 0:
			//exec process
			if(execvp(argv[1], argv + 1) == -1)
			{
				printf("invalid command\n");
			}
			break;

		case -1:
			perror("fork()");
			break;

		default:
			waitpid(pid, &wstatus, 0);

			if(WIFEXITED(wstatus))
			{
				printf("child terminated with exit status %d\n", WEXITSTATUS(wstatus));
			}


	}
}
