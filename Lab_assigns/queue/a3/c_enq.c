#include "main.h"

int c_enq(slist **head, data_t data)
{
	slist *new = malloc(sizeof(slist));
	new->data = data;
	
	if(*head == NULL)
	{
		new->link = new;
		*head = new;
		return SUCCESS;
	}

	new->link = *head;

	slist *temp = *head;

	while(temp->link != *head)
	{
		temp = temp->link;
	}

	temp->link = new;



	return SUCCESS;
	

	


}
