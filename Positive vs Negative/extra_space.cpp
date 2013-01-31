#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

void swapPointers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
//	int *array=new int[7];
	int array[]= {-1,5,3,-8,4,-6,9};
	int temp[7];
/*	int i=0, j=6;
	while(i<j)
	{
		while(array[i]>=0)
			i++;
		while(array[j] < 0)
			j--;
		if(i<=6 && j>=0)
		{
			swapPointers(&array[i], &array[j]);
			i++;
			j--;
		}
	}
*/
	int i=0, j=0, k=0;
	for(;i<7;)
	{
		if(array[i]<0)
		{
			array[j++]=array[i++];
		}
		else
		{
			temp[k++]=array[i++];
		}
	}
	k=0;
	while(j<7)
	{
		array[j++]=temp[k++];
	}
	for(int i=0; i<7; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
