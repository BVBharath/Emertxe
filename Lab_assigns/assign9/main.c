#include "main.h"

int main()
{
	slist *head = NULL;
	
	char choice;
	int data;
	int key;
	while(1)
	{
		printf("Enter an option:\n1)Insert at last\n2)remove duplicates\n3)Print\n4)Exit\nOption:");
		scanf("\n%c", &choice);
		switch(choice)
		{
			case '1':
					printf("Enter the data:");
					scanf("%d",&data);
					if(insert_at_last(&head, data) == success)
					{
						printf("Data:%d Successfully added\n",data);
						putchar('\n');
					}
					break;
			case '2':
					if(remove_duplicate(&head) == success)
					{
						printf("Duplicate Data removed\n");
					}
					else
					{
						printf ("List empty\n");
					}
					putchar('\n');
					break;
			 case '3':
					print_list(head);
					break;
			default: return 1;
		}
	}
}
