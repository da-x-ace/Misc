#include<iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void nextPalindrome(char *);

int checkPalindrome(unsigned long long int n)
{
	unsigned long long int temp, rev=0, val;
	temp = n;
	while(temp > 0)
	{
		val = temp % 10;
		rev = rev*10+val;
		temp = temp/10;
	}
	if(rev == n)
		return 1;
	return 0;
}

int main()
{
	unsigned long long int t,n, check;
	int j=0, length =0;
	bool flag = false;
	cin>>t;
	n = 1000002;
	char *number = new char[n];
	for(int i=0; i<t;i++)
	{
		gets(number);
		nextPalindrome(number);	
	}
}
void nextPalindrome(char *number)
{
	int length = strlen(number);
	bool flag = false;
	int check=0, checkLow=0, checkHigh=0;
//	cout<<length<<endl;
	//first checking the special case for 999999....
	
	
	for(int i=0; i<length; i++)
	{
		if(number[i]=='9')
		{
			check++;
		}
	}
	if(check == length)
	{
//		cout<<"All nines :) "<<endl;
//		char *output= new char[length+2];
		number[0]='1';
		for(int j=1; j<length; j++)
			number[j]='0';
		number[length]='1';
		number[length+1]='\0';
		cout<<number<<endl;
		return;
	}
	
/*	if(length == 1)
	{
		number[0]+=1;
		cout<<number[0]<<endl;
		return;
	}
	*/
	check=0;
	
	for(int i=0; i<(length/2); i++)
	{
		if(number[i] > number[length-1-i])
		{
			check = -1;
		}
		else if(number[i] < number[length-1-i])
		{
			check = 1;
		}
		number[length-1-i]=number[i];
	}
	
	if(check == -1)
	{
		cout<<number<<endl;
		return;
	}
	int t=0;
	int val=0;
	
	if( check == 1 || check == 0)
	{
		if(length%2)
		{
			val = (length/2);
		}
		else
		{
			val = (length/2)-1;
		}
		while(number[val-t] == '9')
			{
				number[val-t]='0';
				number[length-1-(val-t)]=number[val-t];
				t++;
			}
			number[val-t]+=1;
			number[length-1-(val-t)]=number[val-t];
			cout<<number<<endl;
			return;
	}
}

