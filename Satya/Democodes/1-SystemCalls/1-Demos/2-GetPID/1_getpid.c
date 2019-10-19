#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t status;

	status = getpid();

	printf("PID: %d\n", status);

	return 0;
}
