#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
	int element;
	struct NODE *next;
}NODE;

void print_list(NODE *head)
{
	NODE *aux = head;
	while(aux -> next != NULL)
	{
		printf("%d -> ", aux -> element);
		aux = aux -> next;
	}	
	printf("%d\n",aux -> element);
	return;
}

NODE *creating_node(int e)
{
	NODE *new_node = (NODE*) malloc (sizeof(NODE));
	new_node -> element = e;
	new_node -> next = NULL;
	return new_node;
}

NODE *add_beginning(NODE *head, int e)
{
	NODE *new_node = creating_node(e);
	new_node -> next = head;
	return new_node;
}

void add_end(int e, NODE *head)
{
	NODE *new_node = creating_node(e);	
	NODE *aux = head;
	while(aux -> next != NULL)
	{
		aux = aux -> next;
	}
	aux -> next = new_node;
}

int main()
{	
	int n, i, e;
	scanf("%d %d", &n, &e);
	NODE *head = creating_node(e);
	for(i = 0; i < n - 1; i++)
	{
		scanf("%d", &e);
		// head = add_beginning(head, e);
		add_end(e,head);
	}

	print_list(head);
	return 0;
}
