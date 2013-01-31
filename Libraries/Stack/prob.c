#include<stdio.h>
#include <stdlib.h>
#include "stack.h"

void printStack(Stack *head)
{
	while(head)
	{
		printf("%d ",(int)head->value);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	Stack* myNode = newElement((void *)5);
	Stack* head = NULL;
	Stack* temp = NULL;
	
	char c='a';
	push(&head,(void *)5);
	printStack(head);
	push(&head,(void *)c);
	printStack(head);
	temp = pop(&head);
	//printf("%c\n", (char)temp->value);
	temp = pop(&head);
	printStack(head);
	
}
