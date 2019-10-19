#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define SHM_SIZE 1024

int main()
{
	int shmid;
	char *ptr;
	char *n;
	char *p;
	char *new;
	int count = 0,k = 5;
	key_t key = 'B';

	if((shmid = shmget(key,SHM_SIZE,0644 | IPC_CREAT)) == -1)
	{
		perror("shmget()");
		exit(0);
	}
	
	printf("shmid:%d\n",shmid);
	if((ptr = shmat(shmid,(void *)0,0)) == (void *)-1)
	{
		perror("shmat");
		exit(1);
	}
	
	pid_t pid;
	pid = fork();
	switch(pid)
	{
		case -1:
			printf("Not happening\n");
			break;
		case 0:
			*ptr = '1';
			p = ptr;
			ptr++;
			new = ptr;
			ptr++;
			while(k--)
			{
				printf("Enter child:");
				scanf("\n%[^\n]s",ptr);
				count = count + strlen(ptr);
				ptr = ptr + strlen(ptr);
				*ptr = '\n';
				count++;
				ptr++;
			}
			*new = count;
			ptr = p;
			break;
		default:
			waitpid(pid,0,0);
			*ptr = '2';
			p = ptr;
			ptr++;
			ptr = ptr + *ptr;
			ptr++;
			while(k--)
			{
				printf("Enter parent:");
				scanf("\n%[^\n]s",ptr);
				ptr = ptr + strlen(ptr);
				*ptr = '\n';
				ptr++;
			}
			ptr = p;
			*ptr = '3';
			break;
	}
	if(shmdt(ptr) == -1)
	{
		perror("shmdt");
		exit(2);
	}
}
