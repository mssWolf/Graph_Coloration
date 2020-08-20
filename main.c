#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
 	Node * graph;
	int number_node ;
	int color;
	printf("the number of nodes is :\t");
	scanf("%d",&number_node);
	graph = create_graph(number_node);
	color = color_graph(graph,number_node);
	print_graph(graph,number_node);
	printf("\x1b[32m""the number of colors needed is %d \n",color );

	return 0;
}
