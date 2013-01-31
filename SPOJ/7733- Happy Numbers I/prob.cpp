#include<iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
	
typedef struct myBst{
	int value;
	struct myBst *left;
	struct myBst *right;	
};

int insertNode(myBst *node, myBst *temp)
{
	int check = 1;
//	myBst *temp = root;
	if(node->value < temp->value)
	{
		if(temp->left == NULL)
		{
			temp->left = node;
		}
		else
		{
			check = insertNode(node, temp->left);
		}
	}
	if(node->value > temp->value)
	{
		if(temp->right == NULL)
		{
			temp->right = node;
		}
		else
		{
			check = insertNode(node, temp->right);
		}
	}
	if(node->value == temp->value)
	{
		check = -1;
		return check;
	}
	return check;
}

	
int main()
{
	unsigned long long int num;
	int check =0;
	bool flag = true;
	unsigned long long int count = 0;
	unsigned long long int single=0;
	unsigned long long int sum =0;
	myBst *root= NULL, *temp=NULL;
//	while(1)
	{
		count =0;
		cin>>num;
		while(flag)
		{
			//Calculating the sum
			sum = 0;
			while(num/10 > 0)
			{
				single = num%10;
				sum = sum+(single*single);
				num=num/10;
			}
			sum = sum+num*num;
			
			//entring into bst
			myBst *newNode = (myBst *)malloc(sizeof(myBst));
			newNode->value = sum;
			newNode->left = NULL;
			newNode->right = NULL;
			
			if(root == NULL)
			{
				root = newNode;
				temp = root;
			}
			else
			{
				check = insertNode(newNode, temp);
			}
			
			if(check == -1)
			{
				cout<<"-1"<<endl;
				break;
			}
			
			//preparing for next iteration
			count++;
			num = sum;
			if(num == 1)
			{
				cout<<count<<endl;
				break;
			}
		}
	}
}



