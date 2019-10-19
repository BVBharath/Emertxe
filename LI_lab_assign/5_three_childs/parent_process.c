/*
Title: parent_proce.c
Name : Bharath
Organization: Emertxe
Decsription : creation of three child process with same parent process

 */


#include "common.h"
#include "sys/wait.h"

//driver
int main()
{
	//initialization of variables
	pid_t pid, pid1, pid2;
	int wstatus;

	//creation of first child
	pid = fork();


	switch(pid)
	{
		case 0:
			sleep(5);
			break;

		case -1:
			break;

		default:
			printf("child1 created with pid : %d\n", pid);

			printf("parent  pid : %d\n\n", getpid());

			//creation of second child
			pid1 = fork();

			switch(pid1)
			{
				case 0:
					sleep(3);
					break;

				case -1:
					break;

				default:
					printf("child2 created with pid : %d\n", pid1);
					printf("parent  pid : %d\n\n", getpid());
				
					//creation of third child
					pid2 = fork();


					switch(pid2)
					{
						case 0:
							sleep(2);
							break;

						case -1:
							break;

						default:
							printf("child3 created with pid : %d\n", pid2);
							printf("parent  pid : %d\n\n", getpid());

							//child1 termination status
							waitpid(pid, &wstatus, 0);
							if(WIFEXITED(wstatus))
							{
								printf("child 1 is terminated with exit code %d\n", WEXITSTATUS(wstatus));
							}

							//child2 termination status
							waitpid(pid1, &wstatus, 0);
							if(WIFEXITED(wstatus))
							{
								printf("child 2 is terminated with exit code %d\n", WEXITSTATUS(wstatus));
							}

							//child3 termination status
							waitpid(pid2, &wstatus, 0);
							if(WIFEXITED(wstatus))
							{
								printf("child 3 is terminated with exit code %d\n", WEXITSTATUS(wstatus));
							}


					}

			}
	}
}
d
