#include<iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
	
int findMajority(int *array, int n)
{
	int index = 0;
	int count =1;
	int finalCount=0;
	for(int i=1; i<n ; i++)
	{
		if(array[index] != array[i])
			count--;
		else
			count++;
		if(count == 0)
		{
			index= i;
			count = 1;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(array[index] == array[i])
			finalCount++;
	}
	if(finalCount > n/2)
	{
		cout<<"YES "<<array[index]<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	unsigned long long int n;
	int *array;
	for(int i=0; i<t; i++)
	{
		cin>>n;
		array = new int[n];
		for(int j=0; j<n; j++)
		{
			scanf("%d",&array[j]);
		}
		findMajority(array, n);
	}
}
