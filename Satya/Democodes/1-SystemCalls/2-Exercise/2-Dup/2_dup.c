#include "common.h"

int main()
{
	int fd = open("log", O_WRONLY | O_APPEND);

    if (fd == -1 )
	{
        printf("Error opening the file\n");
	}

    dup2(fd, 1);

	write(fd, "Bye\n", 4);
	printf("Welcome to linux Internals\n");

    return 0;
}
