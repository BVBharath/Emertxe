#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


void handler(int signum)
{
	printf("Signal Recieved\n");
	exit(0);
}

int main()
{
	printf("Alarm raises after 5 secs\n");
	time_t tm;
	time(&tm);
	printf("%ld\n",tm);
	signal(SIGALRM,handler);
	alarm(5);
	while(1);
}

