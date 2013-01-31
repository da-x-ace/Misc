#include<iostream>
#include <stdio.h>

using namespace std;

int main()
{
	unsigned long long n;
	cin>>n;
	int count =0;
	if((n & (n - 1)) == 0)
	{
		cout<<"TAK"<<endl;
	}
	else
	{
		cout<<"NIE"<<endl;
	}
}
