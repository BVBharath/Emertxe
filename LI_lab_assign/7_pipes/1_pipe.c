/*

*/

#include "common.h"


//driver
int main(int argc, char *argv[])
{
	//initializing the variables
	int p[2];
	int i;

	//creating the pipe
	if(pipe(p) == -1)
	{
		perror("pipe");
		exit(1);
	}

	//creating the first child
	pid_t pid = fork();

	//
	switch(pid)
	{
		case 0:
			//closing reading portal of pipe
			close(p[0]);

			//bypasssing of stdout to pipe writing path
			dup2(p[1], 1);
			
			//logic
			i = 0;
			while((strcmp(argv[i], "|")) != 0)
			{
				i++;
			}
			argv[i] = NULL;

			if(execvp(argv[1], argv + 1) == -1)
			{
				printf("invalid command1\n");
			}
			break;

		case -1:
			break;

		default : 
			sleep(2);

			//creating the second child
			pid_t pid1 = fork();

			switch(pid1)
			{
				case 0:
					
					//logic
					i  = 0;
					close(p[1]);
					dup2(p[0], 0);
					while((strcmp(argv[i], "|")) != 0)
					{
						i++;
					}

					if(execvp(argv[i + 1], argv + i + 1 ) == -1)
					{
						printf("invalid command2\n");
					}
					break;

				case -1:
					break;

				default : 
					sleep(2);

			}
	}

}
