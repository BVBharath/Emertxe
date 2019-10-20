#include "main.h"

int  get_nth_last(slist *head,data_t n,data_t *data)
{
	slist *temp = head;
	slist *temp1 = head;
	if(head == NULL)
	{
		return LIST_EMPTY;
	}
	while(--n && temp)
	{
		temp = temp->link;
	}
	if (n)
	{
		return FAILURE;
	}
	while (temp->link)
	{
		temp1 = temp1->link;
		temp = temp->link;
	}
	*data = temp1->data;
	return SUCCESS;

}


