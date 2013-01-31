#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <string>
#include <stdlib.h>

using namespace std;

int LEFT(int i)
{
	return 2*i;
}

int RIGHT(int i)
{
	return 2*i+1;
}

void swapPointers(int *a, int *b)
{
	int temp= *a;
	*a = *b;
	*b = temp;	
}

void minHeapify(int *array, int i, int length)
{
	int j=0;
	int l = LEFT(i);
	int r = RIGHT(i);
	int smallest;
	if((l<= length && l>0) && (array[l] < array[i]))
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	if((r<= length && r>0) && (array[r] < array[smallest]))
	{
		smallest = r;
	}
	if(smallest != i)
	{
		swapPointers(&array[i], &array[smallest]);
		for(j=1; j<=length;j++)
		{
			cout<<array[j]<<" ";
		}
		cout<<endl;
		minHeapify(array, smallest, length);
	}
}

void buildMinHeap(int *array, int length)
{
	for(int i=(length/2); i>0; i--)
	{
		minHeapify(array,i, length);
	}
}

int main()
{
	int k;
	cin>>k;
	int *array= new int[k];
	
	for(int i=1; i<=k; i++)
	{
		array[i]=rand()%100+1;
	}
	for(int i=1; i<=k;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	buildMinHeap(array, k);
	for(int i=1; i<=k;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	int newElement;
	while(1)
	{
		cin>>newElement;
		if(newElement > array[1])
		{
			array[1]=newElement;
			minHeapify(array,1,k);
		}
		for(int i=1; i<=k;i++)
		{
			cout<<array[i]<<" ";
		}
		cout<<endl;
	}
	
}
