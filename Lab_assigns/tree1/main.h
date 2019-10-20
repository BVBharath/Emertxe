#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>


typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *l_link, *r_link;
}BST_Tree;


BST_Tree *get_new_node(data_t data);

BST_Tree *insert_node(BST_Tree *root, data_t data);

BST_Tree *find_max(BST_Tree *root);

BST_Tree *find_min(BST_Tree *root);


void in_order(BST_Tree *root);
#endif
