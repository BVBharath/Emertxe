#include "main.h"

int pop(slist **top)
{
	if(*top == NULL)
	{
		return LIST_EMPTY;
	}
	slist *temp = *top;
	 *top = temp->link;
	free(temp);
	return SUCCESS;
}
