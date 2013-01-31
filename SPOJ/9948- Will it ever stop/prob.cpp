#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	unsigned long long n;
	cin>>n;
	int count =0;
	while (n > 1)
	{
		if(n%2 == 0)
			n/=2;
		else
		{
			n=3*(n+1);
			count = 1;
			break;
		}
	}
	if(count == 0)
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;

}
