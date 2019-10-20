#include "main.h"

int insert_before(slist **head, data_t data, data_t new_data)
{
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}
	if((*head)->data == data)
	{
		return insert_first(head, new_data);
	}
	slist *temp  = *head, *temp1;

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
			new->link = temp1->link;
			temp1->link = new;
			return SUCCESS;
		}
		temp1 = temp;
		temp = temp->link;
	}
	return DATA_NOT_FOUND;
}
