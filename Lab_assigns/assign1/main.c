#include "main.h"
int main()
{
	int options, data;
	slist *head = NULL;
	while (1)
	{
		printf("\n1.insert_first\n2.insert_last\n3.delete_first\n4.delete_last\n5.find_node\n6.delete_list\n7.print_list\n8.quit\n");
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
				//prompt + read
				printf("enter the data to insert at last\n");
				scanf("%d", &data);

				if(insert_last(&head, data) == SUCCESS)
				{
					printf("insertion at last successfull\n");
				}
				else
				{
					printf("insertion is unsuccessed\n");
				}

				break;

			case 3:
				if(delete_first(&head) == LIST_EMPTY)
				{
					printf("delete first unsuccess\n");
				}
				else
				{
					printf("delete first success\n");
				}

				break;

			case 4:
				if(delete_last(&head) == SUCCESS)
				{
					printf("delete first success\n");
				}
				else
				{
					printf("delete first unsuccess\n");
				}


				break;

			case 5: 
				printf("enter the data to search\n");
				scanf("%d", &data);
				if(find_node(head, data) == DATA_FOUND)
				{
					printf("data found\n");
				}
				else
				{

					printf("data not found\n");
				}
				break;

			case 6:
				if(delete_list(&head) == LIST_EMPTY)
				{
					printf("list is empty\n");
				}
				else
				{
					printf("delete list is successfull\n");
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
