#include "main.h"

BST_Tree *get_new_node(data_t data)
{
	BST_Tree *new = malloc(sizeof(BST_Tree));
	if(new == NULL)
	{
		return NULL;
	}
	new->data = data;
	new->l_link = NULL;
	new->r_link = NULL;
	return new;
}
