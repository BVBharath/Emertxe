/*
Title: recursive_main.c
Author: Bharath
Organization: Emertxe
Description: The below programme is used to find the factorial of given number by calling main function recursively

*/


#include <stdio.h>

//driver
int main()
{
	//initialize the variables
	static int num, flag = 1;
	static int fact = 1;

	//prompt the user to enter the number
	if(flag)
	{
		printf("enter the number\n");
		scanf("%d", &num);
		flag = 0;
	}

	//logic
	if(num > 1)
	{
	
		fact = fact * num;
		num --;

		//termination condition
		if(num == 1)
		{
			return 0;
		}

		//calling the main function recusivelly
		main();
	}

	if(num == 0 || num == 1 )
	{
		//printing the factorial number
		printf("The factorial of given  is : %d\n", fact);
		num = num - 2;
		
	}
	
}
