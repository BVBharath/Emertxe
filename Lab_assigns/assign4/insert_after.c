#include "main.h"

int insert_after(dlist **head, dlist **tail, data_t data,  data_t new_data)
{
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}

	dlist *temp = *head;

	while(temp)
	{
		if(temp->data == data)
		{
			dlist *new = malloc(sizeof(dlist));
			if(new == NULL)
			{
				return FAILURE;
			}

			new->data = new_data;
			new->prev = temp;
			new->next = temp->next;
			temp->next = new;
			if(new->next)
			{
				new->next->prev = new;
				return SUCCESS;
			}

			*tail = new;
			return SUCCESS;
		}
		temp = temp->next;
	}
	return DATA_NOT_FOUND;

}
