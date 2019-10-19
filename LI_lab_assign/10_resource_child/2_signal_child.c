#include "common.h"

//signal handler
void signal_handler(int num)
{
	printf("child resource is cleared\n");
}

//driver
int main()
{
	//initialization of variables
	struct sigaction s;

	s.sa_handler = signal_handler;

	s.sa_flags = SA_NOCLDWAIT | SA_SIGINFO;

	pid_t pid;


	//creation of child
	pid = fork();

	if(pid == 0)
	{
		sleep(5);

	}
	else
	{
		printf("child id : %d\n", pid);
		sigaction(SIGCHLD, &s, NULL);
		sleep(20);
		printf("parent is terminating\n");
		sleep(20);

	}
}
