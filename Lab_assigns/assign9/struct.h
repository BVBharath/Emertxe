#ifndef STRUCT_H
#define STRUCT_H

typedef int data_t;
typedef struct node
{
	data_t data;
	struct node*link;
}slist;

typedef enum
{
	success,
	failure,
	list_empty,
	data_found,
	data_not_found
}Status;

/*Insert element at last */
Status insert_at_last(slist **head, data_t data);

/*remove duplicates */
Status remove_duplicate(slist **head);

/*Print all the elements */
void print_list(slist *head);
#endif
