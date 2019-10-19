/*
title:4_ap_hp_gp
author:BHARATH
organization:EMERTXE
description: To find the Arithmatic Progression and Geometric Progression and Harmonic Progression
*/

#include <stdio.h>

int main()
{
	// initialize the variables
	int a, n;
	float R, result;
	char status;

do
{
 
	 //prompt the user to read the inputs
	 printf("enter the initial value:");
	 //read the initial value
	 scanf("%d", &a);

	 printf("enter the ratio:");
	 //read the ratio
	 scanf("%f", &R);

	 printf("enter the limit:");
	 //read the limit
	 scanf("%d", &n);

	 if ( a <= 0 || a > 1024 || R <= 0 || R > 1024 || n <= 0 || n > 1024 )
	 {
	 	 printf("invalid inputs:\n");
	 }
	
	 else
	 {

		 //logic

		 //arithmatic progression
		 printf("the AP series:");
		 for(int i=0; i<n; i++)
		 {
			 int result=a + (i * R);
			 printf(" %d", result);
		 }
		  printf("\n");

		 //harmonic progression
		 printf("the HP series:");
		 for(int i=0; i<n; i++)
		 {
			result= 1/(a + (i * R));
			 printf(" %f", result);
		 }
		  printf("\n");

	    //geometric progression
		 printf("the GP series:");
		 printf("%d", a);
		 for (int i=1; i<n; i++)
		 {
		 	 a=a * R;
			 printf(" %d", a);
		 }
		 printf("\n");
	 }
	  printf("do you want continue.....press(Yy):");
	 scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');
}
