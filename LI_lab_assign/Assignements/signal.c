#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sig_handler(int signum,siginfo_t *p,void *q)
{
	printf("Memory fault : %p\n",p -> si_addr);
	exit(0);
}

int main()
{
	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_handler;
	sigaction(SIGSEGV,&act,NULL);
	
	int a = *(int *)10;
	/*printf("Enter a number:");
	scanf("%d",a);*/

}


