#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

void reverse(char* start, char* end)
{
	char tmp;
	while(start < end)
	{
		tmp = *start;
		*start = *end;
		*end = 	tmp;
		start++;
		end--;
	}
}

void reverseWords(char* s)
{
	int len = strlen(s);
	
	char* tmp = s;
	
	char* word_begin = s;
	
	while(*tmp)
	{
		tmp++;
		if(*tmp ==)
		if(*tmp == ' ')
		{
			reverse(word_begin, tmp-1);
			word_begin = tmp+1;
		}
		if(*tmp == '\0')
		{
			reverse(word_begin, tmp-1);
		}
	}
	
	reverse(s, tmp-1);
}

int main()
{
	char str[] = "i like this program very much";
	char* tmp = str;
	reverseWords(tmp);
	cout<<str<<endl;
}
