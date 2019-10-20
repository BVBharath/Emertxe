#include "main.h"
int main()
{
	int options, data;
	slist *head = NULL;
	slist *prev, *next, *current;
	while (1)
	{
		printf("\n1.insert_first\n2.reverse_link_iteration\n3.reverse_recursive\n7.print_list\n8.quit\n");
		scanf("%d", &options);
		switch(options)
		{
			case 1:
				printf("enter the data to insert at first\n");
				scanf("%d", &data);


				if(insert_first(&head, data) == SUCCESS)
				{
					printf("insertion is done\n");
				}
				else
				{
					printf("insertion is not done\n");
				}
				break;

			case 2:
				if(reverse_iteration(&head) == SUCCESS)
				{
					printf("reverse is done\n");
				}
				else
				{
					printf("reverse is not done\n");
				}
				break;


			case 3:
					current = head;
					prev = NULL;
					next = NULL;
				if(reverse_recursive(&head, &prev, &next, &current) == SUCCESS)
				{
					printf("reverse is done\n");
				}
				else
				{
					printf("reverse is not done\n");
				}
				break;


			case 7:
				print_list(head);
				break;


			default:

				exit(1);



		}
	}
	return 0;

}
