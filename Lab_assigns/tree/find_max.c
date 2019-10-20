#include "main.h"

BST_Tree *find_max(BST_Tree *root)
{
	if(root == NULL)
	{
		return NULL;
	}

	while(root->r_link)
	{
		root = root->r_link;
	}

	return root;
}
