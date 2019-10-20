#include "main.h"

int d_enq(slist **front)
{
	if(*front == NULL)
	{
		return LIST_EMPTY;
	}

	if((*front)->link == (*front))
	{
		free(*front);
	}

	slist *temp = *front;

	while(temp->link != *front)
	{
		temp = temp->link;
	}

	temp->link = (*front)->link;
	free(*front);

	*front = temp->link;
	return SUCCESS;


}
