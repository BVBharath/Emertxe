#include "main.h"

int search(BST_Tree *root, data_t data)
{
	if(root == NULL)
	{
		return DATA_NOT_FOUND;
	}

	if (root->data == data)
	{
		return DATA_FOUND;
	}
	else if(data < root->data)
	{
		search(root->l_link, data);
	}
	else
	{

		search(root->r_link, data);
	}


}
