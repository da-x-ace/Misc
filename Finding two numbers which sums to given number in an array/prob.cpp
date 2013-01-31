#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

void findPair(int *array, int sum, int length)
{
	bool* myHash = new bool[length];
	for(int i=0; i<length; i++)
	{
		myHash[i]=0;
	}
	int temp=0;
	
	for(int i=0; i<length; i++)
	{
		temp = sum-array[i];
		if(temp > 0 && myHash[temp] == 1)
			cout<<"The two numbers are: "<<temp<<"+"<<array[i]<<endl;
		myHash[array[i]]=1;
	}
}


int main(int argc, char* argv[])
{
	int arr[] = {23,8, 10, 45, 57, 2, 18, 4};
	int n = 23;
	
	int length = sizeof(arr)/4;
	cout<<length<<endl;
	
	findPair(arr, n, length);
}
