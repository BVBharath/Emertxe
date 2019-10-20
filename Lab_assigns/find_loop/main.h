#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define FAILURE 0
#define LIST_EMPTY -1
#define LOOP_EXIST 5
#define LOOP_NOT_EXIST 6
typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *link;
}slist;
int insert_first(slist **head, data_t data);



void print_list(slist *head);


void make_loop(slist *head);

int find_loop(slist *head);
#endif
