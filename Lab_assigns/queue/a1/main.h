#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define FAILURE 0
#define LIST_EMPTY -1
#define QUEUE_OVERFLOW 5
#define QUEUE_UNDERFLOW 6
#define CAPACITY 5
typedef int data_t;
typedef struct 
{
	data_t array[CAPACITY];
	int front, rear;
}q_array;

//
int enq(q_array *q, data_t data);

int deq(q_array *q, data_t *data);

int print_queue(q_array q);
#endif


