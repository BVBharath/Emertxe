#include "main.h"


int sort(slist *head)
{
	int swapped, i;
	slist *first;
	slist *last = NULL;
	
	if(head == NULL)
	{
		return LIST_EMPTY;
	}
	do
	{
		swapped = 0;
		first = head;

	while(first->link != last )
	{
		if(first->data > first->link->data)
		{
			swap(first, first->link);
			swapped = 1;
		}

		first = first->link;
	}
	last = first;
	}while(swapped);
	return SUCCESS;
}
