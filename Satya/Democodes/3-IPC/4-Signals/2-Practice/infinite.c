#include <stdio.h>
#include <unistd.h>

int main()
{
	long i;

	for (i = 0; i < 100000; i++)
	{
		printf("i: %ld\n", i);
		sleep(1);
	}
}
