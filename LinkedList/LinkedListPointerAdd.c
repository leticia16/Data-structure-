#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int element;
	struct NODE *next;
}NODE;

void print_list(NODE *head)
{
	NODE *aux = head;
	while(aux -> next != NULL)
	{
		printf("%d -> ",aux -> element);
		aux = aux -> next;
	}
	printf("%d\n",aux -> element);
	return;
}

NODE *creating_node(int e)
{
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	new_node -> element = e;
	new_node -> next = NULL;
	return new_node;
}

NODE *add_beginning(int e, NODE *head)
{
	NODE *new_node = creating_node(e);
	new_node -> next = head;
	return new_node;
}

NODE *add_end(int e, NODE *head)
{
	NODE *new_node = creating_node(e);
	NODE *aux = head;
	while(aux -> next != NULL)
	{
		aux = aux -> next;
	}
	aux -> next = new_node;
	return head;
}

 void get_list(int n, NODE *(*f)(int e, NODE *head))
{
	int e, i;
	scanf("%d", &e);
	NODE *head = creating_node(e);
	for(i = 0; i < n-1; i++)
	{
		scanf("%d", &e);
		head = (*f)(e, head);
	}
	print_list(head);
	return;
}

int main()
{	
	int n;
	scanf("%d", &n);
	NODE *head;
	get_list(n, add_beginning);
	get_list(n, add_end);
	return 0;
}

//  try this enter case:
//  5
//  1 2 3 4 5 6
//  1 2 3 4 5 6
