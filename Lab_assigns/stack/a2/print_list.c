#include "main.h"

void peep(slist *head)
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
			head = head->link;
		}
		putchar('\n');
	}
}
