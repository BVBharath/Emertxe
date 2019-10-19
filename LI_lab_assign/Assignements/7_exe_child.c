#include "common.h"

int main(int argc,char **argv)
{
	int status;
	//If no arguments are passed
	if(argc == 1)
	{
		printf("Usage:\n");
		printf("%s arguments..\n",argv[0]);
		return 0;
	}
	//creating a child
	pid_t pid = fork();
	switch(pid)
	{
		case -1 :
				printf("not happening\n");
				break;
		case 0:
				wait(0);
				//Using execvp to run the other process
				int new = execvp(argv[1],argv+1);
				if(new == -1)
				{
					perror("command\n");
					exit(EXIT_FAILURE);
				}
				break;
		default:
			printf("This is the Child Process,with id %d\n",pid);
			//waiting till the child process is completed and then continue
			waitpid(pid,&status,0);
			if(WIFEXITED(status))
			{
				printf("Child exited with status %d\n", WEXITSTATUS(status));
			}
			else
			{
				printf("Child exited Abnormally\n");
				printf("Child exited with status %d\n",WEXITSTATUS(status));
			}
				

	}
}
