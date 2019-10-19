/*
Title:bitwise_library
Author:Bharath
Organization:Emertxe
Description:Performing below operations in bitwise
1.get nbits
2.replace nbits
3.get nbits from position
4.replace nbits from position
5.toggle nbits
6.print bits

*/

#include <stdio.h>
//prototypes
unsigned get_nbits(unsigned, int);
unsigned replace_nbits(unsigned,  unsigned,int);
unsigned get_nbits_pos(unsigned, int, int);
unsigned replace_nbits_pos(unsigned, int, unsigned, int); 
unsigned toggle_nbits(unsigned, int, int);
void print_nobits(unsigned, int);

//driver
int main()
{

	//initialize the variables
	unsigned int num,val,mask ;
	int options,n,pos;
	char status;

	do
	{
		//select the particular operation
		printf("select any one operations\n1.get_nbits\n2.replace_nbits\n3.get_nbits_position\n4.replace_nbits_pos\n5.toggle_nbits\n6.print_nobits\n");
		scanf("%d", &options);


		switch(options)
		{
			case 1 :
					printf("enter the number\n");
					scanf("%d", &num);

					printf("enter the number of bits to taken from lsb\n");
					scanf("%d", &n);

					//calling the function
					printf("%d\n", get_nbits(num, n));
					break;

			case 2 :
					printf("enter the number\n");
					scanf("%d", &num);

					printf("enter the value\n");
					scanf("%d", &val);

					printf("enter the number of bits to extract and replace\n");
					scanf("%d", &n);
                
				  
					//calling the function
					printf("%d\n", replace_nbits(num, val, n));
					break;

			case 3:
					printf("enter the number\n");
					scanf("%d", &num);

					printf("enter the position\n");
					scanf("%d", &pos);

					printf("enter the number of bits\n");
					scanf("%d", &n);

					//calling the function
					printf("%d\n", get_nbits_pos(num, pos, n));
					break;

			case 4:
					printf("enter the number\n");
					scanf("%d", &num);

					printf("enter the number of bits\n");
					scanf("%d", &n);

					printf("enter the value\n");
					scanf("%d", &val);

					printf("enter the position\ny");
					scanf("%d", &pos);

					//calling the function and storing
					num = replace_nbits_pos(num, n, val, pos);
					printf("%d\n", num);
					
					break;

			case 5:

					printf("enter the number\n");
					scanf("%d", &num);

					printf("enter the number of terms\n");
					scanf("%d", &n);

					printf("enter the position\n");
					scanf("%d", &pos);

					//calling the function
					printf(	"%d\n",toggle_nbits(num, n, pos));
					break;

			case 6 :
					printf("enter the number\n");
					scanf("%d", &num);

					printf("enter te number of bits to prints\n");
					scanf("%d", &n);
					printf("Binary(+%d):", num);

					//calling the function
					print_nobits(num, n);
					int num2=-num;
					printf("Binary(%d):", num2);
					print_nobits(num2, n);
					break;


			default :
					printf("invalid\n");
		}

		printf("do u want continue: press[Yy]\n");
		scanf("\n%c", &status);
	}while(status == 'Y' || status == 'y');


}		

//functions
//get_nbits function
unsigned get_nbits(unsigned num, int n)
{
			num &= ~(~0 << n);
			return num;
	
}

//replce bits function
unsigned replace_nbits (unsigned num, unsigned val, int n)

{

    num  &= (~0 << n);
	val &= (~(~0 << n));

	num = num | val;
	return num;
				
}

//togggle bits function
unsigned toggle_nbits(unsigned num, int n, int pos)
{
	num= num ^ (~(~0 << n)) << pos;
	return num;
}

//print_nobits function
void print_nobits(unsigned num, int n)
{

	unsigned mask= 1 << n-1;
	for(; mask; mask >>= 1)
	{

		num & mask? putchar('1'):putchar('0');
						
	}
	printf("\n");
	

}

//get nbits from position function
unsigned get_nbits_pos(unsigned num, int pos, int n)
{
	int temp = pos - n + 1;
	num = (num &  ((~(~0 << n)) << temp)) >> temp;
	return num;
}

//replace nbits from position
unsigned replace_nbits_pos(unsigned num, int n, unsigned val, int pos)
{
	val = ( val & ~(~0 << n )) << (pos - n + 1);
	num = num & ~(~(~0 << n)) << pos;
	num = num | val;
	return num;
}
