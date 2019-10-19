/*

*/
#include "common.h"
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 16

int main()
{

	//initialize the variables
	int shmid;
	char *ptr;
	char *str;


	/*same key has to be used in other process also */
	key_t key = 'A';

	/*1.create the shared memory segment*/
	if((shmid = shmget(key, SHM_SIZE, 0644 )) == -1)
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
	printf("message: %s\n", ptr);

	//reversing the string
	str = malloc(strlen(ptr)+1);
	strcpy(str, ptr);
	int i, j;

	i = 0;
	j = strlen(str) - 1;

	while(i < j)
	{
		char temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i++;
		j--;
	}
	
	
	//printing the string
	printf("message: %s\n", str);

	

	//detaching from and deleting the segment
	if(shmdt(ptr)== -1)
	{
		perror("shmdt");
		exit(2);
	}

	//after reading data , remove the shared the memory
	shmctl(shmid, IPC_RMID, NULL);
}
