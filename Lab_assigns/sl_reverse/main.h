#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define FAILURE 0
#define LIST_EMPTY -1
#define DATA_FOUND 5
#define DATA_NOT_FOUND 6
typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *link;
}slist;

int reverse_iteration(slist **head);

int reverse_recursive(slist **head, slist **prev, slist **next, slist **current);
void print_list(slist *head);

int insert_first(slist **head, data_t data);



#endif
