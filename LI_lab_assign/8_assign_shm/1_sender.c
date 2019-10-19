/*

*/

#include "common.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>
#define SHM_SIZE 16

int main()
{
	//initialize the variables
	int shmid, i = 0;
	char *ptr;

	/*same key has to be used in other process also */
	key_t key = 'A';

	/*1.create the shared memory segment*/
	if((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1)
	{
		perror("shmget()");
		exit(0);
	}

	//attch the process to the shm created
	if((ptr = shmat(shmid, (void *)0, 0)) == (void *) -1)
	{
		perror("shmat");
		exit(0);
	}
	
	///reading or writing to shared memory segment
	printf("enter the data\n");
	scanf("%s", ptr);
	
	
	//converting into upper
	while(ptr[i])
	{
		ptr[i] = (ptr[i] - 'a') + 'A';
		i++;
	}


	//detaching from and deleting the segment
	if(shmdt(ptr)== -1)
	{
		perror("shmdt");
		exit(2);
	}
}
