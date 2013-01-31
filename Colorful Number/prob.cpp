#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <map>

using namespace std;

map <int, int> myMap;

void calcProd(int* array, int index, int length)
{
	int prod=1;
	
	//cout<<"Index = "<<index<<endl;
	
	for(int i=index; i<length; i++)
	{
			prod = prod*array[i];
			if(myMap.find(prod) != myMap.end())
			{
				cout<<"Not a colourful Number"<<endl;
				exit(0);
			}
			else
			{
				myMap[prod] = prod;	
			}
			//cout<<"Product is : "<<prod<<endl;
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	int len=0;
	int temp = num;
	while(temp>0)
	{
		len++;
		temp = temp/10;	
	}
	int* array= (int*)malloc(sizeof(int)*len);
	memset(array, 0, len);
//	cout<<"Length of the input number is ="<<len<<endl;
	for(int i=len-1, temp = num; i>=0; i--)
	{
			array[i]=temp%10;
			temp/=10;
	}
	
	for(int i = len-1; i>=0; i--)
	{
		calcProd(array, i, len);	
	}
	printf("Colourful Number\n");
	
}
