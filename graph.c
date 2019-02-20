#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct adj_list{
	struct adj_list *next;
	int value;
}adj_list;

typedef struct queue{
	struct adj_list *head;
}QUEUE;

typedef struct graph{
	adj_list* vertices[MAX_SIZE];
	int visited[MAX_SIZE];
}GRAPH;

int is_empty(int size)
{
	return (size == 0);
}

QUEUE *create_queue(){
	QUEUE *queue = (QUEUE*)malloc(sizeof(QUEUE));
	queue->head = NULL;
	return queue;
}

GRAPH *creating_graph()
{
	GRAPH *new_graph = (GRAPH*) malloc(sizeof(GRAPH));
	int i;
	for(i = 0; i < MAX_SIZE; i++)
	{
		new_graph -> vertices[i] = NULL;
		new_graph -> visited[i] = 0;
	}
	return new_graph;
}
adj_list *creating_node(int value)
{
	adj_list *new_node = (adj_list*) malloc(sizeof(adj_list));
	new_node -> next = NULL;
	new_node -> value = value;
	return new_node;
}

void enqueue_queue_simple(QUEUE *the_queue, int data, int queue_size)
{
	adj_list *new_node = creating_node(data);
	if(the_queue->head == NULL)
	{
		the_queue -> head = new_node;
		return;
	}
	adj_list *current = the_queue->head;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = new_node;
}

int dequeue(QUEUE *the_queue, int queue_size){
	int val;
	adj_list *aux = the_queue->head;
	the_queue->head = the_queue->head->next;
	val = aux->value;
	free(aux);
	return val;
}

void BFS(GRAPH *graph, int source){
	QUEUE *queue = create_queue();
	int queue_size = 1;
	graph->visited[source] = 1;
	enqueue_queue_simple(queue, source, queue_size);
	while(!is_empty(queue_size)){
		int vertex = dequeue(queue, queue_size);
		// printf("%d\n",vertex);
		queue_size--;
		adj_list *vertex_adj_list = graph->vertices[vertex];
		while(vertex_adj_list != NULL){
			// puts("hello");
			if(graph->visited[vertex_adj_list->value] == 0){
				queue_size++;
				printf("VISITANDO %d\n", vertex_adj_list->value);
				enqueue_queue_simple(queue, vertex_adj_list->value, queue_size);
				graph->visited[vertex_adj_list->value] = 1; 
			}
			vertex_adj_list = vertex_adj_list->next;
		}
	}
}

void print(adj_list *node)
{
	adj_list *aux = node;
	while(aux != NULL)
	{
		printf("%d -> ", aux -> value);
		aux = aux -> next;
	}
	puts("\n");
}

void add_edge(int v1, int v2, GRAPH *graph)
{
	adj_list *new_node = creating_node(v2);
	new_node -> next = graph -> vertices[v1];
	graph -> vertices[v1] = new_node;
}
void dfs(GRAPH *graph, int data)
{
	graph -> visited[data] = 1;
	adj_list *aux = graph -> vertices[data];
	while(aux != NULL)
	{
		if(graph -> visited[aux->value] == 0)
		{
			printf("VISITANDO %d\n",aux -> value);
			dfs(graph, aux -> value);
		}
		aux = aux -> next;
	}
}

int main()
{
	GRAPH *new_graph = creating_graph();
	add_edge(1,2, new_graph);
	add_edge(1,3, new_graph);
	add_edge(2,4, new_graph);
	add_edge(2,5, new_graph);
	add_edge(3,6, new_graph);
	add_edge(3,7, new_graph);
	int i;
	// dfs(new_graph,1);
	BFS(new_graph,1);
	for(i = 0; i < MAX_SIZE; i++)
	{
		if(new_graph -> vertices[i] != NULL)
		{
			print(new_graph -> vertices[i]);
		}
	}
	return 0;
}
