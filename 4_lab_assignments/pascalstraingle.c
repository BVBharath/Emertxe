#include <stdio.h>

int main()
{
	//
	int rows, i, j, spaces, c;

	printf("enter the rows\n");
	scanf("%d", &rows);

	for(i=0; i < rows; i++)
	{
		for(spaces = 1; spaces < rows - i; spaces++)
		{
			printf(" ");
		}

		for(j = 0; j <= i; j++)
		{
			if(j == 0)
			{
				c = 1;
			}
			else
			{
				c = c*(i-j+1)/j;
			}
			printf(" %d", c);
		}
		putchar('\n');
	}

}
