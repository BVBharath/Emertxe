#include "main.h"

int remove_duplicates(slist **head)
{
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}

	slist *ptr1, *ptr2, *dup;

	ptr1 = *head;

	while(ptr1 != NULL && ptr1->link != NULL)
	{
		ptr2 = ptr1;

		while(ptr2->link)
		{
			if(ptr1->data == ptr2->link->data)
			{
				dup = ptr2->link;

				ptr2->link = dup->link;
				free(dup);
			}
			else
			{
				ptr2 = ptr2->link;
			}
		}
		ptr1 = ptr1->link;
	}

}
