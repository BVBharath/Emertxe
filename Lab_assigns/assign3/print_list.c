#include "main.h"

void print_list(dlist *head)
{
	if(head == NULL)
	{
		printf("list is empty\n");
	}

	else
	{
		while(head)
		{
			printf("%d->", head->data);
			head = head->next;
		}
		putchar('\n');
	}
}
