/*
Title:consecutive.c
Author:Bharath
Organization:Emrtxe
Decsription:Create a 8 byte consecutive memory location:
1.add element
2.remove element
3.display the element
4.exit from programme

*/

#include <stdio.h>
#include <stdlib.h>


//driver
int main()
{
	int ch[8] = {0}, i, choice[8] = {0}, j = 0, k = 0, l = 0;
	void *p = malloc(8 * sizeof(char));

	if (p == NULL)
	{
		printf ("No memory\n");
		return -1;
	}
	void *q = p;
	void *s = p;
	void *t;
	void *m = s;

	do
	{
		printf ("Menu:\n1-Add element\n2-Remove element\n3-Display element\n4-Exit from program\nEnter ur choice: ");
		scanf ("%d", &ch[k]);

		switch (ch[k])
		{
			case 1: 
				printf ("1-int\n2-char\n3-float\n4-double\nEnter the type you want to enter: ");
				scanf ("%d", &choice[j]);

				switch (choice[j])
				{
					case 1:
						scanf ("%d", (int *)p);
						p = (char *)p + 4;
						break;
					case 2:
						scanf ("\n%c", (char *)p);
						p = (char *)p + 1;
						break;
					case 3:
						scanf ("%f", (float *)p);
						p = (char *)p + 4;
						break;
					default:
						scanf ("%lf", (double *)p);
						p = (char *)p + 8;
				}
				j++;
				break;
			case 2:
				*(double *)q = 0;
				break;
			case 3:
				if (ch[k-1] == 2)
				{
					printf ("After remove: %x\n", *(int *)q);
				}
				else
				{
					s = m;
					for (i = 0; i < 8; i++)
					{
						if ((char *)s < (char *)m + 8)
						{
							switch (choice[i])
							{
								case 1:
									printf ("int : %d\n", *(int *)s);
									s = (char *)s + 4;
									break;
								case 2:
									printf ("char: %c\n", *(char *)s);
									s = (char *)s + 1;
									break;
								case 3:
									printf ("float: %.2f\n", *(float *)s);
									s = (char *)s + 4;
									break;
								case 4:
									printf ("double: %lf\n", *(double *)s);
									s = (char *)s + 8;
									
							}
						}
					}
				}
				break;
			default:
				exit(1);
		}
		k++;
	}while ( (char *)p <= (char *)q + 8);
	printf ("Sorry memory exceeds 8 byte\n");
}

