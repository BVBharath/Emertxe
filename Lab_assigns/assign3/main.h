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
	struct node *prev;
	struct node *next;
}dlist;



int insert_first(dlist **head, data_t data, dlist **tail);

void print_list(dlist *head);


int insert_last(dlist **head, data_t data, dlist **tail);

int delete_first(dlist **head, dlist **tail);

int delete_last(dlist **head, dlist **tail);


int delete_list(dlist **head, dlist **tail);
#endif
