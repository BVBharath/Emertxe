#include "common.h"


int main(int argc, char *argv[])
{
	
	
	int count_pipes, count_line = 0,  i = 0, j = 0;

	while(argv[i])
	{
		if(strcmp(argv[i++], "|") == 0)
		{
			count_pipes++;
		}
	}

	char buff[count_pipes - 1][3][10];

	printf("number of pipes; %d\n", count_pipes);

	i= 0;
	int l = 0, n = 1;
	while(argv[i])
	{
		count_line++;
		if(strcmp(argv[i++], "|") == 0 && (count_pipes--))
		{
			int  k;
			for(k = 0; k < count_line; k++)
			{
				strcpy(buff[j][k], argv[n]);
				n++;
			}
			j++;
			n++;
			
		}
		if(argv[i] == NULL)
		{
			int  k;
			for(k = 0; k < count_line; k++)
			{
				strcpy(buff[j][k], argv[n]);
			}
			
			 
	
		}
	}


	for(int g = 0; g < 3; g++)
	{
		for(int r = 0; g < 2; g++)
		{
			printf("%s\n", buff[g][r]);
		}
	}


	



}
