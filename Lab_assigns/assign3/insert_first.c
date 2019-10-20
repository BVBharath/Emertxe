#include "main.h"

int insert_first(dlist **head, data_t data, dlist **tail)
{
	dlist *new = malloc(sizeof(dlist));

	if(new == NULL)
	{
		return FAILURE;
	}

	new->data = data;
	new->prev = NULL;
	new->next = *head;
	if(*head == NULL)
	{
		*head = new;
		*tail = new;
		return SUCCESS;
	}
	(*head)->prev = new;
	*head = new;
	return SUCCESS;
	


}
