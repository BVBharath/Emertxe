#include "main.h"

int search(hash_table hash_array[], int data)
{
	int index = data % SIZE;

	hash_table *temp; 
	if(hash_array[index].value == data)
	{
		return DATA_FOUND;
	}
	temp = hash_array[index].link;
	while(temp != NULL)
	{
		if(temp->value == data)
		{
			return DATA_FOUND;
		}

		temp = temp->link;
	}

	return DATA_NOT_FOUND;
}
