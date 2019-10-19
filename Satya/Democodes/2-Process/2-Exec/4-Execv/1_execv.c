/*
1. In execl(), the parameters passed are hard coded.
2. In execv(), we can passed the arguments at the run time.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
	char *temp[] = {"ls", "-l", (char *)0};

	execv("/bin/ls", temp);	
}
