#include "common.h"

int main(int argc,char **argv)
{
	int fs;
	char ch;
	//Open the file
	fs = open(argv[1],O_WRONLY,0644);
	if(fs == -1)
	{
		perror(argv[1]);
		exit(1);
	}
	//Dupe the file using dup1
	close(1);
	dup(fs);
	printf("Hello World!\n");
}
