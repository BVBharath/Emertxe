#include "main.h"

int find_node(slist *head, data_t data)
{
	if(head == NULL)
	{
		return LIST_EMPTY;
	}
	while(head)
	{
		if(head->data == data)
		{
			return DATA_FOUND;
		}

		head = head->link;
	}

	return DATA_NOT_FOUND;


}
