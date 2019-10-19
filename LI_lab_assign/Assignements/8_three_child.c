#include "common.h"

int main()
{
	//Variables to create 3 forks
	pid_t pid,pid1,pid2;
	//Creates a process
	pid = fork();

	switch(pid)
	{
		case 0 :
		//Child1 is in sleep
			sleep(5);
			break;
		case -1:
			printf("Nope\n");
			break;
		default:
			//Creates another process
			printf("PID1: %d\n", pid);
			pid1 = fork();
			switch(pid1)
			{
				case 0:
					//Child2 is in sleep
					sleep(6);
					break;
				case -1:
					printf("Nope again\n");
					break;
				default:
				//Creates another process
					printf("PID2: %d\n", pid1);
					pid2 = fork();
					switch(pid2)
					{
						case 0:
							//Child3 is in sleep
							sleep(7);
							break;
						case -1:
							printf("Nope again\n");
							break;
						default:
							printf("PID3: %d\n", pid2);
							//Waitpid system call suspends execution of calling proccess untill the given pid is terminated
							waitpid(pid,0,0);
							//Returns true if terminated normally (WIFEXITED(status))
							if(WIFEXITED(0))
							{
								//returns the exit status of child (WEXITSTATUS(status))
								printf("Child %d terminated with %d\n",pid,WEXITSTATUS(0));
							}
							waitpid(pid1,0,0);
							if(WIFEXITED(0))
							{
								printf("Child %d terminated with %d\n",pid1,WEXITSTATUS(0));
							}
							waitpid(pid2,0,0);
							if(WIFEXITED(0))
							{
								printf("Child %d terminated with %d\n",pid2,WEXITSTATUS(0));
							}
							printf("Done\n");
					}

			}
	}
}
