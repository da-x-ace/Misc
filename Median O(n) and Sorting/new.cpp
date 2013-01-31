#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

int count = 0;

void swapPointers(int *a, int *b)
{
	int temp = *a;
	*a= *b;
	*b = temp;
}

int partition(int *array, int pivot, int start, int end)
{
	int temp;
	int low = start;
	int high = end;
	while(low<=high)
	{
		while( low<=end && array[low]<=pivot)
			low++;
		while( high>=start && array[high]>pivot)
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
		return high;
	else
		return high+1;
}


int partitionBasedOnElement(int *array, int low, int high, int pivot)
{
	cout<<"Low : "<<low<<" High "<<high<<" Pivot "<<pivot<<endl;
	int swapIndex=low;
	int length = high-low+1;
	for(int i=low; i<high+1; i++)
	{
		if(array[i]< pivot)
		{
			swapPointers(&array[i], &array[swapIndex]);
			swapIndex++;
		}
	}
	return swapIndex-1;
}




void quickSort(int *array, int low, int high)
{
	if(low >= high)
	{
		return;
	}
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
	quickSort(array, low, end-1);
	quickSort(array, end+1, high);
	
}

int myMedian(int *array,int low, int high, int k)
{
//	if(count > 30)
//		exit(0);
//	count++;
	int length = high-low+1;
	cout<<"Low "<<low<<" High "<<high<<" Length "<<length<<" k "<<k<<endl;
	if(length <= 5)
	{
		quickSort(array, low, high);
		return array[low+k-1];
	}
	int numMedians = length/5;
	cout<<"NumMedians : "<<numMedians<<endl;
	int *medians = new int[numMedians];
	for(int i=0; i<numMedians; i++)
	{
		medians[i]= myMedian(array, low+(i*5),low+((i+1)*5)-1, 3);
	}

	for(int i=0; i<numMedians; i++)
	{
		cout<<medians[i]<<" ";
	}
	cout<<endl;

	int pivot = myMedian(medians, 0, numMedians-1, numMedians/2+1);
	cout<<"Pivot "<<pivot<<endl;
	int pivotIndex = partitionBasedOnElement(array, low, high, pivot);
//	int pivotIndex = partition(array, pivot, low, high);
	cout<<"Pivot index of "<<pivot<<" is "<<pivotIndex<<endl;
	int rank = pivotIndex - low +1;
	cout<<"rank :"<<rank<<" k: "<<k<<endl;
	if(k <= rank)
	{
		return myMedian(array, low, pivotIndex, k);
	}
	else //if(k> rank)
		{
			return myMedian(array, pivotIndex+1, high, k-rank);
		}
		//else
		{
		//	return pivot;
		}
}

int main()
{
	
	int k;
	int n = 49789;
	int *array = new int[n];
	int *array_back = new int[n];
	for(int i=0; i<n; i++)
	{
		array[i]=rand()%1000+1;
	}
	for(int i=0; i<n; i++)
	{
		array_back[i]=array[i];
	}
/*	for(int i=0; i<n; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
*/	
	cout<<"Median Index:"<<n/2<<endl;
	
	int result = myMedian(array,0, n-1, (n/2));
	cout<<result<<endl;	
	
	quickSort(array_back, 0, n-1);

/*	for(int i=0; i<n; i++)
	{
		cout<<array_back[i]<<" ";
	}

	cout<<endl;
*/	
	cout<<"Median :"<<array_back[n/2-1]<<endl;
	
	
}
