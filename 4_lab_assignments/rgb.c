#include <stdio.h>

//prototypes

void sort(char *str, int n)
{
	printf("i came this far1\n");
	//initialize the variables
	int i = 0, j;


	j = i + 1;
	 while(j < n)
	{
		if(str[j] == 'R')
		{
			char temp = str[j];
			str[j] = str[i];
			str[i] = temp;
			i++;
		}
		j++;
	}
	printf("i came this far2\n");

	j = i + 1;

	while(j < n)
	{
		if(str[j] == 'G')
		{
			char temp = str[j];
			str[j] = str[i];
			str[i] = temp;
			i++;
		}
		j++;
	}

	printf("i came this far3\n");
	
	while(i < n)
	{
		str[i++] = 'B';
	}



}

//driver
int main()
{
	//initialize the variables
	int n;

	printf("enter the length of the array\n");
	scanf("%d", &n);
	printf("length : %d\n", n);

	char str[n];

	printf("enter the sequence:\n");
	for(int i = 0; i < n; i++)
	{
		scanf("\n%c", &str[i]);
	}

	sort(str, n);

	for(int i = 0; i < n; i++)
	{
		printf("%c", str[i]);
	}
	putchar('\n');
	return 0;
}
