#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next_ptr;
}node;

node *head_ptr, *tail_ptr;

void create_node();
void create_loop_in_list();
void num_of_elements_in_loop();

int main()
{
    int num_of_elements = 0, element = 0;

    printf(" Enter number of elements: ");
    scanf("%d", &num_of_elements);

    for(int counter = 0; counter < num_of_elements; counter++)
	{
		printf("\nEnter element %d: ",counter+1);
		scanf("%d",&element);
		create_node(element);
	}
	printf("\nList created successfully\n");

	create_loop_in_list(num_of_elements);
	printf("\nLoop created successfully\n");

	num_of_elements_in_loop();

    return 0;
}


void create_node(int value)
{
  node *to_create_node = head_ptr, *point_end;

  to_create_node = (node*)malloc(sizeof(node));

  to_create_node->data = value;
  to_create_node->next_ptr = NULL;

  if(head_ptr == NULL)
  {
  	 head_ptr = tail_ptr = to_create_node;
  }
  else
  {
  	point_end = head_ptr;

  	while(point_end->next_ptr != NULL)
	{
		point_end = point_end ->next_ptr;
	}
	point_end->next_ptr = tail_ptr = to_create_node;
  }
}



void create_loop_in_list(int num_of_data)
{
	int to_join = 0;
	node *to_create_loop = head_ptr;

	do
	{
		printf("\nThere are %d nodes in list",num_of_data);
		printf("\nPlease enter to which node you want to connect last node: ");
		scanf("%d",&to_join);

		if(to_join > num_of_data)
			printf("\nInvalid input");

    }while(to_join > num_of_data);

    for(int i = 1; i<to_join; ++i )
	{
		to_create_loop = to_create_loop->next_ptr;
	}

	tail_ptr->next_ptr = to_create_loop;
}



void num_of_elements_in_loop()
{
	node *nodes = tail_ptr->next_ptr;
	int nodes_in_loop = 1;//circular linked list

	while(nodes != tail_ptr)
	{
		++nodes_in_loop;
		nodes = nodes->next_ptr;
	}
	printf("\nNumber of nodes in loop are %d\n", nodes_in_loop);
}
