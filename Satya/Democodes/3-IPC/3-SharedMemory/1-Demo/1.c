/*
1. Demo of shared Memory
2. Steps in creating the shared memory
	1. Create the shared memory segment
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 16


int main()
{
	int shmid;
	char *ptr;

	/* The same key has to be used in other processes also */
	key_t key = 'A';

	/* 1. Create the shared memory segment */
	if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1)
	{
		perror("shmget()");
		exit(0);
	}

	printf("shmid: %d\n", shmid);

	/* 2. Attach this process to the shm created */
	if ((ptr = shmat(shmid, (void *)0, 0)) == (void *)-1)
	{
		perror("shmat");
		exit(1);
	}

	/* 3. Reading / writing to the shared memory segment */
	printf("Enter the data\n");
	scanf("%s", ptr);

	/* 4. Detaching from and deleting segments */
	if (shmdt(ptr) == -1)
	{
		perror("shmdt");
		exit(2);
	}
}
