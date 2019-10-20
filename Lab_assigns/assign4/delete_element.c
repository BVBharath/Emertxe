#include "main.h"

int delete_element(dlist **head, dlist **tail, data_t data)
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
			temp->prev->next = temp ->next;
			temp->next->prev= temp->prev;
			free(temp);
			return SUCCESS;
		}
		temp = temp->next;
	}
}
