#include "main.h"

int insert_nth(slist **head, data_t pos, data_t data)
{
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}

	if(pos < 1)
	{
		return FAILURE;
	}

	slist *temp = *head, *temp1;
	while(--pos)
	{
		temp1 = temp;
		temp = temp->link;
		if(!temp)
		{
			return FAILURE;
		}
	}
	slist *new = malloc(sizeof(slist));
	new->data = data;
	new->link = temp;
	temp1->link = new;
	return SUCCESS;

}
