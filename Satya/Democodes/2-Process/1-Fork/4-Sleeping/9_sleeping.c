/*
1. Sleeping: In the process table, the second column is indicating by 'S'
2. 
*/

#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("My PID: %d\n", getpid());
	printf("Run the ps -el command\n");
	sleep(20);
	printf("Woke-up from sleep\n");
	printf("Run the ps -el command\n");
	while (1);

	return 0;
}
