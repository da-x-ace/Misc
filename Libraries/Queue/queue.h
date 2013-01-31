typedef struct queue Queue;
	
struct queue{
	void* value;
	struct queue* next;
};

struct queue* newElement(void* value)
{
	struct queue* newNode= (struct queue*)malloc(sizeof(struct queue));
	newNode->value = value;
	newNode->next = NULL;
}

void enqueue(struct queue** head, void* value)
{
	struct queue* temp =NULL;
	struct queue* iterator = *head;
	if(*head == NULL )
	{
		*head = newElement(value);
	//	*tail = *head;
	}
	else
	{
		temp = newElement(value);
		while(iterator->next)
		{
			iterator = iterator->next;
		}
		iterator->next = temp;
		//*tail = temp;
	}
}


struct queue* dequeue(struct queue** head)
{
	struct queue* temp = NULL;
	if(*head == NULL)
	{
		return NULL;
	}
	else
	{
		temp = *head;
		*head = (*head)->next;
		return temp;
	}
}


