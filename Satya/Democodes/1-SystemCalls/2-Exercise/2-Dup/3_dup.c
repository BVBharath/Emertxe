#include "common.h"

int main()
{
	int fd = open("log", O_WRONLY | O_APPEND);

	close(1);
	int n_fd = dup(fd);

	printf("Welcome to linux Internals\n");
	write(n_fd, "Hai\n", 4);

    return 0;
}
