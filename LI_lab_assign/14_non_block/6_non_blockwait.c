#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	//Creating a child process
	pid_t pid = fork();
	int status;
	switch(pid)
	{
		case -1:
			printf("Not happening\n");
			break;
		case 0:
			sleep(5);
			break;
		default:
			while(1)
			{
				//if WNOHANG is set waitpid will return 1 that is child process is done and parent is not blocked at all
				if(waitpid(pid,&status,WNOHANG))
				{
					break;
				}
				sleep(1);
				printf("Parent is running\n");
			}
			//Check for the status of exit
			if(WIFEXITED(status))
			{
				printf("Child %d terminated with %d",pid,WEXITSTATUS(status));
			}
	}
}
