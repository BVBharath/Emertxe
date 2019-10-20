#include "main.h"

int delete_list(slist **head)
{
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}

	while(*head)
	{
		slist *temp = *head;
		*head = (*head)->link;
		free(temp);
	}
	return SUCCESS;
}
