#include "main.h"

int insert_last(dlist **head, data_t data, dlist **tail)
{
	dlist *new = malloc(sizeof(dlist));

	if(new == NULL)
	{
		return FAILURE;
	}

	new->data = data;
	new->prev = *tail;
	new->next = NULL;
	if(*head == NULL)
	{
		*head = new;
		*tail = new;
		return SUCCESS;
	}
	(*tail)->next = new;
	*tail = new;
	return SUCCESS;
	


}
