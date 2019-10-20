#include "main.h"

void swap(slist *num1, slist *num2)
{
	int temp = num1->data;
	num1->data = num2->data;
	num2->data = temp;
}
