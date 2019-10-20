#include "main.h"

int delete_first(dlist **head, dlist **tail)
{
	if(*head == NULL)
	{
		return	LIST_EMPTY;
	}

	dlist *temp = *head;
	*head = temp -> next;
	temp->prev = NULL;
	free(temp);

	if(*head == NULL)
	{
		*tail == NULL;
	}
	return SUCCESS;
}
