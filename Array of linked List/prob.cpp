#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

struct node{
	char *str;
	struct node* next;
};

int main()
{
	int n = 5;
	struct node** myArrayList = (struct node**) malloc(sizeof(struct node*)*n);
	struct node* newNode = (struct node *)malloc(sizeof(struct node));
	char *temp = (char *)malloc(10);
	memcpy(temp,"Hi This \0",10);
	newNode->str = temp;
	newNode->next = NULL;
 	//(*myArrayList)->str = (void *)newNode;
 	//(*myArrayList)->next = NULL;
 	myArrayList[0] = newNode;
 	cout<<myArrayList[0]->str<<endl;
}
