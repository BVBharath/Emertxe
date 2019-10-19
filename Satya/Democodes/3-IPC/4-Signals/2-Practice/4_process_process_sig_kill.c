/*
1.
*/

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	kill(atoi(argv[1]), SIGINT);
}
