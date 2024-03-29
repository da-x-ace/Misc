#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

int countTotal(long, long *, long *, long, long, long);
void sort(long *, long, long);

void swapPointers(long *x, long *y)
{
	long temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	long m,k,t,n,q;
	long flag=0;
	long *first= NULL;
	long *rest = NULL;
	cin>>t;
	long result;
	for(long i=0; i<t; i++)
	{
		cin>>m>>n>>k;
		if(n > m)
			n = m;
		first = new long[m];
		rest = new long[m];
		for(long j=0; j< m; j++)
		{
			cin>>first[j];
		}
		for(long j=0; j< m; j++)
		{
			cin>>rest[j];
		}
		long high=0, low=0, mid=0, temp;
		long sum=0;
		high = first[0]+ (k-1)*rest[0];
		for (long i=1; i<m; i++)
		{
			temp = first[i]+ (k-1)*rest[i];
			if(high > temp)
				high = temp;
		}
		while(high > low)
		{
			mid = (low+high)/2;
			cout<<mid;

			if( countTotal( mid, first, rest, n, m, k ) )
            	high = mid;
	        else
	            low = mid+1;
/*			sum = countTotal(mid, first, rest, n, m, k);
			if(sum >= k)
			{
				high = mid;
				result = high;
			}
			else
			{
				low = mid+1;
			}
*/
		}
		cout<<endl<<high;
	}
	
	return 0;
}

int countTotal(long mid, long *first, long *rest, long n, long m, long k)
{	
	long sum=0;
	long *nuts = new long[m];
	for(long i=0; i<m; i++)
	{
		if(mid >= first[i])
		{
			nuts[i]=((mid - first[i])/rest[i])+1;
		}
		else
		{
			nuts[i]=0;
		}
	}
	//taking the top values of the squirrel
	sort(nuts, 0, m-1);
	for(long i=m-1; i>=(m-n);i--)
	{
		sum=sum+nuts[i];	
	
//	return sum;
	 if( sum >= k)
            return 1;
	}
    return 0;
}

void sort(long *array, long low, long high)
{
	if( low >= high)
		return;
	
	long pivot = (low+high)/2;
	long pivotElement = array[(low+high)/2];;
	swapPointers(&array[low], &array[pivot]);
	long start = low+1;
	long end = high;
	while( start <= end)
	{
		while((start <= high) && (array[start] <= pivotElement))
			start++;
		while((end >= low) && (array[end] > pivotElement))
			end--;
		if(start < end)
		{
			swapPointers(&array[start], &array[end]);
		}
	}
	swapPointers(&array[low], &array[end]);
	sort(array, low, end-1);
	sort(array, end+1, high);
}
