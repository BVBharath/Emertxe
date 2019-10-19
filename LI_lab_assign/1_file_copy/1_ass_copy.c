/*
Name: Bharath
Organization: Emertxe
Title: File copy with or without permission

 */

#include "common.h"

//protoype
void my_copy(int fs, int fd);

//driver
int main(int argc, char *argv[])
{

	//validation
	if(argc < 3 || argc > 4)
	{
		printf("no valid inputs\n");
		exit(1);
	}

	//initialization
	int fs, fd, i;
	char ch;
	ssize_t count;
	struct stat file_status;

	//1.open the source file + handle the error
	if(strcmp(argv[1], "-p") == 0)
	{
		i = 2;
	}
	else
	{
		i = 1;
	}

	fs = open(argv[i], O_RDONLY);

	//validation
	if(fs == -1)
	{
		perror(argv[i]);
		exit(1);
	}


	//2.open destination file + error handling
	fd = open(argv[i+1], O_EXCL | O_CREAT |  O_WRONLY, 0644);

	/*	if(i == 2)
		{
		fstat(fs, &file_status);
		fchmod(fd, file_status.st_mode);
		}*/

	//validation
	if(fd == -1)
	{
		//if it already exist
		if(errno == EEXIST)
		{
			//prompt for user
			printf("do u want to copy\n1.press y for yes\n2.pres n for no\n");
			ch = getchar();

			if(ch == 'y' )
			{
				fd = open(argv[i+1],  O_TRUNC | O_WRONLY);
				if(i == 2)
				{
					fstat(fs, &file_status);
					fchmod(fd, file_status.st_mode);
				}


				//calling function
				my_copy(fs, fd);
			}
			else
			{
				printf("its ur wish\n");
				exit(1);
			}
		}
		else
		{
			perror(argv[i+1]);
			exit(2);
		}
	}
	else
	{
		//calling function
		if(i == 2)
		{
			fstat(fs, &file_status);
			fchmod(fd, file_status.st_mode);
		}


		my_copy(fs, fd);
	}


	//close all files
	close(fs);
	close(fd);

}


//function
void my_copy(int fs, int fd)
{
	//initialization of variables
	ssize_t count;
	char buff[80] = {'0'};

	//copy
	while((count = read(fs, buff, 80)) > 0)
	{
		write(fd, buff, count);
	}

	printf("copy.....done\n");
}
