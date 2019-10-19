#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

pid_t pid;
void handler(int signum)
{
	int status;
	waitpid(pid,&status,0);
	if(WIFSIGNALED(status))
	{
		printf("CHild %d terminated with %d\n",pid,WEXITSTATUS(status));
	}
	else if(WIFSTOPPED(status))
	{
		printf("CHild %d terminated with %d\n",pid,WEXITSTATUS(status));

	}
}

int main()
{
	pid = fork();

	switch(pid)
	{
		case -1:
			printf("Not happening\n");
			break;
		case 0:
			printf("PID: %d\n",getpid());
			sleep(5);
		printf("Child is turning Zombie\n");
			break;
		default:
		/*struct sigaction act;
		act.sa_sigaction = handler;
		act.sa_flags = SA_NOCLDWAIT;
		sigaction(SIGCHLD,&act,NULL);*/
		signal(SIGCHLD,handler);
		sleep(7);
		printf("Parent is terminating\n");
		sleep(20);
		break;
	}
}
