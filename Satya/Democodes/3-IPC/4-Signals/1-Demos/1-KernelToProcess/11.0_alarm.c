/*
1. Code to demonstrate the alarm system call.
2. alarm is used to set the alarm.
3. When once the timer expires, the kernel will send the signal alarm to the process.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	alarm(5);
	while(1);
}

