#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;


int partition(int *array, int elementIndex, int start, int end)
{
	int temp;
//	cout<<array[elementIndex]<<endl;
	temp = array[elementIndex];
	array[elementIndex] = array[start];
	array[start]=temp;
//	cout<<array[elementIndex]<<endl;
	int low = start+1;
	int high = end;
	while(low<=high)
	{
		while( low<=end && array[low]<=array[start])
			low++;
		while( high>=start && array[high]>array[start])
			high--;
		if(low < high)
		{
			temp=array[low];
			array[low]=array[high];
			array[high]=temp;
			low++;
			high--;
		}
	}
	if(high != -1)
	{
		temp=array[start];
		array[start]=array[high];
		array[high]=temp;
	}
	
/*	for(int i=0; i<20; i++)
		{
			cout<<array[i]<<" ";
		}
		cout<<endl;
*/		
	if(high != -1)
		return high;
	else
		return high+1;
}

int findKthLargestElement(int *array, int k, int start, int end)
{
//	cout<<"k needed:"<<k<<endl;
	if(start >= end)
		return array[end];
		
	int elementIndex = (start+end)/2;
	int index, rank; 
//	cout<<elementIndex<<" "<<start<<" "<<end<<endl;
	index = partition(array, elementIndex, start, end);
//	cout<<index<<endl;
	rank = index-start+1;
//	cout<<"rank :"<<rank<<endl;
	if(rank == k)
		return array[index];
	else if(k < rank)
		return findKthLargestElement(array, k, start, index-1);
		else
			return findKthLargestElement(array, k-rank, index+1, end);
}

int main()
{
	int n=497;
	int k;
	int *array = new int[n];
	for(int i=0; i<n; i++)
	{
		array[i]=rand()%1000+1;
	}
	for(int i=0; i<n; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
//	while(true)
	{
		cin>>k;
	//	k = n-k;
		int start =0;
		int end = n-1;
		int pos;
		pos = findKthLargestElement(array, k, start, end);
		
/*		for(int i=0; i<n; i++)
		{
			cout<<array[i]<<" ";
		}
*/
		cout<<endl<<pos<<endl;

	}
		
	
}
