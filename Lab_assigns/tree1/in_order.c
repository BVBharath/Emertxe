#include "main.h"

void in_order(BST_Tree *root)
{
	if(root == NULL)
	{
		return;
	}

	in_order(root->l_link);

	printf("%d-->", root->data);
	in_order(root->r_link);
}
