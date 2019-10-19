/*
Title:Combination.c
Author:Bharath
Organization:Emertxe
Decsription:To find the possible combination of given string.

*/

#include<stdio.h>
#include<string.h>

//prototype
void swap(char *, int, char *, char *);

int main()
{
	//initialize the variables
	char s[10];

	//prompt + read string from user
	printf("enter the character\n");
	scanf("%s", s);

	//creating temporary array
	char s1[20];
	
	//copy the original string to temporary
	strcpy(s1,s);

	//logic
	char s2[20];
	char *st=s1;
	char *str=s1;
	char *cp=s2;
	int i=0,count = 0;

	//finding the length of string
	while(s[i++])
	{	
		count++;
	}
	//calling the function
	printf("The possible combination are: \n");
	swap(str,count,st,cp);
}


//function
void swap(char *str,int count,char *st,char *cp)
{
	int i;
	char temp;
	char k[20];
	if(count>1)
	{
	for(i = 0;i < count;i++)
	{
		strcpy(k,st);
		temp = *(str+i);
		*(str+i) = *str;
		*str = temp;
		//printf("%d=%s\n",count,st);
		swap(str+1,count-1,st,cp);
		if(count == 2)
		{
		printf("%s\n",st);
		}
		strcpy(st,k);
		//printf("%d=%s\n",count,st);
	}
}
}
