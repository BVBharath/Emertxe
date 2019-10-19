/*
Title:Wordcount.c
Author:Bharath
Organization: Emertxe
Description: To display the number of lines, characters and words
*/

#include <stdio.h>

//driver
int main()
{
	//initialize the variables
	int chars = 0, words = 0, line = 0;
	char last = 0, ch, status;

	//logic

	printf("enter the input\n");
	ch = getchar();

	//if first character is space or tab
	if (ch == ' ' || ch == '	')
	{
		words--;
	}

	//to run loop until u press ctrl+d
	while(ch != EOF)
	{
		chars++;
		if (ch == ' ' || ch == '\n' || ch == '	')
		{
			if(last != ' ' && last != '	' && last != '\n')
			{
				words++;
			}
		}
		if(ch == '\n')
		{
			line++;
		}
		last = ch;
		ch = getchar();
	}
	

	
	//printing
	printf("number of characters: %d\n", chars);
	printf("the number of words: %d\n", words);
	printf("the number of lines: %d\n", line);
}
