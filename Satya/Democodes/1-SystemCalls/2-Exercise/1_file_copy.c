/*
1. Program to copy the contents of one file to the other file
2. This program uses
	- open
	- read
	- write
	- close system calls
*/
#include "common.h"

int main(int argc, char *argv[])
{
	//Declare the file descriptor
	int fs, fd;
	char buffer[256];
	int count;

	//Open the source file + Handle the error
	fs = open(argv[1], O_RDONLY);
	if (fs == -1)
	{
		perror(argv[1]);
		return -1;
	}

	//Open the destination file + Handle the error
	fd = open(argv[2], O_WRONLY);
	if (fd == -1)
	{
		perror(argv[2]);
		return -1;
	}

	//Copy the contents from source to destination
	while ((count = read(fs, buffer, 256)) > 0)
	{
		write(fd, buffer, count);
		memset(buffer, '\0', 256);
	}

	close(fd);
	close(fs);
}
