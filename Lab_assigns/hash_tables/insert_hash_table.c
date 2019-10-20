#include "main.h"

int insert_hash_table(hash_table hash_array[], data_t data)
{
	int index = data % SIZE;

	if(hash_array[index].value == -1)
	{
		hash_array[index].value = data;
		return SUCCESS;
	}

	hash_table *new = malloc(sizeof(hash_table));

	if(new == NULL)
	{
		return FAILURE;
	}

	new->key = index;
	new->value = data;
	new->link = NULL;

	if(hash_array[index].link == NULL)
	{
		hash_array[index].link = new;
		return SUCCESS;
	}

	hash_table *temp = hash_array[index].link;

	while(temp->link)
	{
		temp = temp->link;
	}
	temp->link = new;
	return SUCCESS;
}
