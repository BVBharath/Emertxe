#include "main.h"
//#include "insert_last.c"
//#include "print_list.c"
int main()
{
	int options, data, new_data, result, pos;
	dlist *head = NULL;
	dlist *tail = NULL;
	while (1)
	{
		printf("\n1.insert_first\n2.insert_last\n3.delete_first\n4delete_last\n5.delete_list\n6.print_list\n7.quit\n");
		scanf("%d", &options);
		switch(options)
		{
			case 1:
					printf("enter the data to insert at first\n");
					scanf("%d", &data);

					if(insert_first(&head, data, &tail) == SUCCESS)
					{
						printf("insertion is done\n");
					}
					else
					{
						printf("insertion is not done\n");
					}
					break;

			case 2: 				
					printf("enter the data to insert at lat\n");
					scanf("%d", &data);

					if(insert_last(&head, data, &tail) == SUCCESS)
					{
						printf("insertion is done\n");
					}
					else
					{
						printf("insertion is not done\n");
					}
					break;

			case 3:
					if(delete_first(&head, &tail) == SUCCESS)
					{
						printf("delete first is done\n");
					}
					else
					{
						printf("delete first is not done\n");
					}
					break;

			case 4:
					if(delete_last(&head, &tail) == SUCCESS)
					{
						printf("delete last is done\n");
					}
					else
					{
						printf("delete last is not done\n");
					}
					break;
			case 5: 
					
					if(delete_list(&head, &tail) == SUCCESS)
					{
						printf("delete list is done\n");
					}
					else
					{
						printf("delete list is not done\n");
					}
	
				break;

			case 6:
					print_list(head);
					break;


			default:
					
					exit(1);



		}
	}
	return 0;

}
