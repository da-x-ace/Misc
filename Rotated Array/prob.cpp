#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <string>
#include <stdlib.h>

using namespace std;


int findPivotIndex(int arr[], int low, int high)
{
	int mid = (low+high)/2;
	
	if(low > high)
		return -1;
	if(arr[mid] > arr[mid+1])
		return mid;
	
	if(arr[low] < arr[mid])
	{
		findPivotIndex(arr, mid+1, high);
	}
	else
	{
		findPivotIndex(arr, low, mid-1);
	}
}

int binarySearch(int arr[], int low, int high, int num)
{
	int mid = (low+high)/2;
	
	if(arr[mid] == num)
		return mid;
	if(arr[mid] > num)
		return binarySearch(arr, 0, mid-1, num);
	else
		return binarySearch(arr, mid+1, high, num); 	
}

int pivotedBinarySearch(int arr[], int size, int num)
{
	int pivotIndex = findPivotIndex(arr, 0, size-1);
	
	int pivot = arr[pivotIndex];
	
	cout<<"Pivot element = "<<pivot<<endl;
	
	if(pivot == num)
		return pivotIndex;
	if(num < pivot && num >= arr[0])
	{
		return binarySearch(arr, 0, pivotIndex-1, num);
	}
	else
	{
		return binarySearch(arr, pivotIndex+1,size-1, num);
	}
}


int main()
{
	int arr[10] = {3, 4, 5, 6, 7, 1, 2};
   int n = 5;
   printf("Index of the element is %d", pivotedBinarySearch(arr, 7, 3)); 
   return 0;	
}
