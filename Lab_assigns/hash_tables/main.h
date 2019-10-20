#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>


#define SIZE 10

#define SUCCESS 1

#define FAILURE 2

#define DATA_FOUND 3
#define DATA_NOT_FOUND 4


typedef int data_t;

typedef struct hash
{
	int key;
	data_t value;
	struct hash *link;
}hash_table;

hash_table hash_array[SIZE];

void print_hash(hash_table hash_array[], int size);

int insert_hash_table(hash_table hash_array[], data_t data);

int search(hash_table hash_array[], int data);

int delete_element(hash_table hash_array[], int data);


int delete_hash(hash_table hash_array[], int size);
#endif
