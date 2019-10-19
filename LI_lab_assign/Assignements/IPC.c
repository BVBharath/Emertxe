#include "common.h"

int main(int argc,char **argv)
{
	int p[2];
	int status,i=0;
	if(pipe(p) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid_t pid1,pid2;
	pid1 = fork();
	switch(pid1)
	{
		case -1:
			printf("Not happening\n");
			break;
		case 0:
			while(strcmp(argv[i],"|") != 0)
			{	
				i++;
			}
			argv[i] = NULL;
			i=1;
			close(p[0]);
			dup2(p[1],1);
			execvp(argv[i],argv+1);
			break;
			
		default:
		//wait(0);
			waitpid(pid1,&status,0);
			pid2 = fork();
			switch(pid2)
			{
				case -1:
					printf("Not happening\n");
					break;
				case 0:
					while(strcmp(argv[i],"|") != 0)
					{	
						i++;
					}
					close(p[1]);
					dup2(p[0],0);
					execvp(argv[i+1],argv+i+1);
					break;
					
					
				default:
					sleep(1);

			}
	}
}
