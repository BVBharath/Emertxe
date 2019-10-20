#include "main.h"
int main()
{
	int options, data, pos;
	slist *head = NULL;
	while (1)
	{
		printf("\n1.insert_first\n2.get_nth_last\n3.get_mid\n7.print_list\n8.quit\n");
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
				printf("enter the position\n");
				scanf("%d", &pos);

				if(get_nth_last(head,  pos, &data)== SUCCESS)
				{
					printf("%dth data: %d\n", pos, data);
				}
				else
				{
					printf("list is empty\n");
				}
				break;

		case 3:

				if(get_mid(head, &data)== SUCCESS)
				{
					printf("midth data: %d\n", data);
				}
				else
				{
					printf("list is empty\n");
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
