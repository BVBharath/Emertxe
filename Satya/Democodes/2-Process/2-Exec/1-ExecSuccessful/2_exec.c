#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("\nI am the new program got loaded on exec\n");
	printf("After exec my Id : %d\n", getpid());
	printf("After exec my Parent Id : %d\n", getppid());

}
