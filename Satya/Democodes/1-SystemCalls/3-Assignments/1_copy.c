#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define ARG_COUNT 3

int main(int argc, char *argv[])
{
	//Clear the output screen
	system("clear");

	struct stat file_permissions;
	char buffer[256];

	//Validate the number of arguments
	if (argc < ARG_COUNT)
	{
		printf("Insufficient Arguments\n");
		printf("Usage: ./copy [option] <source_file> <destination_file>\n");
		exit(1);
	}

	//Specify the flags
	int fs_flags;
	mode_t fs_mode = O_RDONLY;

	//Open the source file + Handle the error
	int fs = open(argv[1], fs_mode);
	if (fs == -1)
	{
		perror(argv[1]);
		exit(2);
	}

	//Specify the flags
	int fd_flags = O_WRONLY | O_CREAT;

	//Open the destination file + Handle the error
	int fd = open(argv[2], fd_flags);
	if (fd == -1)
	{
		perror(argv[2]);
		exit(3);
	}

	//Retrive the file permissions of source file
	fstat(fs, &file_permissions);
	
	//Change the file permissions of the source to destination
	fchmod(fd, file_permissions.st_mode);
	

	int bytes;
	//Copy the contents form source to destination
	while ((bytes = read(fs, buffer, bytes)) > 0)
	{
		write(fd, buffer, bytes);
	}

	//Close the files
	close(fd);
	close(fs);
}
