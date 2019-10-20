#include "main.h"

int insert_after(slist **head, data_t data, data_t new_data)
{
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}

	slist *temp  = *head;

	while(temp)
	{
		if(data == temp->data)
		{
			slist *new = malloc(sizeof(slist));
			if(new == NULL)
			{
				return FAILURE;
			}
			new->data = new_data;
			new->link = temp->link;
			temp->link = new;
			return SUCCESS;
		}
		temp = temp->link;
	}
	return DATA_NOT_FOUND;
}
