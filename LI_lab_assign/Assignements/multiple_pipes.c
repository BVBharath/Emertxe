#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int in;
	
	int n = 0;
	int k = 0;
	pid_t pid;
	for(int i = 1; argv[i] != NULL; i++)
	{
		if(*argv[i] == '|')
		{
			n++;
		}
	}
	printf("Count: %d\n",n);
	
	static int j=1;
	for(int i = 1 ;i <= count ; i++)
	{
		if(pipe(p) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		switch(pid = fork())
		{
			case -1:
				printf("Not happening\n");
				break;
			case 0:

			default:
				while(strcmp(argv[k],"|") != 0 && i == j)
				{
					k++;
				}

				int m = k;
				if(i > 1)
				{
					while(strcmp(argv[m],"|") != 0 && i == j+1)
					{
						m++;
					}
					
				}
				argv[m] = NULL;
				
				

		}
	}
}
