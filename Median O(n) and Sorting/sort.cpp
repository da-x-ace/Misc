#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

int n=326;

void swapPointers(int *a, int*b)
{
	int temp=*a;
	*a = *b;
	*b= temp;
}

void quicksort(int *array, int low, int high)
{
	if(low >= high)
		return;
	
	int pivotIndex = (low+high)/2;
	int pivotElement = array[pivotIndex];
	swapPointers(&array[low], &array[pivotIndex]);
	int start = low+1;
	int end = high;
	while(start <= end)
	{
		while((start <= high)&& (array[start] <= pivotElement))
			start++;
		while((end >= low) && (array[end] > pivotElement))
			end--;
		if(start < end)
		{
			swapPointers(&array[start], &array[end]);
			start++;
			end--;	
		}
	}
	if(end != -1)
	{
		swapPointers(&array[low], &array[end]);
	}
	quicksort(array, low, end-1);
	quicksort(array, end+1, high);
}

void merge(int *array, int start, int mid, int end)
{
	int secondStart;
	int *helper = new int[n];
	int low = start;
	int back_start = start;
	int back_end = end;
	int high = end;
	
	secondStart = mid+1;

	while(start <= mid && secondStart <= end)
	{
		if(array[start] <= array[secondStart])
		{
			helper[low++]=array[start++];
			//start++;
		}
		else
		{
//			temp = array[secondStart];
//			swapPointers(&array[start], &array[secondStart]);
//			secondStart++;	
			helper[low++]=array[secondStart++];
		}
	}
	while(start <= mid)
	{
		helper[low++]=array[start++];
	}
	while(secondStart <= end)
	{
		helper[low++]=array[secondStart++];
	}
	for(int i=back_start; i<=back_end; i++)
	{
		array[i]=helper[i];
	}
}

void mergeSort(int *array, int low, int high)
{
	if(low >= high)
		return;
	int pivotIndex = (low+high)/2;
	int pivotElement = array[pivotIndex];
	mergeSort(array, low, pivotIndex);
	mergeSort(array, pivotIndex+1, high);
	merge(array, low, pivotIndex, high);
}

void doInsertionSort(int *array, int low, int high)
{
	int key,i;
	for(int j=low+1; j<=high; j++)
	{
		key = array[j];
		i=j-1;
		while(i>=low && array[i]> key)
		{
			array[i+1]=array[i];
			i--;
		}
		array[i+1]=key;
	}
}

void sort(int *array, int choice, int n)
{
	if (choice == 1)
	{
		quicksort(array,0,n); 
	}
	if(choice == 2)
	{
		mergeSort(array, 0, n);
	}
	if(choice == 3)
	{
		doInsertionSort(array,0,n);
	}
}

int main()
{
	
	int k;
	int *array = new int[n];
	int *array_back = new int[n];
	for(int i=0; i<n; i++)
	{
		array[i]=rand()%10000+1;
	}
	for(int i=0; i<n; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	cout<<"Median Index:"<<n/2<<endl;
	
//	int partitionvalue = partition(array, 0 , n-1, 50);
	
	
	//check answer through sorting
	int choice = 1;
	sort(array, choice, n-1);

	cout<<endl;
	cout<<"Median :"<<array_back[n/2]<<endl;
	
	
}
