#include <stdio.h>


struct node{
	int value;
	struct node* next;
};

void insertNode(struct node** head, int myvalue)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->value = myvalue;
	newNode->next = *head;
	
	*head = newNode;
	
}

void printList(struct node *list)
{
	while(list != NULL)
	{
		printf("%d ",list->value);
		list = list->next;
	}
}

struct node* mergeList(struct node* a, struct node* b)
{
	struct node* result = NULL;
	
	if(a == NULL)
		return b;
	else if (b == NULL)
		return a;
	
	if(a->value <= b->value)
	{
		result = a;
		result->next = mergeList(a->next, b);
	}
	else
	{
		result = b;
		result->next = mergeList(a, b->next);
	}
	return result;
}


int main(int argc, char *argv[])
{
	struct node* a = NULL;
	struct node* b = NULL;
	struct node* result = NULL;
	
	insertNode(&a, 15);
	insertNode(&a, 10);
	insertNode(&a, 5);
	printList(a);
	printf("\n");
	insertNode(&b, 20);
	insertNode(&b, 10);
	insertNode(&b, 8);
	printList(b);
	printf("\n");
	
	result = mergeList(a,b);
	printList(result);
	printf("\n");
}
