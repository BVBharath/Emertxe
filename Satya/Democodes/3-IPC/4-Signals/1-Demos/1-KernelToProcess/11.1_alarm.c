/*
1. Code to demonstrate the alarm system call.
2. alarm is used to set the alarm.
3. When once the timer expires, the kernel will send the signal alarm to the process.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef void (*sighandler_t)(int);
void signal_handler(int num);

int main()
{
	signal(SIGALRM, signal_handler);
	alarm(5);
	while(1);
	//pause();
}

void signal_handler(int num)
{
	printf("Received signal: %d\n", num);
}

/*
1. pause: To keep the process active.
2. while(1), will waste the CPU cycles whereas pause, keeps the process in wait state.
*/
