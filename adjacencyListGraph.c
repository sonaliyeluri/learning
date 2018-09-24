#include<stdio.h>
#include<stdlib.h>

struct adjListNode
{
	int dest;
	struct adjListNode *next;
};

struct adjList
{
	struct adjListNode *head;
};

struct Graph
{
	int V;
	struct adjList* array;
};

struct adjListNode *newAdjListNode(int dest)
{
	struct adjListNode *newNode = malloc(sizeof(struct adjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

struct Graph *createGraph(int V)
{
	struct Graph *graph = malloc(sizeof(struct Graph));
	graph->V = V;
	graph->array = malloc(V*sizeof(struct adjList));
	int i;
	for (i=0;i<V;i++)
		graph->array[i].head = NULL;
	return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
	struct adjListNode *newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
	
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

void printGraph(struct Graph *graph)
{
	int v;
	for (v=0;v<graph->V;v++)
	{
		struct adjListNode *trav = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while(trav)
		{
			printf("-> %d", trav->dest);
			trav = trav->next;
		}
		printf("\n");
	}
}

int main()
{
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	printGraph(graph);
	return 0;
}	
	
	
