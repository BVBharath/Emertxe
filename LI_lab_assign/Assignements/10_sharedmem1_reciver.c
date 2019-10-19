#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <ctype.h>
#define SHM_SIZE 1024

int main()
{
	int shmid;
	char *ptr,*p,*q;
	char temp;
	key_t key = 'A';

	if((shmid = shmget(key,SHM_SIZE,0644)) == -1)
	{
		perror("shmget");
		exit(0);
	}

	if((ptr = shmat(shmid,(void *)0,0)) == (void *)-1)
	{
		perror("shmat");
		exit(1);
	}
	
	p = ptr;
	q = p;
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
	
	printf("%s\n", ptr);

	if(shmdt(ptr) == -1)
	{
		perror("shmdt");
		exit(2);
	}

	shmctl(shmid,IPC_RMID,NULL);
}
