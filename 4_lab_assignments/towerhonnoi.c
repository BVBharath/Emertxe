/*
Title:Towerofhonnoi.c
Author: Bharath
Organization: Emertxe
Description: Move all the disks from source to destination with help of auxillary pillar

*/

#include <stdio.h>


int toh(int n, char s, char d, char temp);
int main()
{
	//initialize the variables
	int n;
	char status;

	do
	{
		//prompt + read
		printf("enter the number of disks\n");
		scanf("%d", &n);
	
		//calling function
		toh(n,'A','C','B' );
		printf("do u want to continue...press(Yy)\n");
		scanf("\n%c", &status);
	}while(status == 'y' || status == 'Y');
}

//
int toh(int n, char s, char d, char temp)
{
	if(n == 1)
	{
	
		printf("move disk %d from %c to %c\n", n, s, d);
		return 0;
	}
	//function to move disks from source tp auxillary
	toh(n-1, s,temp, d );
	printf("move disk %d from %c to %c\n", n, s, d);

	//function to move disks from auxillary to destination
	toh(n-1, temp, d, s);

}
