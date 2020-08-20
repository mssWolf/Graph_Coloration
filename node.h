#include <stdio.h>
#include <stdlib.h>

typedef struct Adjacent
{
	int node_place;
	struct Adjacent * next;
}Adjacent;
typedef struct Node
{
	int color;
	Adjacent * adjacent;
}Node;

Adjacent * init_list(int node_place);
Adjacent * add_first_item(Adjacent * head, int node_place);
Adjacent * del_first_item(Adjacent * head);
void print_list(Adjacent * head);
Node * create_graph(int number_node);
void print_graph (Node * graph,int number_node);
int if_color_allowed(Adjacent * head, Node * graph, int color);
int if_exist(Adjacent * head,int node_place);
int color_graph(Node * graph, int number_node);
