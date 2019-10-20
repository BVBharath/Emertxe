#include "main.h"

int main()
{
	//initialize the variables
	data_t i, options, data;

	for(i = 0; i < SIZE; i++)
	{
		hash_array[i].key = i;
		hash_array[i].value = -1;
		hash_array[i].link = NULL;
	}

	//prompt
	while(1)
	{
		printf("1.insert_hash_table\n2.print_hash_table\n3.search_data\n4.delete_element\n5.delete_hash_table\n6.quit\n");
		scanf("%d", &options);


		switch(options)
		{
			case 1:
				printf("enter the data to be insert\n");
				scanf("%d", &data);
				insert_hash_table(hash_array, data);
				break;

			case 2:
				print_hash(hash_array, SIZE);
				break;

			case 3:
				printf("enter the data to be search\n");
				scanf("%d", &data);

				if(search(hash_array, data) == DATA_FOUND)
				{
					printf("data found\n");
				}
				else
				{
					printf("data not found\n");
				}
				break;

			case 4:
				printf("enter the data to be insert\n");
				scanf("%d", &data);

				if(delete_element(hash_array, data) == SUCCESS)
				{
					printf("data has been deleted\n");
				}
				break;
			case 5:
				if(delete_hash(hash_array, SIZE) == SUCCESS)
				{
					printf("hash has been deleted\n");
				}
				break;


			case 6:
				exit(1);


		}
	}

}
