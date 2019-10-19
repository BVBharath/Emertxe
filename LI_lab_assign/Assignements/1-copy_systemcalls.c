#include "common.h"
void copy(int fs,int fd);
int main(int argc , char *argv[])
{
	//Declaring two file descriptors
	int fs,fd,i;
	char ch;
	//Structure to store all the file information
	struct stat file_status;
	//Checking whether we gave "-p" or not in the argv[1]
	if(argc == 4 && strcmp(argv[1],"-p") == 0)
	{
		i = 2;
	}
	else
	{
		i = 1;
	}
	//Open the file fs 
	fs = open(argv[i],O_RDONLY);
	if(fs == -1)
	{
		perror(argv[i]);
		exit(1);
	}
	//Open the file fd and create a fie and check if a file aready exits
	fd = open(argv[i+1], O_EXCL | O_CREAT | O_WRONLY,0644);
	//Check the errno whether the file exists
	if(fd == -1 && errno == EEXIST)
	{
		printf("Do you want to continue copying the data? ");
		scanf("%c",&ch);
		if(ch == 'Y' || ch == 'y')
		{
		//If file exists Truncate/clear everything in the file and continue
				fd = open(argv[i+1],O_TRUNC | O_WRONLY);
		}
		else
		{
			printf("Program Terminated\n");
			exit(3);
		}
	}
	//If "-p" exists copy the permissions
	if(i == 2)
	{
		fstat(fs,&file_status);
		fchmod(fd,file_status.st_mode);
	}
	//Copy the normal content of file
	copy(fs,fd);
	//4.Close all the opened files
	close(fs);
	close(fd);
}

//Copy functions for the file
void copy(int fs,int fd)
{
	char buffer[80]={'\0'};
	ssize_t count;
	while((count=read(fs,buffer,80))>0)
	{
		write(fd,buffer,count);
	}
}
