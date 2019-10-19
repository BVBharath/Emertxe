/*
Title: Generic_search
Author: Bharath
Organization: Emertxe
Description:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VALID 1
#define INVALID 0

//prototypes
int compare(const void *p, const void *q);

int comparef(const void *p, const void *q);

int compared(const void *p, const void *q);

int comparec(const void *p, const void *q);

int cmpstringp(const void *p, const void *p2);
//void stringsort(char **a5, int n);

void search(char **a5, int n);

int strcomp(char *s1, char *s2);

//driver
int main(int argc, char *argv[])
{

	system("clear");
	//initialize the variables
	int n = atoi(argv[1]);
	int options;
	
	int a1[n], i, key;

	float a2[n], key1;

	double a3[n], key2;

	char a4[n], key3;

	char **a5, ch[10];

	//providing a options to user to selct datatype
	printf("\nselect one of the datatype\n1.int\n2.float\n3.double\n4.char\n5.strings\n");
	scanf("%d", &options);

	//switching to one of the options

	switch(options)
	{
		case 1:
							
				printf("enter the %d numbers\n", n);
				for( i = 0; i < n; i++)
				{
					scanf("%d", &a1[i]);
				}
				printf("enter the key to search\n");
				scanf("%d", &key);
				//qsort function
				int (*comp)(const void*, const void*) = compare;
				qsort(a1, sizeof(a1) / sizeof(a1[0]), sizeof(a1[0]), *comp);
				printf("the elments after sorting\n");
				for(i = 0; i < n; i++)
				{
					printf("%d ", a1[i]);
				}
				printf("\n");

				//binary search
				if(bsearch(&key,a1, sizeof(a1) / sizeof(a1[0]), sizeof(a1[0]), *comp) != 0)
				{
					printf("key is found\n");
				}
				else
				{
					printf("key not found\n");
				}
				break;

		case 2:
				//prompt the user to enter the numbers
				printf("enter the float array\n");
				for(i = 0; i < n; i++)
				{
					scanf("%f", &a2[i]);
				}

				printf("enter the key to search\n");
				scanf("%f", &key1);

				//int (*compf) (const void*, const void*) = comparef;

				qsort(a2, sizeof(a2) / sizeof(a2[0]), sizeof(a2[0]), 
				comparef);

				

				//

				printf("elemenys after sorting\n");
				for(i = 0; i < n; i++)
				{
					printf("%f\n", a2[i]);
				}


				if(bsearch(&key1,a2, sizeof(a2) / sizeof(a2[0]), sizeof(a2[0]), comparef) == NULL)
				{
					printf("key is not found\n");
				}
				else
				{
					printf("key  found\n");
				}
				break;

		case 3:
				//prompt the user to enter the numbers
				printf("enter the double array\n");
				for(i = 0; i < n; i++)
				{
					scanf("%lf", &a3[i]);
				}

				printf("enter the key to search\n");
				scanf("%lf", &key2);

				int (*compd) (const void*, const void*) = compared;

				qsort(a3, sizeof(a3) / sizeof(a3[0]), sizeof(a3[0]), 
				*compd);

				//

				printf("elemenys after sorting\n");
				for(i = 0; i < n; i++)
				{
					printf("%le\n", a3[i]);
				}

				if(bsearch(&key2,a3, sizeof(a3) / sizeof(a3[0]), sizeof(a3[0]), compared) == NULL)
				{
					printf("key is not found\n");
				}
				else
				{
					printf("key  found\n");
				}
				break;

	case 4:
			printf("enter the charatcers\n");
			for(i = 0; i < n; i++)
			{
				scanf("\n%c", &a4[i]);
			}

			qsort(a4, sizeof(a4) / sizeof(a4[0]), sizeof(a4[0]), comparec);
			printf("enter the key\n");
			scanf("\n%c", &key3);
			printf(" charatcers after sorting \n");
			for(i = 0; i < n; i++)
			{
				printf("%c ", a4[i]);
			}

			putchar('\n');

			if(bsearch(&key3,a4, sizeof(a4) / sizeof(a4[0]), sizeof(a4[0]), comparec) == NULL)
			{
				printf("key is not found\n");
			}
			else
			{
				printf("key  found\n");
			}
			break;

	case 5:
			printf("enter the strings\n");
			a5 = malloc(n * sizeof(char *));
			for(i = 0; i < n; i++)
			{
				a5[i] = malloc(10);
				printf("enter the string%d:", i+1);
				scanf("%s", ch);
				strcpy(a5[i], ch);
			}
		

		//	stringsort(a5, n);
			qsort(a5, n, sizeof(char *), cmpstringp);
			printf("\nafter sorting\n");
			for(i = 0; i < n; i++)
			{
				printf("string%d : %s\n",i+1, a5[i]);
			}
			search(a5, n);

		}

}

//functions
int compare(const void *p, const void *q)
{
	//initialize the variables
	int a, b;
	a = *(int  *) p;
	b = *(int *) q;
	if(a > b)
	{
		return 1;
	}
	else if(a < b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
//
int comparef(const void *p, const void *q)
{
	
	return ((*(float *)p > *(float *)q) - (*(float *)p < *(float *)q));
}

//
int compared(const void *p, const void *q)
{
	
	return ((*(double *)p > *(double *)q) - (*(double *)p < *(double *)q));
}



//
int comparec(const void *p, const void *q)
{
	
	return ((*(char *)p > *(char *)q) - (*(char *)p < *(char *)q));
}


//
/*
void stringsort(char **a5, int n)
{
	int i, j;
	char temp[10];

	for(i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - 1 - i; j++)
		{
			if(strcmp(a5[j], a5[j + 1]) > 0)
			{
				strcpy(temp,a5[j]);
				strcpy(a5[j], a5[j + 1]);
				strcpy(a5[j + 1], temp);


			}
		}
	}
		
}*/

//
int cmpstringp(const void *p, const void *p2)
{
	return strcmp(*(char * const *)p, *(char * const *)p2);
}

//
void search(char **a5, int n)
{
	int i, flag = 1;;
	char key[10];


	printf("enter the key to search\n");
	scanf("%s", key);

	for(i = 0; i < n; i++)
	{
		if(strcomp(key, a5[i]) == VALID)
		{
			printf("string found\n");
			flag = 0;
			break;
		}
	}
	if(flag)
	{
		printf("string not found\n");
	}

}

//
int strcomp(char *s1, char *s2)
{
	int flag = 1;
	if(strlen(s1) != strlen(s2))
	{
		return INVALID;
	}

	while(*s2)
	{
		if(*s1 != *s2)
		{
			
			return INVALID;
		}

		s1++;
		s2++;
	}
	return VALID;
}
