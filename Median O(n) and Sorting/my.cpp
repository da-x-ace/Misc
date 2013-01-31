#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

int n=497;
int num=n;
int *less = new int[num];
int *greater = new int[num];
int *equal = new int[num];

void swapPointers(int *a, int*b)
{
	int temp=*a;
	*a = *b;
	*b= temp;
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


int medianAlgorithm(int *array, int low, int high, int k)
{
	int length= high-low+1;
//	cout<<" Length :"<<length<<" K:"<<k<<endl;
	if(length<=10)
	{
		quicksort(array, low, high);
		return array[low+k-1];
	}
	int numMedians= length/5;
	int *medians = new int[numMedians];
	for(int i=0,j=0; i<numMedians; i++, j=j+5)
	{
		medians[i] = medianAlgorithm(array, j, j+4, 3);
	}
//	for(int i=0; i<numMedians; i++)
	{
//		cout<<medians[i]<<" ";
	}
//	cout<<endl;
	int mm = medianAlgorithm(medians, 0, numMedians-1, (numMedians/2)+1);
//	cout<<"Median of medians :"<<mm<<" "<<numMedians<<endl;
	int count =0, lessNum=0, equalNum =0, greaterNum=0;
	
//	int *myless = new int[lessNum];
//	int *mygreater = new int[equalNum];
//	int *myequal = new int[greaterNum];
	
	while(count < length)
	{
		if(array[count] < mm)
		{
			less[lessNum++] = array[count++];
		}
		else if(array[count] == mm)
			{
				equal[equalNum++] = array[count++];
			}
			else
			{
				greater[greaterNum++] = array[count++];
			}
	}
/*	count=0;
	while(count< lessNum)
	{
		cout<<less[count++]<<" ";
	}
	cout<<endl;
	count=0;
	while(count< equalNum)
	{
		cout<<equal[count++]<<" ";
	}
	cout<<endl;
	count=0;
	while(count< greaterNum)
	{
		cout<<greater[count++]<<" ";
	}
	cout<<endl;
*/
	if(k <= lessNum)
	{
		return medianAlgorithm(less, 0, lessNum-1, k);
	}
	else if(k > (lessNum+equalNum))
		{
			return medianAlgorithm(greater, 0, greaterNum-1, k-lessNum-equalNum);
		}
		else
		{
			return mm;
		}
	
}


int main()
{
	
	int k;

	int *array = new int[n];
	int *array_back = new int[n];
	for(int i=0; i<n; i++)
	{
		array[i]=rand()%1000+1;
	}
	for(int i=0; i<n; i++)
	{
		array_back[i]=array[i];
//		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	cout<<"Median Index:"<<n/2<<endl;
	
//	int partitionvalue = partition(array, 0 , n-1, 50);
	int myMedian = medianAlgorithm(array, 0, n-1, (n/2)+1);
	cout<<"Median "<<myMedian<<endl;
	//check answer through sorting

//	quicksort(array_back, 0, n-1);
//	mergeSort(array_back, 0, n-1);
	doInsertionSort(array_back, 0, n-1);
//	for(int i=0; i<n; i++)
	{
//		cout<<array_back[i]<<" ";
	}
//	cout<<endl;
//	cout<<endl;
	cout<<"Median :"<<array_back[n/2]<<endl;
	
	
}
