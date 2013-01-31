#include<iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <string>
#include <stdlib.h>

using namespace std;

void rle(string& mystring)
//void rle(char *mystring)
{
	char prev = mystring[0], curr = mystring[1];
	char prev_old, curr_old;
	int count = 1;
	int k = 0;
	int j=0;
	int len=0;
	char *num;
	while(mystring[j])
	{	
		while((prev == mystring[j+1]) && (mystring[j+1]!='\0'))
		{
			j++;
			count++;
		}
		mystring[k++]=prev;
		if(count > 1 && count < 10)
		{
			mystring[k++]=count+'0';
		}
		else if(count != 1)
			{
				len=0;
				num = new char[count];
				itoa(count, num,10);
				while(num[len])
				{
					mystring[k++]=num[len++];
				}
			}
		count=1;
		j++;
		if(mystring[j])
		{
			prev = mystring[j];
		}
	}	
	mystring[k]='\0';
}





//void pointerTechnique(string& mystring)
void pointerTechnique(char *s)
{
	char *q = s, *p = s;
    int len;
    while(*q != '\0')
    {
        while(*++p == *q);
        *s++ = *q;
        len = p - q;
        if(len > 1)
        {
            if(len < 10)
                *s++ = len + '0';
            else
                s += sprintf(s, "%d", len);
        }
        q = p;
    }
    *s = '\0';
}


int main()
{
	string mystring;
	getline(cin,mystring);
//	cout<<mystring<<endl;
//	char *alphabets = new char[26];
	rle(mystring);
	
//	char s[100];
//	scanf("%s", s);
//	pointerTechnique(s);
//	printf("%s \n",s);
	int j=0;
	while(mystring[j]!='\0')
	{
		cout<<mystring[j];
		j++;
	}
	cout<<endl;

	
	
}
