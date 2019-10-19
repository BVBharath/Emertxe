/*
Title: c_type_lib
Author: Bharath
Organization: Emertxe
Description: performing the below operations through bitwise and functions
1.check character is alphabet or not
2.check character is alphabet or number
3.check character is ascii or not
4.check character is blank or not

*/


#include <stdio.h>
#define VALID 1
#define INVALID 0

//prototypes
int is_alpha(char);
int is_alnum(char);
int is_ascii(char);
int is_blank(char);

//driver
int main()
{
	//initialize the variables
	char ch, status;
	int option;

	do
	{

		//promopt the user to enter the character
		printf("enter the character\n");
		scanf("%c", &ch);
		getchar();

		printf("select any option\n1.isalpha\n2.isalnum\n3.isascii\n4.isblank\n");
		scanf("%d", &option);
		switch (option)
		{
			case 1:
					//calling is_alpha function
					if(is_alpha(ch) )
					{
						printf("character is alphabet\n");
				
					}
					else
					{
						printf("character is not alphabet\n");
					}
					break;

			case 2:
					//calling function
					if(is_alnum(ch))
					{
						printf("character is alphanum\n");
				
					}
					else
					{
						printf("character is not alphanum\n");
					}
					break;


			case 3:
				
					//calling is_ascii function
					if(is_ascii(ch) )
					{
						printf("character is ascii\n");
				
					}
					else
					{
						printf("character is not ascii\n");
					}
					break;


			case 4:
					//calling is_blank function
					if(is_blank(ch))
					{
						printf("character is blank\n");
				
					}
					else
					{
						printf("character is not blank\n");
					}
					break;



			default:
					printf("invalid\n");
		}


	printf("do u want to continue..press(Yy)");
	scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
	getchar();
}

//functions

//is_alphabet function
int  is_alpha(char ch)
{
	if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
	{
		return VALID;
	}
	return INVALID;
}

//is_alphanum function
int is_alnum(char ch)
{
	
	if( is_alpha(ch)|| ch >= '0' && ch <= '9')
	{
		return VALID;
	}
	return INVALID;
}

//is_ascii function
int is_ascii(char ch)
{
	if(ch >= 0 && ch <= 127)
	{
		return VALID;
	}
	return INVALID;
}

//is_blank function
int is_blank(char ch)
{
	if(ch == ' ' || ch =='	')
	{
		return VALID;
	}
	return INVALID;
}


