#include "main.h"

int delete_last(slist **head)
{
	slist *temp = *head, *temp1;
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}
	if((*head)->link == NULL)
	{
		free(*head);
		*head = NULL;
		return SUCCESS;
	}

	while(temp->link)
	{
		temp1 = temp;
		temp = temp->link;

	}

	free(temp);
	temp1->link = NULL;
	return SUCCESS;
}
