#include "main.h"

int delete_list(dlist **head, dlist **tail)
{
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}
	while((*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
	*head = NULL;
	*tail = NULL;
	return SUCCESS;
}
