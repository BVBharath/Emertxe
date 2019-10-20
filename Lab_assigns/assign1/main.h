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
int insert_last(slist **head, data_t data);



void print_list(slist *head);

int insert_first(slist **head, data_t data);

int delete_first(slist **head);
int delete_last(slist **head);

int find_node(slist *head, data_t data);

int delete_list(slist **head);
#endif