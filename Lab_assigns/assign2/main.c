#include "main.h"
//#include "insert_last.c"
//#include "print_list.c"
int main()
{
	int options, data, new_data, result, pos;
	slist *head = NULL;
	while (1)
	{
		printf("\n1.insert_first\n2.insert_after\n3.insert_before\n4.inser_nth\n5.delete_element\n7.print_list\n8.quit\n");
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
				printf("enter the data to insert at after \n");
				scanf("%d", &data);
				printf("enter the new data \n");
				scanf("%d", &new_data);

				result = insert_after(&head, data, new_data);
				
				if(result == SUCCESS)
				{
					printf("insertion at last successfull\n");
				}
				else if(result == FAILURE)
				{
					printf("insertion is unsuccessed\n");
				}
				else
				{
					printf("data not found\n");
				}

				break;

			case 3:
				//prompt + read
				printf("enter the data to insert at before \n");
				scanf("%d", &data);
				printf("enter the new data \n");
				scanf("%d", &new_data);

				result = insert_before(&head, data, new_data);
				
				if(result == SUCCESS)
				{
					printf("insertion at last successfull\n");
				}
				else if(result == FAILURE)
				{
					printf("insertion is unsuccessed\n");
				}
				else if(result == LIST_EMPTY)
				{
					printf("list is empty\n");
				}
				else
				{

					printf("data not found\n");
				}


				break;

			case 4:
				//prompt + read
				printf("enter the position \n");
				scanf("%d", &pos);
				printf("enter the new data \n");
				scanf("%d", &data);

				result = insert_nth(&head, pos, data);
				if(result == LIST_EMPTY)
				{
					printf("list is empty\n");

				}
				else if(result == FAILURE)
				{
					printf("insertion is failure\n");
				}
				else
				{
					printf("insertion success\n");
				}
				break;

			case 5: 
					printf("enter the data to be deleted\n");
					scanf("%d", &data);

					result = delete_element(&head, data);

					if(result == LIST_EMPTY)
					{
						printf("list is empty\n");

					}
					else if(result == DATA_NOT_FOUND)
					{
						printf("data not found\n");
					}
					else
					{
						printf("delete successful\n");
					}

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
