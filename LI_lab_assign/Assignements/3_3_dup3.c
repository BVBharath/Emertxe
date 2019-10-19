#include "common.h"

int main(int argc,char **argv)
{
	int fs;
	char ch;
	fs = open(argv[1],O_CREAT|O_WRONLY,0644);
	if(fs == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	//Dup the file using dup3
	dup3(fs,1,O_CLOEXEC);
	printf("Hello World!Dup2\n");
}
