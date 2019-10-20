#include "main.h"

BST_Tree *delete_element(BST_Tree *root, data_t data)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(root->data > data)
	{
		root->l_link = delete_element(root->l_link, data);
	}
	else if(root->data < data)
	{
		root->r_link = delete_element(root->r_link, data);
	}
	else
	{
		if(root->l_link == NULL && root->r_link == NULL)
		{
			free(root);
		}
		else if(root->l_link && root->r_link == NULL)
		{
			BST_Tree *temp = root;
			root = root->l_link;
			free(temp);
		}

		else if(root->l_link == NULL && root->r_link)
		{
			BST_Tree *temp = root;
			root = root->r_link;
			free(temp);
	
		}
		else
		{
			BST_Tree *temp = find_min(root->r_link);
			root->data = temp->data;
			root->r_link = delete_element(root->r_link, temp->data);
	
		}
		return root;

	}
}
