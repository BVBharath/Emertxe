#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum,siginfo_t *p,void *q)
{
	int i = 10;
	while(--i)
	{
		printf("Hello\n");
		sleep(10);
	}
}

int main()
{
	struct sigaction act;
	sigset_t new;
	act.sa_flags = 0;
	act.sa_sigaction = sig_handler;
	printf("PID:%d\n",getpid());
	sigaction(SIGQUIT,&act,NULL);
	sigemptyset(&new);
	sigaddset(&new,SIGINT);
//	sigfillset(&new);
//	sigdelset(&new,SIGINT);
	act.sa_mask = new;
	while(1);
}

