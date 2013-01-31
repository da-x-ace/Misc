#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

void computeLPS(char* pat, int m, int* lps)
{
	int len = 0;
	int i = 0;
	lps[0]=0;
	i++;
	while(i < m)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
			if(len != 0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
	}		
}

void KMPSearch(char* pat, char* text)
{
	int m = strlen(pat);
	int n = strlen(text);
	int* lps = (int*)malloc(sizeof(int)*m);
	int i=0, j=0;
	
	if(m> n)
		return;
	computeLPS(pat, m, lps);
	
	while(i < n)
	{
		if(pat[j] == text[i])
		{
			i++;
			j++;
		}
		if(j == m)
		{
			cout<<"Found pattern at index :"<<i-j<<endl;
			j = lps[j-1];
		}
		else
			if(pat[j] != text[i])
			{
				if(j != 0)
				{
					j = lps[j-1];
				}
				else
					i=i+1;
			}
		
	}
	//delete (lps);
}


int main()
{
	char *txt = "ABABDABACDABABCABAB";
   char *pat = "ABABCABAB";
   KMPSearch(pat, txt);
   return 0;
	
}
