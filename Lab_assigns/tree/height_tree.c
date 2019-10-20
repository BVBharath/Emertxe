#include "main.h"


int height(BST_Tree *root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		int l_height = height(root->l_link);
		int r_height = height(root->r_link);
	

	if(l_height > r_height)
	{
		return (l_height + 1);
	}

		return (r_height + 1 );

	}



}
