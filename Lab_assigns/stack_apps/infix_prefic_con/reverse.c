#include "main.h"

void reverse(char *str)
{
	int n = strlen(str);

	char *temp = str + n - 1;
	
	while(str < temp)
	{
		char temp1 = *str;
		*str = *temp;
		*temp = temp1;
		str++;
		temp--;
	}
}
