#include "common.h"


int main(int argc, char *argv[])
{
	int in, p[2], count = 0;
	char buff[80];
	int count_pipes,i = 0, j = 0, k = 0;
	char **buffer ;

	while(argv[i] )
	{
		if(strcmp(argv[i++], "|") == 0)
		{
			count++;
		}


	}

	printf("count : %d\n", count);

	for(k = 0; k <= count; k++)
	{

		printf("j entry : %d\n", j);
		if(pipe(p) == -1)
		{
			perror("pipe");
			exit(1);
		}


		while((argv[j]) && (strcmp(argv[j],"|") != 0))
		{
			j++;
		}

		printf("j : %d\n", j);
		if(j)
		{
			argv[j] = NULL;
		}

		printf("argv[j] : %s\n", argv[j++]);

		//creation of child process
		pid_t pid = fork();
		if(pid == 0)
		{

			if(k == 0)
			{
				dup2(p[1], 1);
				if((execvp(argv[1], argv + 1)) == -1)
				{
					printf("invalid command1\n");
				}
			}
			else if(k == count)
			{

				printf("command line: %s\n", argv[i]);
				dup2(in, 0);
				if((execvp(argv[i], argv + i  )) == -1)
				{
					printf("invalid command3\n");
				}


			}
			else
			{	
				
				printf("command line: %s\n", argv[i]);
				dup2(in, 0);
				dup2(p[1], 1);
			
				if((execvp(argv[i], argv + i   )) == -1)
				{
					printf("invalid command3\n");
				}
			}

		}
		else
		{
			sleep(1);
			i = j;

			in = p[0];

			while(read = )
		}
	}
}
