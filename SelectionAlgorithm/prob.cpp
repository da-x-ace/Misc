#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <string>
#include <stdlib.h>

using namespace std;

void swapPointers(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int* arr, int low, int high, int index)
{
	int start, end;
	if(low > high)
		return -1;
	swapPointers(&arr[low], &arr[index]);
	start = low+1;
	end = high;
	//cout<<"1"<<endl;
	while(start <= end)
	{
		while(high >= start && arr[start] <= arr[low])
		{
			start++;
		}
		while(end >= low && arr[end] > arr[low])
			end--;
		//cout<<"Start :"<<start<<"end: "<<end<<endl;
		if(start <= end)
		{
			swapPointers(&arr[start], &arr[end]);
			start++;
			end--;
		}
	}
	//cout<<end<<endl;
	if(end != -1)
	{
		swapPointers(&arr[low], &arr[end]);
	}
	return end;
}

int selectionAlgorithm(int* arr, int low, int high, int index)
{
	int pivot = arr[index];
	int pivotIndex;
	//cout<<pivot<<endl;
	pivotIndex = partition(arr, low, high, index);
	cout<<"pivotIndex:"<<pivotIndex<<endl;
	for(int i=0; i<=high; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	if(pivotIndex == index)
		return arr[index];
	if(pivotIndex < index)
		selectionAlgorithm(arr, pivotIndex+1, high, index);
	else
		selectionAlgorithm(arr, low, pivotIndex-1, index);
}

int main()
{
	int n = 10;
	int* arr;
	//int* arr = (int*) malloc(sizeof(int)*n);
	int arr1[] = {1,4,8,5,2,9,6,7,3,10};
	arr = arr1;
	int pivot = selectionAlgorithm(arr, 0, n-1, 2); 
	cout<<pivot<<endl;	
}
