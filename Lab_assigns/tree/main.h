#ifndef MAIN_H
#define MAIN_H
#define DATA_FOUND 1
#define DATA_NOT_FOUND 2
#define TREE_DOES_NOT_EXIST 0
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

int search(BST_Tree *root, data_t data);

int height(BST_Tree *root);
BST_Tree *delete_element(BST_Tree *root, data_t data);
void in_order(BST_Tree *root);

void level_order(BST_Tree *root);
void print_level(BST_Tree *root, int level);
#endif
