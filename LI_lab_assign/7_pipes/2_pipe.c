/*

 */

#include "common.h"


//driver
int main(int argc, char *argv[])
{
	//initializing the variables
	int p[2];
	int p1[2];
	int i, j;
	char buffer[100];

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

			//creating the pipe
			if(pipe(p1) == -1)
			{
				perror("pipe");
				exit(1);
			}

			close(p[1]);
			dup2(p[0], 0);
			//creating the second child
			pid_t pid1 = fork();

			switch(pid1)
			{
				case 0:

					//logic
					i  = 0;

					close(p1[0]);
					dup2(p1[1], 1);
					while((strcmp(argv[i], "|")) != 0)
					{
						i++;
					}
					j = i + 1;
					while((strcmp(argv[j], "|")) != 0)
					{
						j++;
					}

					argv[j] = NULL;


					if(execvp(argv[i + 1], argv + i + 1 ) == -1)
					{
						printf("invalid command2\n");
					}
					break;

				case -1:
					break;

				default : 
					sleep(2);

					
					close(p1[1]);
					dup2(p1[0], 0);

					//creation of third child
					pid_t pid2 = fork();

					switch(pid2)
					{
						case 0:

							//logic
							i  = 0;

							while((strcmp(argv[i], "|")) != 0)
							{
								i++;
							}
							i++;

							while((strcmp(argv[i], "|")) != 0)
							{
								i++;
							}
							i++;

							if(execvp(argv[i], argv + i) == -1)
							{
								printf("invalid command3\n");
							}
							else
							{
								printf("Hello\n");
							}
							break;

						case -1:
							break;

						default : 
							sleep(2);


					}

			}
	}

}
