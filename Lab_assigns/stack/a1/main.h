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
typedef struct s_array
{
	data_t array[CAPACITY];
	int top;
}stack_array;

//
int push(stack_array *s, data_t data);

int pop(stack_array *s, data_t *data);


int peep(stack_array s);


int peak(stack_array *s, data_t *data);
#endif


