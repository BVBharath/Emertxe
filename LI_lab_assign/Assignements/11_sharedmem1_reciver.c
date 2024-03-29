#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ctype.h>
#define SHM_SIZE 100

int main()
{
	int shmid;
	char *ptr,*p,*q,*r;
	char temp;
	key_t key = 'B';
	int fd;
	char buff[20];
	int count;


	if((shmid = shmget(key,SHM_SIZE,0644)) == -1)
	{
		perror("shmget");
		exit(0);
	}
	
	printf("shmid:%d\n",shmid);
	if((ptr = shmat(shmid,(void *)0,0)) == (void *)-1)
	{
		perror("shmat");
		exit(1);
	}
	
	p = ptr;
	q = p;
	r =p;
	while(*p)
	{
		*p = toupper(*p);	
		p++;
	}
	p--;
	while(q < p)
	{
		temp = *q;
		*q = *p;
		*p = temp;
		q++;
		p--;
	}
	
	printf("%s\n",r);
	if((fd = open("myfifo",O_WRONLY)) == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	
	printf("%d\n",fd);
	strcpy(buff,r);

		if(write(fd,buff,sizeof(buff)) < 0)
		{
			perror("write");
		}

	
	if(shmdt(ptr) == -1)
	{
		perror("shmdt");
		exit(2);
	}

	shmctl(shmid,IPC_RMID,NULL);
}
