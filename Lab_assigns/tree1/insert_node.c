#include "main.h"

BST_Tree *insert_node(BST_Tree *root, data_t data)
{
	if(root == NULL)
	{
		root = get_new_node(data);

	}
	else if(data > root->data)
	{
		root->l_link = insert_node(root->l_link, data);
	}
	else if(data < root->data)
	{
		root->r_link = insert_node(root->r_link, data);
	}
	else
	{
		printf("data already present\n");
	}
	return root;
}
