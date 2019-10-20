#include "main.h"

int insert_first(slist **head, data_t data)
{

	slist *new = malloc(sizeof(slist));

	if(new == NULL)
	{
		printf("memory is not available\n");
		return FAILURE;
	}

	new->data = data;
	new->link = *head;
	*head = new;
	return SUCCESS;
	
}
