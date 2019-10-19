/*

*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	//initialize the variabeles
	FILE *fp, *fd;
	int ch;
	char buffer[80];

	//open the file in read mod
	fp = fopen("sample.txt", "r");


	//handle the error
	if(!fp)
	{
		perror("sample.txt");
		exit(1);
	}
	//open the file in read mod
	fd = fopen("dst.txt", "w");


	//handle the error
	if(!fd)
	{
		perror("dst.txt");
		exit(1);
	}


	//Read char by char

	while(fgets(buffer, 80, fp) != NULL)
	{
		fputs(buffer, fd);
	}

	//close the file
	fclose(fp);
	fclose(fd);
}
