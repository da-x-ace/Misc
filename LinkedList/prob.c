#include <stdio.h>
#include <assert.h>

#define null NULL
struct node{
	int value;
	struct node* next;
};

struct node* mergeList(struct node* , struct node* );

void push(struct node** head, int data)
{
	struct node* tmp = *head;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = data;
	newNode->next = *head;
	*head = newNode;	
}

struct node* getNew(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = data;
	newNode->next = null;
	return newNode;	
}

void printList(struct node* head)
{
	struct node* current = head;
	while(current != null)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void sortedInsert(struct node** head, struct node* newNode)
{
	struct node* current = *head;
	
	if(current == null || newNode->value <= current->value)
	{
		newNode->next = current;
		*head = newNode;
		//printf("Hi \n");
		return;
	}
	while(current->next != null )//&& current->next->value<newNode->value)
	{
		if(newNode->value <= current->next->value)
		{
			break;
		}
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
	
}

void insertSort(struct node** head)
{
	struct node* result = null;
	struct node* current = *head;
	struct node* next = current->next;
	
	//sortedInsert(&result, current);
	
	while(current != null)
	{
		next = current->next;
		//current->next = null;
		sortedInsert(&result, current);
		
		current = next;
	}
	
	*head = result;
}

void append(struct node** a, struct node** b)
{
	struct node* current = *a;
	if(a == null)
	{
		*a = *b;
		return;
	}
	
	while(current->next != null)
	{
		current = current->next;
	}
	current->next = *b;
	
	*b = null;
	
}


void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef)
{
	struct node* current = source;
	struct node* slow = null;
	struct node* fast = null;
	
	if(current == null || current->next == null)
	{
		*frontRef = current;
		*backRef  = null;
		return;
	}
	slow = current;
	fast = current->next;
	
	while(fast != null)
	{
		fast = fast->next;
		while(fast != null)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = null;
}

void moveNode(struct node** source, struct node** dest)
{
	struct node* headSource = *source;
	struct node* headDest = *dest;
	if(*dest == null)
		return;
	
	headDest = headDest->next;
	(*dest)->next = headSource;
	*source = *dest;
	*dest = headDest;	
}

void AlternatingSplit(struct node* source,struct node** aRef, struct node** bRef)
{
	struct node* a = null;
	struct node* b = null;
	struct node* current = source;
	int flag = 0;
	
	if(source == null || source->next == null)
	{
		*aRef = source;
		*bRef = null;
		return;
	}
	while(current != null)
	{
		if(flag == 0)
		{
			moveNode(&a, &current);
			flag = 1;
		}
		if(flag == 1)
		{
			moveNode(&b, &current);
			flag =0;
		}
	}
	*aRef = a;
	*bRef = b;
}

struct node* ShuffleMerge(struct node* a, struct node* b)
{
	struct node* current = a;
	struct node dummy;
	struct node* tmp = &dummy;
	dummy.next = null;
	
	while(1)
	{	
		if(a == null)
		{
			tmp->next = b;
			break;						
		}
		if(b == null)
		{
			tmp->next = a;
			break;
		}
		tmp->next = a;
		a = a->next;
		tmp->next->next = null;
		tmp = tmp->next;
		tmp->next = b;
		b = b->next;
		tmp->next->next = null;
		tmp = tmp->next;
	}
	return dummy.next;
}

struct node* SortedIntersect(struct node* a, struct node* b)
{
	struct node dummy;
	struct node* tail = &dummy;
	dummy.next = null;
	
	while(1)
	{
		if(a == null || b == null)
		{
			break;
		}
		if(a->value < b->value)
		{
			a = a->next;
		}else if(a->value > b->value)
			{
				b = b->next;
			}
			else
			{
				push(&tail->next, a->value);
				tail = tail->next;
				a = a->next;
				b = b->next;
			}
	}
	return dummy.next;
}

void reverse(struct node** a)
{
	struct node* result = null;
	struct node* current = *a;
	
	while(current != null)
	{
		moveNode(&result, &current);
	}
	
	*a= result;
	
}

void recursiveReverse(struct node** a)
{
	struct node* current = *a;
	struct node* first=null;
	struct node* rest = null;
	if(*a == null)
		return;	
	
	first = current;
	rest = current->next;
	if(rest == null)
		return;
	
	recursiveReverse(&rest);
	
	first->next->next = first;
	first->next = null;
	
	*a = rest;	
}

int main(int argc, char *argv[])
{
	struct node* a = NULL;
	struct node* b = NULL;
	struct node* result = NULL;
	struct node* a1 = null;
	struct node* a2 = null;
		
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	printList(a);
	
	//sortedInsert(&a, getNew(1));
	//	printList(a);
	printf("\n");
	push(&b, 80);
	push(&b, 50);
	push(&b, 10);
	push(&b, 3);
	printList(b);
	printf("\n");
	
	//insertSort(&b);
	//printList(b);
	//result = mergeList(a,b);
	
	//append(&a, &b);
	

	
	//FrontBackSplit(b, &a1, &a2);
	//AlternatingSplit(a,&a1, &a2);
	
	//printList(a);
	
	
	//printList(a1);
	//printList(a2);
	
	//moveNode(&a, &b);
	//printList(a);
	//printList(b);
	
	//result = ShuffleMerge(a,b);
	
 //printList(result);
 	//result = SortedIntersect(a,b);
 	//printList(result);
 	//printList(a);
	//printList(b);
	
	//reverse(&b);
	
	recursiveReverse(&b);
	
	printList(b);
}
