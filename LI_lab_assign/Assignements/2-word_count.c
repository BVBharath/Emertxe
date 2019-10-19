#include "common.h"

int i,flag_w,flag_c,flag_l;
int character,word,line,new_character,new_word,new_line,count;
//Function for Word Count
void word_count(int fs,char *s);
int main(int argc, char *argv[])
{
	int fs,opt=0;
	char buff;
	int character=0,word=0,line=0,new_character=0,new_word=0,new_line=0,count=0;
	//Using getopt function to set the flags for the operations after "-"
	while((opt = getopt(argc,argv, "wlc")) != -1)
	{
		switch(opt)
		{
			case 'w' : flag_w = 1;
					   break;
			case 'l' : flag_l = 1;
					   break;
			case 'c' : flag_c = 1;
		}
	}

	//Check whether no files are passed
	if(argv[optind] == NULL)
	{
		word_count(0,"STDIN");
	}
	
	//if one or more than 1 files are passed
	for(i = optind ; i < argc;i++)
	{
		fs = open(argv[i],O_RDONLY);
		if(fs == -1)
		{
			perror(argv[i]);
			exit(1);
		}
		//Calling wordcount function
		word_count(fs,argv[i]);
	}
}


void word_count(int fs,char *s)
{
	char buff;
		word=0,character=0,line=0;
	//reading number of words and characters and lines
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
	//check the flags and print the values
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
	printf("%s\n", s);
	count++;
	//Check if there are more than one file to print the total
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


