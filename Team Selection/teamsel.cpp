#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<cstring>

using namespace std;

FILE *ifp = fopen("input.txt","r");
//FILE *ifp = stdin;



void clearArray(int *a)
{
	for(int i=0; i<451;i++)
	{
		a[i]=0;
	}	
}

int main()
{
	int t,n,num;
	
	int *array = new int[451];
	fscanf(ifp,"%d",&t);
	
	clearArray(array);
	
	for(int i=0; i<t;i++)
	{
		fscanf(ifp,"%d",&n);
		for(int j=0;j<n; j++)
		{
			fscanf(ifp, "%d", &num);
			cout<<num<<endl;
			array[num]++;
		}
		clearArray(array);
	}
		
	system("Pause");
	return 0;
}
