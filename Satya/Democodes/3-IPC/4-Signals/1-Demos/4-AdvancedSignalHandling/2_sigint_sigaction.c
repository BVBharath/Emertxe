/*
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void new_handler(int signum, siginfo_t *ptr, void *context);

int main()
{
	struct sigaction act, oldact;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = new_handler; 

	sigaction(SIGINT, &act, NULL);
	
	puts("Type ctrl + c\n");

	while (1);
}

void new_handler(int signum, siginfo_t *ptr, void *context)
{
	printf("Signal Caught with number: %d\n", signum);
	printf("More Details--->\n");
	printf("Signal Number: %d\n", ptr->si_signo);
	printf("Error Value: %d\n", ptr->si_errno);
	printf("Signal Code: %d\n", ptr->si_code);
	printf("Sending process ID: %d\n", ptr->si_pid);
	signal(SIGINT, SIG_DFL);
}
