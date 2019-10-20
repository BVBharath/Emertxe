#include "main.h"

int get_mid(slist *p1, data_t *data)
{
	if(p1 == NULL)
	{
		return LIST_EMPTY;
	}
	slist *p2 = p1;



	while(p1 && p1->link)
	{

		p1 = p1->link->link;



		p2 = p2->link;


	}

	*data = p2->data;
	return SUCCESS;
}
