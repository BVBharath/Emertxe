#include "main.h"

int delete_hash(hash_table hash_array[], int size)
{
	int i;

	hash_table *temp;

	for(i = 0; i < size; i++)
	{
		if(hash_array[i].value != -1)
		{
			hash_array[i].value = -1;
			while(hash_array[i].link)
			{
				temp = hash_array[i].link;

				hash_array[i].link = temp->link;
				free(temp);


			}
		}
	}
	return SUCCESS;
}
