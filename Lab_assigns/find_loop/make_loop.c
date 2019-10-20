#include "main.h"

void make_loop(slist *head)
{
	slist *temp = head;

	while(temp->link)
	{
		temp = temp->link;
	}

	temp->link = head->link->link;
	
}
