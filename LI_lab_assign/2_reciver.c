#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define SHM_SIZE 1024

int main()
{
	int shmid;
	char *ptr;
	char *p;
	char *q;
	int word;
	key_t key = 'B';

	if((shmid = shmget(key,SHM_SIZE,0644)) == -1)
	{
		perror("shmget()");
		exit(0);
	}

	printf("shmid: %d\n", shmid);


	if((ptr = shmat(shmid,(void*)0,0)) == (void*)-1)
	{
		perror("shmat");
		exit(1);
	}

	p = ptr;
	if(*ptr == '3')
	{
		ptr = ptr + 2;
		int i = 1;
		q = ptr;

		while(*ptr)
		{	
			q = ptr;
			word = 0;
			while(*q != '\n')
			{
				if( i % 2 == 0)
				{
					if(*q == ' ' || *q == '\t' || *q == ',')
					{
						word++;
					}
				}
				q++;
			}

			if(i%2 == 0)
			{
				printf("Line %d : %d\n",i,word+1);
			}
			i++;
			ptr = q+1;
		}
		/*	putchar(*ptr);
			ptr++;*/
		//}
}
ptr = p;
if(shmdt(ptr) == -1)
{
	perror("shmdt");
	exit(2);
}

shmctl(shmid,IPC_RMID,NULL);
}
