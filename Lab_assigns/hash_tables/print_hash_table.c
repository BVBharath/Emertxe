#include "main.h"


void print_hash(hash_table hash_array[], int size)
{
	int i;
	hash_table *temp;
	for(i = 0; i < size; i++)
	{
		printf("%d->", hash_array[i].value);
		temp = hash_array[i].link;

		while(temp)
		{
			printf("%d->", temp->value);
			temp = temp->link;
		}
		putchar('\n');
	}
	putchar('\n');
}
