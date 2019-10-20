#include "main.h"

int main()
{
	stack_array *s = malloc(sizeof(stack_array));

	if(s == NULL)
	{
		printf("memory is not allocated\n");
		exit(1);
	}

	s->top = -1;

	data_t data, options;

	while(1)
	{
		printf("select one of the options\n1.push_stack\n2.pop_stack\n3.peep_stack\n4.peak_stack\n");
		scanf("%d", &options);

		switch(options)
		{
			case 1:
					printf("enter the data to push into stack\n");
					scanf("%d", &data);
					if(push(s, data) == SUCCESS)
					{
						printf("pushing is done\n");
					}
					else
					{
						
						printf("pushing is  not done\n");
					}

					break;

			case 2:
					if(pop(s, &data) == SUCCESS)
					{
						printf("data : %d\n", data);
					}
					else
					{
						
						printf("stack is under flow\n pop is not done\n");
					}
					break;

			case 3:
					if(peep(*s) == SUCCESS)
					{
						printf("peep function is done\n");
					}
					else
					{
						
						printf("stack is under flow\n peep is not done\n");
					}
					break;

			default :
					if(peak(s, &data) == SUCCESS)
					{
						printf("top data : %d\n", data);
					}
					else
					{
						
						printf("stack is under flow\n peak is not done\n");
					}
	


		}

	}

}
