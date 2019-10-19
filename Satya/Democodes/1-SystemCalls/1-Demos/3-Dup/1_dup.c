#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int pid, status;
	int newfd;	/* new file descriptor */

	if (argc != 2) {
		fprintf(stderr, "usage: %s output_file\n", argv[0]);
		exit(1);
	}
	if ((newfd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0) {
		perror(argv[1]);	/* open failed */
		exit(1);
	}
	printf("This goes to the standard output.\n");
	printf("Now the standard output will go to \"%s\".\n", argv[1]);

	/* this new file will become the standard output */
	/* standard output is file descriptor 1, so we use dup to */
	/* to copy the new file descriptor onto file descriptor 1 */
	/* close() will close the current standard output */
	
	close(1);
	dup(newfd); 

	printf("This goes to the standard output too.\n");
	printf("This too goes into the dup.txt.\n");
	exit(0);
}
