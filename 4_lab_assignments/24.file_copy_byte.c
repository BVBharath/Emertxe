/*
Title:File_copy.c
Author: Bharath
Organization: Emertxe
Description: To copy the contents from source file to destination file

*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	//initialize the variabeles
	FILE *fp, *fd;
	int ch;

	//open the file in read mod
	fp = fopen(argv[1], "r");


	//handle the error
	if(!fp)
	{
		perror("argv[1]");
		exit(1);
	}
	//open the file in read mod
	fd = fopen(argv[2], "w");


	//handle the error
	if(!fd)
	{
		perror(argv[2]);
		exit(1);
	}


	//Read char by char

	while((ch = fgetc(fp)) != EOF)
	{
		fputc(ch, fd);

	}

	//close the file
	fclose(fp);
	fclose(fd);
}
