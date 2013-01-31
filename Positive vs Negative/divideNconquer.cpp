#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

int count=0;

void swapPointers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapPointersNew(int *a, int *b, int i, int j, int *array)
{
	int temp = array[j];
	cout<<"temp ="<<temp<<endl;
	for(int k=j; k>=i;k--)
	{
		array[k]= array[k-1];
	}
	array[i] = temp;
}

void partition(int *array, int low, int high)
{
	count++;
//	if(count >5)
//		exit(0);
	int i,j;
	if(low >= high)
	{
		return;
	}
	cout<<"Low ="<<low<<" High="<<high<<endl;
	int mid = (low+high)/2;
	partition(array, low, mid);
	partition(array,mid+1, high);
	cout<<"First"<<endl;
	cout<<"Low ="<<low<<" High="<<high<<" Mid="<<mid<<endl;
	for(int i=low; i<=high;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
/*	if(array[mid+1] < 0)
	{
		j=mid+1;
	}*/
	i=low;
	j=mid+1;
	while(array[i] < 0 && i<= mid)
	{
		i++;
	}
	cout<<" i="<<i<<" j="<<j<<endl;
	while(array[j]>0 && j<=high)
	{
			j++;
	}
	cout<<" i="<<i<<" j="<<j<<endl;

	while(array[j]<0 && i<=mid)
	{
		swapPointersNew(&array[j],&array[i], i, j, array);
  		i++;
  		j++;
	}
	for(int i=0; i<=6;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main()
{
//	int *array=new int[7];
	int array[]= {-1,5,3,-8,4,-6,9};
	int num = 7;
//	int temp[7];
	partition(array, 0,6);
	for(int i=0; i<7;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
