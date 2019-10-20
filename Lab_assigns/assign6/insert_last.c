#include "main.h"
int insert_last(slist **head, data_t data)
{
	slist *new = malloc(sizeof(slist));

	if(new == NULL)
	{
		printf("sufficient memory not availaible");
		return FAILURE;
	}
	new->data = data;
	new->link = NULL;

	if(*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}
	slist *temp = *head;
	while(temp->link)
	{
		temp = temp->link;
	}
	temp->link = new;
	return SUCCESS;
}
