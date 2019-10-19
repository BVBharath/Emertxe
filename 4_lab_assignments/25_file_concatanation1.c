/*

*/

#include <stdio.h>
#include <stdlib.h>
int main(char argc, char *argv[])
{
	//initialize the variabeles
	FILE *fs1, *fs2, *fd;
	int ch;

	//open the file in read mod
	fs1 = fopen(argv[1], "r");


	//handle the error
	if(!fs1)
	{
		perror("argv[1]");
		exit(1);
	}
	//open the file in read mod
	fd = fopen(argv[3], "w");


	//handle the error
	if(!fd)
	{
		perror(argv[3]);
		exit(1);
	}


	//Read char by char

	while((ch = fgetc(fs1)) != EOF)
	{
		fputc(ch, fd);

	}

	//close the file
	fclose(fs1);
	fclose(fd);

	//

	//open the file in read mod
	fs2 = fopen(argv[2], "r");


	//handle the error
	if(!fs2)
	{
		perror(argv[2]);
		exit(1);
	}
	//open the file in read mod
	fd = fopen(argv[3], "a");


	//handle the error
	if(!fd)
	{
		perror(argv[3]);
		exit(1);
	}


	//Read char by char

	while((ch = fgetc(fs2)) != EOF)
	{
		fputc(ch, fd);

	}
	fclose(fs1);
	fclose(fd);

}
