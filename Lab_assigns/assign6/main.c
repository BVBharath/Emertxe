#include "main.h"
int main()
{
	int options, data;
	slist *head = NULL;
	while (1)
	{
		printf("\n1.insert_sorted\n2.find_loop\n7.print_list\n8.quit\n");
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
