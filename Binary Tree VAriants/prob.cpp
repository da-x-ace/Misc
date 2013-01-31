#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

struct node{
	char c;
	struct node* left;
	struct node* right;
};

struct node* newNode(char c)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->c = c;
	temp->left = NULL;
	temp->right = NULL;
}

int main()
{
	char *input = new char[1024];
	input = "abc#def#g##h";
	int length = strlen(input);
	cout<<length<<endl;
	
	char queue[length];
	int queueIndex = 0;
	int top = 0;
	
	struct node* root=NULL;
	struct node* parent;
	struct node* temp=NULL;
	struct node* newValue= NULL;
	
	int index=0;
	//root = newNode(input[index]);
	
	if(input[index] == '#')
	{
		cout<<"Input format is wrong\n"<<endl;
		exit(0);
	}
	
	int count = 0;
	while(count <= length)
	{
		if(count == 0)
		{
			queue[queueIndex++] = input[index];
			top = queueIndex;
			root = newNode(input[index]);
			temp = root;
			index++;
			top++;
		}
		if(count == 1 && input[index]=='#')
			break;
		
		if(input[index]!= '#')
		{
			if(temp->left == NULL)
			{
				newValue = newNode(input[index]);
				temp->left = newValue;
				queue[queueIndex++] = input[index];
				index++;
			}
			else
			{
				newValue = newNode(input[index]);
				temp->right = newValue;
				queue[queueIndex++] = input[index];
				index++;
			}
		}
		
	}
	
	
}
