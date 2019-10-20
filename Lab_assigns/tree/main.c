#include "main.h"

int main()
{
	int choice, data, height1;
	BST_Tree *root = NULL;
	BST_Tree *max = NULL, *min = NULL;
	while(1)
	{
		printf("\n1.insert_node\n2.find max\n3.find min\n4.in_order\n5.search\n6.delete_element\n7.height\n8.level_order\n9.quit\n ");
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
				printf("enter the data to search\n");
				scanf("%d", &data);
				if(search(root, data) == DATA_FOUND)
				{
					printf("data found\n");
				}
				else
				{
					printf("data not found\n");
				}
				break;
				
			case 6:
				printf("enter the data to delete\n");
				scanf("%d", &data);
				root = delete_element(root, data);
				if(root)
				{
					printf("deletion is done\n");
				}
				else
				{
					printf("tree is empty\n");
				}
				break;					

			case 7: 
					height1 = height(root);

					if(height1)
					{
						printf("height of the tree: %d\n", height1);
					}
					else
					{
						printf("tree does not exist\n");
					}
					break;

			case 8:
					level_order(root);
					break;
			case 9:
				exit(1);

		}
	}
}
