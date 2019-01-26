#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct NODE{
	int element;
	struct NODE *next;
}NODE;

void print_list(NODE *head)
{	
	NODE *aux = head;
	while(aux != NULL)
	{
		printf("%d ",aux -> element);
		aux = aux -> next;
	}
}

NODE *creating_node(int e)
{
	NODE *new_node = (NODE*) malloc(sizeof(NODE));
	new_node -> element = e;
	new_node -> next = NULL;
	return new_node;
}

NODE *Insert_Ordered(NODE *new_node, NODE *head)
{
	NODE *previous = NULL;
	NODE *current = head;
	NODE *aux = new_node;
	
	if(head == NULL) //Cheking if the list is empty
	{
		return new_node;
	}
	if(aux -> element <= head -> element){ // if the new element is smaller than the head, swap it.
		aux -> next = head;
		return aux;
	}
	else{//Navigating thru the list to find a bigger element than aux
		while(current -> next != NULL && aux -> element >= current -> element)
		{
			previous = current;
			current = current -> next;

		}
		if(aux -> element <= current -> element)
		{
			previous -> next = aux;
			aux -> next = current;
		}
		else{//swap with the last node
			current -> next = aux;
		}
		return head;
	}
}

int main()
{
	int e;
	scanf("%d",&e);
	NODE *head = creating_node(e);
	while(scanf("%d",&e) != EOF)
	{

		NODE *new_node = creating_node(e);
		head = Insert_Ordered(new_node, head); 
	}
	print_list(head);
	printf("\n");
	return 0;
}