#include "main.h"

void print_list(slist *head)
{
	if(head == NULL)
	{
		printf("List empty\n");
	}
	else
	{
		while(head)
		{
			printf("%d->",head -> data);
			head = head -> link;
		}
		putchar('\n');
	}
	putchar('\n');
}

