#include<iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void swapPointers(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int isVowel(char a)
{
	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return 1;
	else
		return 0;
}

int main(int argc, char* argv[])
{
	string test = "Hi, My name is Prankur";
	int i=0;
	int length = test.size();
	cout<<length<<endl;
	
	char *array = new char[length+1];
	array[length] = '\0';
	for(int i=0; i<length; i++)
	{
		array[i] = test[i];
	}
	
	cout<<array<<endl;
	
	char* first = array;
	int low = 0;
	int high = length -1;
	
	//cout<<first[0]<<endl;
	//cout<<first[length-1]<<endl;
	
	while(low<high)
	{
		while(!isVowel(first[low]))
		{
			low++;
		}
		while(!isVowel(first[high]))
		{
			high--;
		}
		//cout<<first[low]<<endl;
		//low++;
		if(low < high)
		{
			swapPointers(&first[low], &first[high]);
			low++;
			high--;
		}
	}
	
	cout<<array<<endl;
	
	return 0;	
}


