#include "main.h"

int delete_element(slist ** head, data_t data)
{
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}
	if((*head) -> data == data)
	{
		return delete_first(head);
	}
	slist *temp = *head;
	slist *temp1;
	while(temp)
	{
		if(temp -> data == data)
		{
			temp1 -> link = temp -> link;
			free(temp);
			return SUCCESS;
		}
		temp1 = temp;
		temp = temp -> link;
	}

	return DATA_NOT_FOUND;
}
