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
		printf("\n1.insert_first\n2.insert_after\n3.insert_before\n4.delete_element\n7.print_list\n8.quit\n");
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
					printf("enter the data to insert at first\n");
					scanf("%d", &data);

					printf("enter the data to insert at first\n");
					scanf("%d", &new_data);


					if(insert_after(&head,  &tail, data, new_data) == SUCCESS)
					{
						printf("insertion is done\n");
					}
					else
					{
						printf("insertion is not done\n");
					}
				
					break;

			case 3:
					printf("enter the data to insert at first\n");
					scanf("%d", &data);

					printf("enter the data to insert at first\n");
					scanf("%d", &new_data);


					if(insert_before(&head,  &tail, data, new_data) == SUCCESS)
					{
						printf("insertion is done\n");
					}
					else
					{
						printf("insertion is not done\n");
					}
				
					break;

			case 4:
					printf("enter the data to delete\n");
					scanf("%d", &data);
					if(delete_element(&head, &tail, data) == SUCCESS)
					{
						printf("deletion is done\n");
					}
					else
					{
						printf("deletion is not done\n");
					}
	
				break;
			case 5: 
					break;

			case 6:
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
