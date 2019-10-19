/*
Title: getword,itoa, atoi
Author: Bharath
Organization: Emertxe
DEscriptions: To perform the three operations
1.get first substring form one statement and  display the length of substring
2. convert the ascii numbers into integer numbers
3.convert the intger number into asciivalues
*/

#include <stdio.h>
#include <stdlib.h>

//prototypes
void getword(char *s1);
int myatoi(const char *s1);
void itoa(char *s1, int data);

//driver
int main()
{
	//initialize the variables
	char a1[30], status;
	int options, indata;
			
	do
	{
		//prompt the user to select one of the option
		printf("select one options\n1.getword\n2.atoi\n3.itoa\n");
		scanf("%d", &options);
		switch(options)
		{
			case 1:
					printf("enter the string\n");
					scanf("\n%[^:\n]s", a1);
					getchar();

					//calling getword function
					getword(a1);
					break;

			case 2:

					printf("enter the string\n");
					scanf("\n%[^:\n]s", a1);
					getchar();
					
					//calling function
					indata = myatoi(a1);
					printf("%d\n", indata);
					break;

			case 3:
					printf("enter the data\n");
					scanf("%d", &indata);

					//calling function
					itoa(a1, indata);
					printf("%s\n", a1);
					break;
			
			default:
					printf("invalid\n");
		}
		printf("do u want continue...press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
}


//functions
int myatoi(const char *s)
{
	int temp = 0;
	int sign = 1;
	

	if(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')
	{
	//	printf("%c\n", *s);
		return 0;

	}
	if(*s == '-')
	{
		sign = -1;
		s++;
	}
	
	while(*s)
	{
		temp = temp * 10 + (*s++ - '0');
		
		if(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')
		{
			break;
		}

	}
	return sign * temp;
	
}

//functions
void getword(char *s1)
{
	int count = 0;
	while(*s1 != ' ')
	{
	
		count++;
		printf("%c", *s1++);
	}
	printf("\n");
	printf("the length of first substring : %d\n", count);
}


//functions
void itoa(char *s1, int indata)
{
	char *s2 = s1;
	char temp;
	if(indata > 0)
	{
		while(indata)
		{
			*s1++ = (indata % 10) + '0';
			indata = indata / 10;
		}
		*s1--='\0';
		while(s2 < s1)
		{
			temp = *s2;
			*s2++ = *s1;
			*s1-- = temp;
		}
	}
	else
	{
		while(indata)
		{
			indata = abs(indata);
			*s1 = (indata % 10) + '0';
			s1++;
			indata = indata / 10;
		}
		*s1++ = '-';
		*s1 = '\0';
		s1--;

		while(s2 < s1)
		{
			temp = *s2;
			*s2++ = *s1;
			*s1-- = temp;
		}
	}
}


