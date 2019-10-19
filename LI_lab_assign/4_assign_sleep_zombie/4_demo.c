/*
Title:sleep_zombie_process.c
Name:Bharath
Organization:Emertxe
Description : Making of child process with sleep and then zombie process
*/



#include "common.h"
#include <sys/types.h>
#include <unistd.h>

//prototypes
void process_state(int fs, char *buff);


//driver
int main()
{
	
	//initialize the variables
	char buff[20];
	int fs;
	pid_t pid;
	ssize_t count;

	//creating child process
	pid = fork();


	//logic
	switch(pid)
	{
		//child process
		case 0: 
			sleep(5);
			break;

		case -1:
			perror("fork()");
			break;
		//parent process
		default:
			sleep(2);		

			sprintf(buff, "/proc/%d/status", pid);


			//calling function
			process_state(fs, buff);
			
			sleep(6);

			//calling function
			process_state(fs, buff);


	}
}


//functions

void process_state(int fs, char *buff)
{

	//initialize the variables
	int i = 0;
	char state;

	//opening the process + handle the error
	fs = open(buff, O_RDONLY);

	if(fs == -1)
	{
		perror(buff);
		exit(1);
	}

	//for 3 lines
	while( i < 3)
	{
		while(1)
		{
			//reading character by caharacter
			read(fs, &state, 1);
			if(state == '\n')
			{
				break;
			}
			printf("%c", state);


		}
		printf("\n");
		i++;
	}
	putchar('\n');


}
