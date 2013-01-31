#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <string>
#include <stdlib.h>


int calculateLength(char *input)
{
	int length = strlen(input);
	int finalLength=0;
	int temp=0;
	for(int i=0; i<length;i++)
	{
		while(input[i] >= 'a' && input[i] <= 'z')
		{
			i++;
		}
		while(input[i] >='1' && input[i] <= '9')
		{
			temp = temp*10+ input[i]-'0';
			i++;
		}
		if(temp != 1)
		{
			finalLength += temp;
		}
		else
		{
			finalLength +=2;
		}
		temp=0;
	}
	return finalLength;
}

void decode(char *input)
{
//	cout<<input<<endl;
	int inputLength = strlen(input);
	cout<<inputLength<<endl;
	int actualLength = calculateLength(input);
	int j = inputLength-1;
	int i = actualLength-1;
	int loop=0;
	char c;
	int l,r, temp=0;;
	while(j != 0)
	{
		if(input[j] >= 'a' && input[j] <= 'z')
		{
			j--;
		}
		else
		{
			r=j;
			temp=0;
			while(input[j]>='1' && input[j] <= '9')
			{
				j--;
			}
			l=j;
			j++;
			while(j <= r)
			{
				temp= temp*10+(input[j]-'0');
				j++;
			}
			j=l;
			cout<<"temp:"<<temp<<endl;
			if(temp != 1)
			{
				c=input[j];
				cout<<c<<endl;
				while(temp != 0)
				{
					input[i--]=c;
					temp--;
				}
			}
			else
			{
				input[i--]='1';
				input[i--]=input[j];
			}
		}
	}
	
	int newLength=0;
	while(loop < actualLength)
	{
		if(input[loop] != '1')
		{
			input[newLength++] = input[loop++];
		}
		else
		{
			loop++;
		}
	}
	input[newLength]='\0';
	printf("%s\n",input);
	
}


int main()
{
	char input[6];
//	cout<<input<<endl;
	scanf("%s",input);
//	cout<<input<<endl;
	decode(input);
}
