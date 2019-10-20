#include "main.h"

Status insert_at_last(slist **head, data_t data)
{
	slist *new = malloc(sizeof(slist));

	if(new == NULL)
	{
		return failure;
	}

	new -> data = data;
	new -> link = NULL;

	if(*head == NULL)
	{
		*head = new;
		return success;
	}
	slist *temp = *head;
	while(temp -> link)
	{
		temp = temp -> link;
	}
	temp -> link = new;
	return success;
}

