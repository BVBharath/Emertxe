#include "main.h"

Status remove_duplicate(slist **head)
{
	if(*head == NULL)
		return list_empty;
	slist *temp;
	slist *temp1 = *head;
	slist *temp2;
	while (temp1)
	{
		temp = *head;
		while(temp)
		{
			if((temp->data == temp1->data) && (temp != temp1))
			{
				while (temp->link && (temp->data == (temp->link)->data))
				{
					temp = temp->link;
				}
				temp2->link = temp->link;
				temp->link = NULL;
				free(temp);
			}
			temp2 = temp;
			temp = temp2->link;
		}
		temp1 = temp1->link;
	}
	return success;
}
