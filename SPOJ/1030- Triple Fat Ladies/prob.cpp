#include<iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main()
{
	unsigned long long int t,k, count, result, additionalNum;
	cin>>t;
	
	int *array = new int[4];
	array[1] = 192;
	array[2] = 442;
	array[3] = 692;
	array[0] = 942;
	
	
	
	for(int i=0; i<t; i++)
	{
//		count =0;
//		result = 192;
		cin>>k;
		int choice = (k%4);
		additionalNum = k%4 == 0 ? k/4-1 : k/4;
//		cout<<choice<<" "<<additionalNum<<endl;
		cout<<additionalNum*1000+array[choice]<<endl;
/*		while(count<k)
		{
			if(((unsigned long long int)pow(result,3))%1000 == 888)
			{
				count++;
				if(count == k)
					break;
			}
			result= result+250;
		}
		cout<<result<<endl;
*/
	}

}
