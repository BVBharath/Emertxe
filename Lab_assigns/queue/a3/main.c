#include "main.h"
int main()
{
	int options, data;
	slist *head = NULL;
	while (1)
	{
		printf("\n1.c_enq\n2.d_enq\n7.print_list\n8.quit\n");
		scanf("%d", &options);
		switch(options)
		{
			case 1:
				printf("enter the data to insert \n");
				scanf("%d", &data);


				if(c_enq(&head, data) == SUCCESS)
				{
					printf("insertion is done\n");
				}
				else
				{
					printf("insertion is not done\n");
				}
				break;

			case 2:


				if(d_enq(&head) == SUCCESS)
				{
					printf("deletion is done\n");
				}
				else
				{
					printf("deletion is not done\n");
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
