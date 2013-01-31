#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int n,q;
	int flag=0;
	cin>>n;
	char **recipe = new char*[n];
	int *weight = new int[n];
	for(int i=0; i<n;i++)
	{
		recipe[i]= new char[1000];
		cin>>recipe[i]>>weight[i];
	}
	cin>>q;
	char **query = new char*[q];
	for(int i=0; i<q;i++)
	{
		query[i]=new char[1000];
		cin>>query[i];
	}
	char *result = new char[1000];
	int result_weight =-1000000000;
	
	for(int i=0; i<q;i++)
	{
		result_weight =-1000000000;
		result = NULL;
		for(int k=0; k<n; k++)
		{
			flag = 0;
			for(int j=0; j<strlen(query[i]);j++)
			{
				if(recipe[k][j] == query[i][j])
				{
					flag = 1;
				}
				else
				{
					flag =0;
					break;
				}
			}
			if(flag == 1 && (result_weight < weight[k]))
			{
				result = recipe[k];
				result_weight = weight[k];
			}
		}
		if(result == NULL)
			result = "NO";
		cout<<result<<endl;
	}
}
