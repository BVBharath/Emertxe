/*
./a.out 2> error.log
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int pid, status;
	int fd;	

	if ((fd = open("error.log", O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) 
	{
		perror("error.log");	
		exit(1);
	}

	close(2);
	dup(fd); 

	system("ls -l temp");

	exit(0);
}
