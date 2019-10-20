#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define FAILURE 0
#define LIST_EMPTY -1
#define STACK_OVERFLOW 5
#define STACK_UNDERFLOW 6
#define CAPACITY 5
typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *link;
}slist;

//
int push(slist **head, data_t data);
int pop(slist **head);
void peep(slist *head);
#endif


