#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;
typedef struct myList{
	int value;
	struct myList *next;
};

void initialize(myList **a, int data)
{
	myList *temp, *head;
	head = *a;
	temp = (myList *)malloc(sizeof(myList));
	temp->value = data;
	temp->next = NULL;

	if(head == NULL)
	{
		*a= temp;
	}
	else
	{
		while(head->next != NULL)
		{
			head= head->next;
		}
		head->next = temp;
	}
}

int main()
{
//	int *array=new int[7];
	int array[]= {-1,5,3,-8,4,-6,9};
	int temp[7];
	int num;
	myList *a;
	a= NULL; 
	myList *head;
	int n=7;
	for(int i=0; i<7; i++)
	{
		initialize(&a,array[i]);
/*		myList *temp;
		temp = (myList *)malloc(sizeof(myList));
		temp->value = array[i];
		temp->next = NULL;
		if(a == NULL)
		{
			a= temp;
			head = a;
		}
		else
		{
			while(a->next != NULL)
			{
				a= a->next;
			}
			a->next = temp;
			a= head;
		}
		*/
	}
	while(a->next!= NULL)
	{
		num = a->value;
		cout<<num<<" ";
		a= a->next;
	}
	cout<<endl;
}
