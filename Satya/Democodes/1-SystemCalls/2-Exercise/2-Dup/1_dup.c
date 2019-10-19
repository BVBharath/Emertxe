#include "common.h"

int main()
{
	int fd = open("log", O_WRONLY | O_APPEND);

    if (fd == -1 )
	{
        printf("Error opening the file\n");
	}

    int c_fd = dup(fd);

    write(fd, "Hello\n", strlen("Hello\n"));
    write(c_fd, "World\n", strlen("World\n"));

    return 0;
}
