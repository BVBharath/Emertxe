#include "common.h"

int main(int argc, char *argv[])
{
	//initialize the variables
	int i,fs,flag_w=0,flag_c=0,flag_l=0,opt=0;
	char buff;
	int character=0,word=0,line=0,new_character=0,new_word=0,new_line=0,count=0;

	//checking for commands
	while((opt = getopt(argc,argv, "wlc")) != -1)
	{
		switch(opt)
		{
			//incrementing the word count flag
			case 'w' : flag_w = 1;
					   break;

			//increment the line count flag
			case 'l' : flag_l = 1;
					   break;

			//increment the character flag
			case 'c' : flag_c = 1;
		}
	}
	
	//pointing to first file
	if(argv[optind] == NULL)
	{
		printf("NULL\n");
		return 0;
	}

	//pointing for files
	for(i = optind ; i < argc;i++)
	{
		//opening files one by one
		fs = open(argv[i],O_RDONLY);
		if(fs == -1)
		{
			perror(argv[i]);
			exit(1);
		}
		character = 0,line = 0,word =0;

		//reading from files
		while(read(fs,&buff,1) > 0)
		{

			character++;
			new_character++;
			if(buff == '\n')
			{
				line++;
				new_line++;
			}
			if(buff == ' ' || buff == '\t' || buff == ',')
			{
				word++;
				new_word++;
			}
		}
		if(flag_l == 0 && flag_w == 0 && flag_c == 0)
		{
			printf("%d %d %d ", line, word+1, character);
		}
		else
		{
			if(flag_l)
			{	
				printf("%d ", line);
			}
			if(flag_w)
			{
				printf("%d ", word+1);
			}
			if(flag_c)
			{
				printf("%d ", character);
			}
		}
		printf("%s\n", argv[i]);
		count++;
		if(count > 1)
		{
			if(flag_l == 0 && flag_w == 0 && flag_c == 0)
			{
				printf("%d %d %d ", new_line, new_word+2, new_character);
			}
			else
			{
				if(flag_l)
				{	
					printf("%d ", new_line);
				}
				if(flag_w)
				{
					printf("%d ", new_word+2);
				}
				if(flag_c)
				{
					printf("%d ", new_character);
				}
			}
			printf("Total\n");
		}
			
	}

}
