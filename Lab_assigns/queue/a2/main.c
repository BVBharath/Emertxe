#include "main.h"

int main()
{
	q_array *q = malloc(sizeof(q_array));

	if(q == NULL)
	{
		printf("memory is not allocated\n");
		exit(1);
	}

	q->front = -1;
	q->rear = -1;
	q->count = 0;

	data_t data, options;

	while(1)
	{
		printf("select one of the options\n1.c_enq\n2.deq\n3.print_queue\n4.exit\n");
		scanf("%d", &options);

		switch(options)
		{
			case 1:
					printf("enter the data to queue\n");
					scanf("%d", &data);
					if(c_enq(q, data) == SUCCESS)
					{
						printf("enq  is done\n");
					}
					else
					{
						
						printf("enq is  not done\n queue full\n");
					}

					break;

			case 2:
					if(c_deq(q, &data) == SUCCESS)
					{
						printf("data: %d\n", data);
					}
					else
					{
						
						printf("deq is  not done\n queue empty\n");
					}
			case 3:
					if(print_queue(*q) == SUCCESS)
					{
						printf("printing is done\n");
					}
					else
					{
						printf("printing is not done\n");
					}
					break;

			default:
					exit(1);
	


		}

	}

}
