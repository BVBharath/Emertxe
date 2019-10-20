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



void print_list(slist *head);

int insert_first(slist **head, data_t data);

int insert_after(slist **head, data_t data, data_t new_data);

int insert_before(slist **head, data_t data, data_t new_data);

int insert_nth(slist **head, data_t pos, data_t data);

int delete_element(slist **head, data_t data);
int delete_first(slist **head);
#endif
