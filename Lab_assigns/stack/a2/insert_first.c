#include "main.h"

int push(slist **top, data_t data)
{

	slist *new = malloc(sizeof(slist));

	if(new == NULL)
	{
		printf("memory is not available\n");
		return FAILURE;
	}

	new->data = data;
	new->link = *top;
	*top = new;
	return SUCCESS;
	
}
