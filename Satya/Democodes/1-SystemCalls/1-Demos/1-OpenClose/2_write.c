#include <stdio.h>
#include <unistd.h>

int main()
{
	//printf("Hi Everyone!\n");
	write(1, "Hi Everyone!\n", 50);

	return 0;
}
