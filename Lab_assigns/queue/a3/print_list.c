#include "main.h"

void print_list(slist *front)
{
	if(front == NULL)
	{
		printf("list is empty\n");
	}

	else
	{
		slist *temp = front;
		while(temp->link != front)
		{
			printf("%d->", temp->data);
			temp = temp->link;
		}

		printf("%d ", temp->data);
		putchar('\n');
	}
}
