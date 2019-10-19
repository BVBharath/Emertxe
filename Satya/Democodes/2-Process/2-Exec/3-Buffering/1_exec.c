/*
1.	The buffers which is so far conatained data from the previous process
	are also emptied and filled with the new process data.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("This line will not be displayed\n");
	//execl("2_exec", "2_exec", (char *)0);
	execl("/bin/ls", "ls", (char *)0);
}

/*
Note:

1. use '\n' or fflush to clear the buffer contents
*/
