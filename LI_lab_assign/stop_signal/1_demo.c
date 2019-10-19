#include "common.h"

void signal_handler(int num)
{
	int i = 100;
	if(num == SIGQUIT)
	{
	printf("Inside Handler\n");
	while(--i)
	{
		printf("Inside Handler\n");
		sleep(10);
	}
	}
}

int main()
{
	//
	struct sigaction s;
	sigset_t block_mask;
	sigemptyset(&s.sa_mask);

	sigfillset(&s.sa_mask);
	sigdelset(&s.sa_mask, SIGQUIT);
	s.sa_handler = signal_handler;

	s.sa_flags = 0;
	printf("pid: %d\n", getpid());
	sigaction(SIGQUIT, &s, NULL);

	while(1);
	
}
