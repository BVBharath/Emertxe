#include "main.h"

int main()
{
	int choice, data;
	BST_Tree *root = NULL;
	BST_Tree *max = NULL, *min = NULL;
	while(1)
	{
		printf("\n1.insert_node\n2.find max\n3.find min\n4.print\n5.quit\n ");
		scanf("%d", &choice);

		switch(choice)
		{


			case 1:
				printf("enter the data to insert in node\n");
				scanf("%d", &data);
				root = insert_node(root, data);
				break;

			case 2:
				max = find_max(root);
				printf("max: %d\n", max->data );
			
				break;

			case 3:
				min = find_min(root);
			
				printf("min: %d\n", min->data );
			
				break;

			case 4:
				in_order(root);

				break;

			case 5:
				exit(1);

		}
	}
}
