#include "main.h"


int reverse_recursive(slist **head, slist **prev, slist **next, slist **current)
{
	if(*head == NULL)
	{
		return FAILURE;
	}

	if(*current == NULL)
	{
		*head = *prev;
		return SUCCESS;
	}

	*next = (*current)->link;
	(*current)->link = *prev;
	*prev = *current;
	*current = *next;

	 reverse_recursive(head, prev, next, current);


}
