#include "common.h"

void proc_status(pid_t pid,int fs,int fd);
int count = 0,i = 0,status;
int main()
{
	pid_t pid;
	int fs,count,i=0,fd = 1;
	char buffer[20];
	char status;
	//Creating a child process
	pid = fork();
	switch(pid)
	{
		case 0:
			printf("A child created with pid %d\n", getpid());
			sleep(10);
			break;
		case -1:
			 perror("fork");
			 break;
		default:
			 
			sleep(5);
			//printing the child process sleep status
			sprintf(buffer,"/proc/%d/status", pid);
			fs = open(buffer,O_RDONLY);
			if(fs == -1)
			{
				perror(buffer);
				return 0;
			}
			proc_status(pid,fs,fd);
			close(fs);
			sleep(15);//sleeping until the child dies//

			//printf("%s",buffer);
			//printing the child process zombie status
			fs = open(buffer,O_RDONLY);
			if(fs == -1)
			{
				perror(buffer);
				return 0;
			}
			proc_status(pid,fs,fd);
			close(fs);
	}
}


//Function to print the first 3 lines of the proc status
void proc_status(pid_t pid,int fs,int fd)
{
	while((count = read(fs,&status,1)) > 0)
	{
		write(fd,&status,count);
		if(status == '\n')
		{
			i++;
		}
		if(i == 3)
		{
			i = 0;
			break;
		}
	}
}
