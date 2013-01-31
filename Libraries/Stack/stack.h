typedef struct stack Stack;
	
struct stack{
	void* value;
	struct stack* next;
};

struct stack* newElement(void* value)
{
	struct stack* newNode= (struct stack*)malloc(sizeof(struct stack));
	newNode->value = value;
	newNode->next = NULL;
}

void push(struct stack** head, void* value)
{
	struct stack* temp =NULL;
	if(*head == NULL)
	{
		*head = newElement(value);
	}
	else
	{
		temp = newElement(value);
		temp->next = *head;
		*head = temp;
	}
}


struct stack* pop(struct stack** head)
{
	struct stack* temp = NULL;
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


