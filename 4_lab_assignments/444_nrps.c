/*
	Title: NRPS
	Author:Bharath
	Organization:Emertxe
	Description:

				•Suppose k = 3 (say taking 3 distinct characters ).
					◦ Let 3 distinct characters be a , b, c.
				 Suppose ‘n’ is the string length to be formed using ‘k’ distinct words.
					◦ Let n be 6
				 The string should be formed in such a way that there should not be any consecutive repetitions of the strings.
*/
#include <stdio.h>
#include <string.h>

int factorial(int n);
void comb(char *s,int,int );
int check(char *str,int string_length,int character_length);
void swap(char *a, char *b);

int main()
{
	int string_length,character_length;
	char s[26];
	printf("Enter the number of characters:");
	scanf("%d", &character_length);
	printf("Enter the length of string:");
	scanf("%d", &string_length);
	getchar();
	printf("Enter a combination:");
	scanf("%[^\n]s", s);
	if(character_length != strlen(s))
	{
		printf("Wrong number of characters.\n");
		return 1;
	}
	for(int i = 0; i < strlen(s); i++)
	{
		for(int j = i + 1; j < strlen(s); j++)
		{
			if(*(s + i) == *(s + j))
			{
				printf("Cannot have same letters in the combination\n");
				return 1;
			}

		}
	}
	comb(s,string_length,character_length);
	return 0;
}

int factorial(int n)
{
	int fact = 1;
	int i;
	for(i = 1 ; i <= n ;i++)
	{
		fact = fact * i ;
	}
	return fact;
}


void comb(char *s,int string_length,int character_length)
{
	int len = strlen(s);
	int n = factorial(len)/len;
	int temp1 = n;
	char ch[20];
	int length = len;
	int k = 1;
	char *temp = s;
	strcpy(ch,temp);
	int i,j;
	int count = 0;
	while(length--)
	{
		i = 1;
		temp = s;
		temp1 = n;
		while(temp1--)
		{

		if(check(temp,string_length, character_length) == 1)
		{
			while(*temp)
			{
				count++;
				if(count == string_length)
				{
					putchar('\n');
					return;
				}
				printf("%c",*temp);
				temp++;
			}
		}
		temp = s;
			if(temp1 == 0)
			{
				i = 0;
				j = 0;
				while(1)
				{
					if(ch[k] != *(temp + i))
					{
						i++;
					}
					else
					{
						swap(temp + i, temp + j);
						k++;
						break;
					}
				}
				break;
			}
			j = 1;
			if(*(temp +len - i-1) != *(temp ))
			{
				swap(temp + len - i - 1,temp + len - j);
				i++;
			}
			else
			{
				i = 1;
				swap(temp + len - i - 1 , temp + len - j);
				i++;
			}
		}
	}
}

int check(char *str,int n,int k)
{
	char c[50]={0};
	char d[50]={0};
	int count,j,i,m,l;
	for(j=0;j<k-1;j++)
	{
		for(i=0;i<n;i++)
		{
			c[i]=str[j+i];
		}
		count = 0;
		for(m=0;m<k-1;m++)
		{
			for(l=0;l<n;l++)
			{
				d[l]=str[m+l];
			}
			if(strcmp(c,d)==0)
			{
				count++;
			}
			if(count == 2)
			{
				return 0;
			}
		}
	}
return 1;
}


void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
