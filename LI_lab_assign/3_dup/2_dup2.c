/*
Title:closing the stdout buffer and bypassing into file using dup2 system call
Name: Bharath
Organization:Emertxe

 */
//library
#include "common.h"

int main(int argc, char *argv[])
{

	//validation of inputs
	if(argc  < 2 || argc > 2)
	{
		printf("please provide valid inputs\n");
		return 0;
	}

	//initialize the variables
	int fd;

	//before closing output buffer
	printf("before closing output buffer\n");


	//opening a file + handle the error
	fd = open(argv[1], O_EXCL | O_CREAT| O_WRONLY,0644);


	if(fd == -1)
	{

		if(errno == EEXIST)
		{

			//opening the file with truncated mode
			fd = open(argv[1], O_TRUNC | O_WRONLY );
			//bypass into file
			dup2(fd, 1);
			printf("hello world 456");
		}
		else
		{
			perror(argv[1]);	
			exit(1);
		}
	}
	else
	{
		//bypassing  into file
		dup2(fd, 1);
		printf("world");
	}
}	
