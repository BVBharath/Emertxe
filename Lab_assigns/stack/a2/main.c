#include "main.h"
int main()
{
	int options, data;
	slist *top = NULL;
	while (1)
	{
		printf("\n1.push\n2.pop\n7.peep\n8.quit\n");
		scanf("%d", &options);
		switch(options)
		{
			case 1:
				printf("enter the data to insert at first\n");
				scanf("%d", &data);


				if(push(&top, data) == SUCCESS)
				{
					printf("push is done\n");
				}
				else
				{
					printf("push is not done\n");
				}
				break;

			case 2:


				if(pop(&top) == SUCCESS)
				{
					printf("pop is done\n");
				}
				else
				{
					printf("pop is not done\n");
				}
				break;


			case 7:
				peep(top);
				break;


			default:

				exit(1);



		}
	}
	return 0;

}
