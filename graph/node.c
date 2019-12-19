#include "node.h"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define WHITE "\x1b[37m"

Adjacent * init_list(int node_place)
{
	Adjacent * head;
	head = malloc(sizeof(Adjacent));
	if(head == NULL)
		exit(EXIT_FAILURE);
	
	head->node_place	=	node_place;
	head->next	=	NULL;
	return head;
}

Adjacent *  add_first_item(Adjacent * head, int node_place)
{
	Adjacent * item;
	item = malloc(sizeof(Adjacent));
	if(item == NULL)
		exit(EXIT_FAILURE);
	item->next = head;
	item->node_place = node_place;
	return item;
}

Adjacent * del_first_item(Adjacent * head)
{
	Adjacent * item;
	if(head == NULL)
		exit(EXIT_FAILURE);
	item = head->next;
	free(head);
	return item;
}

int if_exist(Adjacent * head,int node_place)
{
	Adjacent * tmp;
	tmp = head;
	while(tmp != NULL)
	{
		if(tmp->node_place == node_place)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

void print_list(Adjacent * head)
{
	Adjacent *tmp;
	tmp = head;
	while(tmp!=NULL)
	{
		printf(WHITE"%d\t",tmp->node_place);
		tmp= tmp->next;
	}
}
int if_color_allowed(Adjacent * head, Node * graph, int color)
{
	Adjacent * tmp;
	tmp = head;
	while(tmp != NULL)
	{
		if(graph[tmp->node_place].color==color)
			return 0;
		tmp = tmp->next;
	}
	return 1;
}
Node * create_graph(int number_node)
{
	Node * graph;
	int tmp;
	graph = malloc(number_node * sizeof(Node));
	if(graph == NULL)
		exit(EXIT_FAILURE);
	for (int i =0; i<number_node;i++)
		graph[i].color = -1;
	printf("Graph created succefully \n");
	printf("Nodes from 0 to %d\n",number_node-1);
	printf("\t\tNow we are going complete the graph : \n");
	for(int i =0 ;i<number_node;i++)
	{
		printf(BLUE"\n\t\t Node %d",i );
		printf(RED"\nyou want to add an adjacent node to node %d\n",i);
		printf(GREEN"No = 0 Yes = other number, your  answer :\t");
		scanf("%d",&tmp);
		while(tmp != 0)
		{
			printf(GREEN"Node %d is adjacent to node :\t",i );
			scanf("%d",&tmp);
			if(tmp >=0 && tmp<number_node && tmp != i)
			{
				graph[i].adjacent = add_first_item(graph[i].adjacent,tmp);
				printf(WHITE"added succefully\n");
			}
			else
				{
					printf(RED"Not possible !!!\n");
					tmp = 1;
				}
			printf(RED"you want to add another adjacent node ?\n");
			printf(GREEN"No = 0 Yes = other number, your  answer :\t");
			scanf("%d",&tmp);
		}
	}
	return graph;
}

void print_graph (Node * graph,int number_node)
{
	printf("Graph : \n");
	for (int i = 0; i < number_node; i++)
	{
		printf (WHITE"node : %d,",i);
		printf(GREEN"color : %d",graph[i].color);
		printf(WHITE" adjacent to : \n \t\t");
		print_list(graph[i].adjacent);
		printf("\n");
	}
}

int color_graph(Node * graph, int number_node)
{
	int color = 0;
	for (int i=0;i<number_node;i++)
	{
		if(graph[i].color == (-1))
		{
			graph[i].color = color;
			for(int j = i+1;j<number_node;j++)
			{
				if(graph[j].color ==-1)
				{
					if(!if_exist(graph[i].adjacent,j))
					{
						if(if_color_allowed(graph[j].adjacent,graph,color))
							graph[j].color=color;
					}
				}
			}
			color ++;
		}
	}
	return color;
}