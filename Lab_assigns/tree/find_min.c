#include "main.h"

BST_Tree *find_min(BST_Tree *root)
{
	if(root == NULL)
	{
		return NULL;
	}

	while(root->l_link)
	{
		root = root->l_link;
	}

	return root;
}
