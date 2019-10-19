/*
Title: Read_int
Author: Bharath
Organization: Emertxe
Descriptions: The below programme is used to read the intger number from the user without use of scanf function.

*/

#include <stdio.h>

//prototypes
int read( );

//driver
int main()
{
	//initialize the variables
	int a;	
	char status;

	do	
	{
	
		printf("enter the number:");

		//calling function
		 a  = read();

		printf("U entered :%d\n", a);
		printf("do u want continuee...press(Yy)\n");
		scanf("%c", &status);
		getchar();
	}while(status == 'Y' || status == 'y');

	 
	
}

//functions
int read( )
{
	char ch;
	int temp = 0;
	int	sign = 1;
	while((ch = getchar()) != '\n')
	{
		if(ch == '-')
		{
			sign = -1;
		}
		else
		{
		temp = temp * 10 + (ch - '0');
		}
		 
		
	}
	return sign * temp;

}
