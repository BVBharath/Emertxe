#include "common.h"
void copy(int fs,int fd);
int main(int argc , char *argv[])
{
	int fs,fd,i;
	char ch;
	struct stat file_status;
	if(argc == 4 && strcmp(argv[1],"-p") == 0)
	{
		i = 2;
	}
	else
	{
		i = 1;
	}

	fs = open(argv[i],O_RDONLY);
	if(fs == -1)
	{
		perror(argv[i]);
		exit(1);
	}
	fd = open(argv[i+1], O_EXCL | O_CREAT | O_WRONLY,0644);
	if(fd == -1 && errno == EEXIST)
	{
		printf("Do you want to continue copying the data? ");
		scanf("%c",&ch);
		if(ch == 'Y' || ch == 'y')
		{
				fd = open(argv[i+1],O_TRUNC | O_WRONLY);
		}
		else
		{
			printf("Program Terminated\n");
			exit(3);
		}
	}
	if(i == 2)
	{
		fstat(fs,&file_status);
		fchmod(fd,file_status.st_mode);
	}
	copy(fs,fd);
	//4.Close all the opened files
	close(fs);
	close(fd);
}
void copy(int fs,int fd)
{
	char buffer[80]={'\0'};
	ssize_t count;
	while((count=read(fs,buffer,80))>0)
	{
		write(fd,buffer,count);
	}
}
