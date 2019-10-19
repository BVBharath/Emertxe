#include <stdio.h>
#include <string.h>

void strstr1(char *str1,char *str2);
int main()
{
	//initialize the variables
	char str1[30], str2[10];

	printf("enter the string1\n");
	scanf("%[^:\n]s", str1);
		
	printf("enter the string2\n");
	scanf("\n%[^:\n]s", str2);

	strstr1(str1,str2);
}

void strstr1(char *str1,char *str2)
{
	char *p, *q;
	p= str1, q = str2;

	while(*p)
	{
		if(*p == *q)
		{
			if(strncmp(p, q, strlen(q)) == 0)
			{
				printf("needle found \n");
				return;
			}
		}
		p++;
	}

	printf("needle not found\n");
}
