/*

*/

#include <stdio.h>

#include <stdlib.h>
int main()
{
	//initialoze the variables
	char status;


	do
	{

		static int num;
		static short int flag = 1;
		static long int fact = 1;
		if(flag)
		{
			printf("enter the number\n");
			scanf("%d", &num);
			flag = 0;
		}

		if(num < 0)
		{
			printf("invalid range...enter positive numbers\n");
		}

		if(num == 1)
		{
			printf("the factorial of given number is %ld\n", fact);
			num = num - 2;
		}
		else
		{
			while(num > 0)
			{
				fact = fact * num;
				--num;
				if(num == 0)
				{
					return 0;
				}
				main();
			}
			if(num == 0)
			{
				printf("the factorial of given number: %ld\n", fact);
			}
		}
		--num;
		_Exit;
	printf("do u want to continue..press(Yy)\n");
	scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
}
