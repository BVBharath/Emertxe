#include "main.h"

int find_loop(slist *head)
{
	slist *p1, *p2;

	p1 = head;
	p2 = head;

	while(p1)
	{
		p1 = p1->link->link;
		p2 = p2->link;

		if(p1 == p2)
		{
			return LOOP_EXIST;
		}
	}

	return LOOP_NOT_EXIST;
}
