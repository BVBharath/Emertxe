#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#define SHM_SIZE 1024

int main()
{
	int shmid;
	char *ptr;
	
	key_t key = 'A';

	if((shmid = shmget(key,SHM_SIZE,0644 | IPC_CREAT)) == -1)//creating shared memory
	{
		perror("shmget");
		exit(0);
	}

	printf("shmid : %d\n", shmid);

	if((ptr = shmat(shmid,(void *)0,0)) == (void *)-1)//attaching pointer to shared memory
	{
		perror("shmat");
		exit(1);
	}
	
	printf("Enter a string:");
	scanf("%[^\n]s",ptr);//writing to shared memory

	if(shmdt(ptr) == -1)
	{
		perror("shmdt");
		exit(2);
	}
}

