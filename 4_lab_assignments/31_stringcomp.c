/*
Title: Stringopertions
Author: Bharath
Organizatio: Emertxe
Description:perform the following operation
1.compare the two strings with case sensitivity and print the result
2.compare the two strings with case insensitivity and print the comparision result
3.print the string1 (haystack) form the given string2(needle).If needle is not there in string1 and print given needle not found
*first find the length of string2
*check function is used to check first charatcer of both strings	*Take the  string1 addres where it found first character equal an	d also take string2 address  and length of string2 into comparisio		n function
	*In comparision function compare the length of substring from str	ing1 and string2. If it found not equal return invalid to main els	e continue in comparing entire charater
	*In the comparision function compare entire substring from string1 and string2. If it found equal return valid and print entire characters from that string1. Else return invalid and check for other characters in string1

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define VALID 1
#define INVALID 0

//prototypes
int stringcmp(char *s1, char *s2);
int grtlst(const char *P, const char *q);
int  casestringcmp(char *s1, char *s2);
void check(char *s1, char *s2, int n);
int compare(char *P, char *q, int n);

//driver
int main()
{
	//initialize the variables
	char a1[20], a2[20], status;
	int choice, n;

	do
	{

		//prompt the user to enter the first string
		printf("enter the first string\n");
		scanf("\n%[^:\n]s", a1);
		getchar();

		//prompt the user to enter the second string
		printf("enter the second string\n");
		scanf("%[^:\n]s", a2);
		getchar();
	
		printf("choose one of the operation\n1.string compare\n2.string case compare\n3.str_tok\n");
		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1: 			
					//calling function
					if(stringcmp(a1, a2))
					{
						printf("string1 and string2 are equal\n");
					}
					else
					{
						printf("string1 and string2 are not equal\n");
					}

					if(grtlst(a1, a2))
					{
						printf("string1 is greater than string2\n");
					}
					else
					{
					
						printf("string2 is greater than string1\n");
					}
					break;


			case 2:
					//calling function
					if(casestringcmp(a1, a2))
					{
						printf("string1 and string2 are equal\n");
					}
					else
					{
						printf("string1 and string2 are not equal\n");
					}
					break;

			case 3:
					n = strlen(a2);

					//calling function
					check(a1, a2, n);
					break;

			default:
				printf("invalid\n");
		}
		printf("do u want continue...press(Yy)\n");
		scanf("\n%c", &status);
	}while("status == 'Y' || status == 'y'");
}
//functions
int casestringcmp(char *s1, char *s2)
{
	int flag = 1;
	while(*s1)
	{
		if(tolower(*s1++) != (tolower(*s2++ )))
		{
		
			flag = 0;
			return INVALID;
		}
		
	}
	if(flag)
	{
		return VALID;
	}
}
//
int stringcmp(char *s1, char *s2)
{ 
	int flag = 1;
	
	if(strlen(s1) != strlen(s2))
	{
		return INVALID;
	}
	while(*s1)
	{
		if(*s1++ != *s2++)
		{
			flag = 0;
			return INVALID;
		}
		
	}
	if(flag)
	{
		return VALID;
	}
}

//


int grtlst(const char *p, const char *q)
{
	int count1=0, count2=0;

	while(*p || *q )
	{
		if(*p)
		{
			count1 = count1 + *p++;
		}

		if(*q)
		{
			count2 = count2 + *q++;
		}
	}

	if(count1 > count2)
	{
		return VALID;
	}

	return INVALID;

	
	
}
//functions
void check(char *s1, char *s2, int n)
{
	char *s3;
	char *s4;
	char *temp;
	int flag = 0;
	while(*s1)
	{
		if(*s1 == *s2)
		{
			s4 = s1;
			s3 = s1;
			temp = s2;
		if(compare(s3, temp, n))
		{
			flag = 1;
			while(*s4)
			{
				printf("%c", *s4++);
			}
			printf("\n");
			break;

		}
		else
		{
			s1++;

		}
		}
		else
		{
			s1++;
		}
	}
	if(flag == 0)
	{
		printf("given needle not found\n");
	}
}

//
int compare(char *p, char *q, int n)
{
	int flag = 0;
	char *temp = p;

	int count = 0;
	while(*temp != ' ' && *temp != '\0')
	{
		count++;
		temp++;
	
	}
	if(count != n)
	{
		return INVALID;
	}
	while(*p != '\0' && *p != ' ' )
	{
	
		if(*p != *q)
		{
			flag = 1;
			break;
		}
		else
		{
			p++;
			q++;
		}
	}
//	printf("%d\n", flag);
	if(flag == 0) 
	{
		return VALID;
	}
	return INVALID;

}
