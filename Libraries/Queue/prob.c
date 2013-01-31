#include<stdio.h>
#include <stdlib.h>
#include "queue.h"

void printQueue(Queue *head)
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
	Queue* myNode = newElement((void *)5);
	Queue* head = NULL;
	Queue* temp = NULL;
	
	char c='a';
	enqueue(&head,(void *)5);
	printQueue(head);
	enqueue(&head,(void *)c);
	printQueue(head);
	enqueue(&head,(void *)12);
	printQueue(head);
	temp = dequeue(&head);
	printQueue(head);
	printf("Dequed element is : %d\n", (int)temp->value);
	temp = dequeue(&head);
	printQueue(head);
	
}
