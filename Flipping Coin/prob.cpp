#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

long *state;
bool *update;

/*
int main()
{
	int n,t;
	int choice,start,end, sum;
	cin>>n>>t;
	state = new int[n];
	for(int i=0; i<n; i++)
	{
		state[i]=0;
	}
	for(int i=0; i<t; i++)
	{
		sum =0;
		cin>>choice>>start>>end;
		if(choice ==0)
		{
			for(int j=start; j<= end; j++)
			{
				if(state[j] == 0)
					state[j]=1;
				else
					state[j]=0;

//				state[j]++;
			}
				
		}
		else
		{
			for(int j=start; j<= end; j++)
			{
				sum = sum+(state[j]%2);
			}
			cout<<sum<<endl;
		}
	}
}*/

long count(long node, long b, long e, long start, long end)
{
	if(start>e || end<b)
		return 0;
	if(b>= start && e<= end)
	{
		if(update[node])
		{
			return end-start+1;
		}
		else
		{
			return 0;
		}
	}
	return count(2*node,b,(b+e)/2,start,end)+ count((2*node)+1,((b+e)/2)+1,e,start,end);
}

void flip(long node, long b, long e, long start, long end)
{
	if(start>e || end < b)
		return;
	if(b>= start && e<= end)
	{
		update[node] ^=1;
		return;
	}
	flip(2*node, b, (b+e)/2, start, end);
	flip((2*node)+1,((b+e)/2)+1, e, start, end);
}


int main()
{
	long n,t;
	cin>>n>>t;
	long choice, start, end;
	state = new long[n];
	update = new bool[n];
	for(int i=0; i<t; i++)
	{
		cin>>choice>>start>>end;
		if(choice)
		{
			cout<<count(1, 0, n-1, start, end)<<endl;
		}
		else
		{
			flip(1,0,n-1, start, end);
		}
	}
}


