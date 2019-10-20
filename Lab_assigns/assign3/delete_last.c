#include "main.h"

int delete_last(dlist **head, dlist **tail)
{
	if(*head == NULL )
	{
		return LIST_EMPTY;
	}

	dlist *temp = *tail;
	*tail = temp->prev;
	temp->next = NULL;
	if((*tail) != NULL )
	{
		(*tail)->next = NULL;
	}
	free(temp);
	
	if(*tail == NULL)
	{
		*head = NULL;
	}
	return SUCCESS;
}
