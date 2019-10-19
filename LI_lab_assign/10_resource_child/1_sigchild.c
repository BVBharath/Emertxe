/*
title:clearing the resources of child using signal

*/


#include "common.h"

pid_t pid;

//signal handler
void signal_handler(int num)
{
	int status;
	waitpid(pid, &status, 0);
	if(WIFEXITED(status))
	{
		printf("child resource is cleared with exit status %d\n", WEXITSTATUS(status));
	}
}

//driver
int main()
{


	//creation of child
	pid = fork();

	//child process
	if(pid == 0)
	{
		sleep(5);
		printf("child move into  zombie\n");

	}

	//parent process
	else
	{

		printf("child id : %d\n", pid);
		signal(SIGCHLD, signal_handler);
		sleep(20);
		printf("parent is terminating\n");
		sleep(20);

	}
}

