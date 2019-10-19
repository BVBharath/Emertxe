#include "common.h"

int main()
{
	int fd1, fd2;

	fd1 = open("log1.txt", O_WRONLY | O_APPEND);

	//Handle the error

	fd2 = open("log2.txt", O_WRONLY | O_APPEND);
	
	//Handle the error

	dup2(fd2, fd1);

	write(fd1, "Good\n", 5);

	while (1);

}
