#include "main.h"

int delete_element(hash_table hash_array[], int data)
{
	int index = data % SIZE, dummy;

	hash_table *temp, *temp1;

	if(hash_array[index].value == data)
	{
		temp = hash_array[index].link;
		if(temp != NULL)
		{
			dummy = temp->value;
			temp->value = hash_array[index].value ;
			hash_array[index].value = dummy;
			hash_array[index].link = temp->link;
			free(temp);
			return SUCCESS;
		}

		hash_array[index].value = -1;
		return SUCCESS;
	}

	temp1 =	temp = hash_array[index].link;

		while(temp != NULL)
		{
			if(temp->value == data)
			{
				temp1->link = temp->link;
				free(temp);
				return SUCCESS;
			}

			temp1 = temp;
			temp = temp->link;


		}

		return FAILURE;
	

}
