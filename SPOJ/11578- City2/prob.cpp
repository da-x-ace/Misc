#include<iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
	
FILE* ifp = fopen("INPUT.txt","r");
//FILE* ifp = stdin;	

int main()
{
	unsigned int n;
	unsigned int count;
	unsigned long long int *array;
	bool flag ;
	unsigned int caseNum=0;
	
	while(fscanf(ifp,"%d",&n) != -1)
	{
//		printf("%d",fscanf(ifp,"%d",&n));
		caseNum++;
		flag = false;
		count =0;
		array = new unsigned long long int[n];
		for(int i=0; i<n; i++)
		{
			fscanf(ifp,"%lld",&array[i]);
//			scanf("%lld",&array[i]);
		}
		for(int i=0; i<n; i++)
		{
			flag = false;
			for(int j=i+1; j< n; j++)
			{
				if( array[i] == 0)
				{
					flag = false;
					break;
				}
				if(array[j] == 0)
				{
					flag = true;
					break;
				}
				if(array[i]> array[j])
				{
					flag= true;
					break;
				}
				if(array[i] == array[j])
				{
					flag = false;
					break;
				}
				if(array[i] < array[j])
				{
					flag = true;
				}
			}
			if(i == n-1 && array[i]!=0)
				flag = true;
			if(flag)
				count++;
		}
		
		cout<<"Case "<<caseNum<<": "<<count<<endl;
//		if(caseNum == 9)
//			break;
	}
	
	
/*	for(int i=0; i<n; i++)
	{
		cout<<array[i]<< " ";
	}
	cout<<endl;
*/	
}
