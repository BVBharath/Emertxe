#include "main.h"


int reverse_iteration(slist **head)
{
	slist *prev = NULL;
	slist *next = NULL;
	slist *current = *head;

	if(*head == NULL)
	{
		return FAILURE;
	}

	while(current != NULL)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return SUCCESS;
}
