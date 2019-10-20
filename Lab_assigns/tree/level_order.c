#include "main.h"

void level_order(BST_Tree *root)
{
	int h = height(root);

	int i;

	for(i = 1; i <=h; i++)
	{
		print_level(root, i);
	}

}

//
void print_level(BST_Tree *root, int level)
{
	if (root == NULL)
	{
		return;
	}

	if(level == 1)
	{
		printf("%d ", root->data);
	}
	else if(level > 1)
	{
		print_level(root->l_link, level-1);

		print_level(root->r_link, level-1);
	}
}
