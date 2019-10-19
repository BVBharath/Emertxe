#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <stdlib.h>
#define SHM_SIZE 100

int main()
{
	int shmid;
	char *ptr;
	char buff[25];
	key_t key = 'B';
	int count,fd;

	if((shmid = shmget(key,SHM_SIZE,0644 | IPC_CREAT)) == -1)
	{
		perror("shmget");
		exit(0);
	}

	printf("shmid : %d\n", shmid);

	if((ptr = shmat(shmid,(void *)0,0)) == (void *)-1)
	{
		perror("shmat");
		exit(1);
	}

	if(mknod("myfifo",S_IFIFO | 0644,0) < 0)
	{
		perror("mknod");
	}
	pid_t pid;
	pid = fork();
	switch(pid)
	{
		case -1:
			printf("Not happening\n");
			break;
		case 0:
			printf("Enter a string:");
			scanf("%[^\n]s",ptr);
			printf("CHild Terminated\n");
			break;
		default:
			sleep(5);
			if((fd = open("myfifo",O_RDWR)) <0)
			{
				perror("open");
				exit(EXIT_FAILURE);
			}
			printf("%d\n",fd);
			if((count = read(fd,buff,25)) >0)
			{
				//printf("Count: %d\n",count);
				printf("%s",buff);
			}
			putchar('\n');
			printf("Parent terminated\n");
	}

	if(shmdt(ptr) == -1)
	{
		perror("shmdt");
		exit(2);
	}
}
