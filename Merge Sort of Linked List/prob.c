#include <stdio.h>
#include <assert.h>

#define null NULL
struct node{
	int value;
	struct node* next;
};

struct node* mergeList(struct node* , struct node* );

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

void splitList(struct node* head, struct node** a, struct node** b)
{
	struct node* slow;
	struct node* fast;
	
	if(head == null || head->next == null)
	{
		*a = head;
		*b = null;
		return;
	}
	
	slow = head;
	fast = head->next;
	
	while(fast != null)
	{
		fast = fast->next;
		while(fast != null)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	*a = head;
	*b = slow->next;
	slow->next = null;
	
}

void mergeSort(struct node** head)
{
	struct node* tmp = *head;
	struct node* a = null;
	struct node* b = null;
	
	if(tmp == null || tmp->next == null)
		return;
	
	splitList(tmp, &a,&b);
	
	mergeSort(&a);
	mergeSort(&b);
	
	*head = mergeList(a, b);
		
}


struct node* mergeList(struct node* a, struct node* b)
{
	struct node* result = (struct node*) malloc(sizeof(struct node));
	struct node* tmp = NULL;
	struct node* finalList = result;
	
	while(1)
	{
		if(a == null)
		{
			result->next = b;
			break;
		}
		if(b == null)
		{
			result->next = a;
			break;
		}
		if(a->value <= b->value)
		{
			tmp = a;
			result->next = tmp;
			a = a->next;
			tmp->next = null;
		}else
		{
			tmp = b;
			result->next = tmp;
			b = b->next;
			tmp->next = null;
		}
		result = result->next;
	}
	return finalList->next;
}


int main(int argc, char *argv[])
{
	struct node* a = NULL;
	struct node* b = NULL;
	struct node* result = NULL;
	
	insertNode(&a, 15);
	insertNode(&a, 1);
	insertNode(&a, 5);
	printList(a);
	printf("\n");
	insertNode(&b, 20);
	insertNode(&b, 10);
	insertNode(&b, 8);
	printList(b);
	printf("\n");
	
	//result = mergeList(a,b);
	
	mergeSort(&a);
	
	printList(a);
	printf("\n");
}
