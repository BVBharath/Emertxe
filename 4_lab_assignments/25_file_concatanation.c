/*
Title: File_concatanation.c
Author: Bharath
Organization: Emertxe
Description: Copy the contents from two source files into one destination file

*/

#include <stdio.h>
#include <stdlib.h>

//driver
int main(char argc, char *argv[])
{
	//initialize the variabeles
	FILE *fs1, *fs2, *fd;
	int ch;
	char buffer[80];
	//open the  source file in read mod
	fs1 = fopen(argv[1], "r");


	//handle the error
	if(!fs1)
	{
		perror(argv[1]);
		exit(1);
	}
	//open the dst file in write mod
	fd = fopen(argv[3], "w");


	//handle the error
	if(!fd)
	{
		perror(argv[3]);
		exit(1);
	}


	//Read block by block

	while(fgets(buffer, 80, fs1) != NULL)
	{
		fputs(buffer, fd);
	}


	//close the file
	fclose(fs1);
	fclose(fd);

	//

	//open the sourcefile2 in read mod
	fs2 = fopen(argv[2], "r");


	//handle the error
	if(!fs2)
	{
		perror(argv[2]);
		exit(1);
	}
	//open the dst file in append mod
	fd = fopen(argv[3], "a");


	//handle the error
	if(!fd)
	{
		perror(argv[3]);
		exit(1);
	}


	//Read block by block

	while(fgets(buffer, 80, fs2) != NULL)
	{
		fputs(buffer, fd);
	}

	//close the files
	fclose(fs1);
	fclose(fd);

}
