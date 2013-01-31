#include<iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
	
int max(int *a,int size){
	int maximum = a[0];
	for(int i=1;i<size;i++)
	{
		if(a[i]> maximum)
			maximum = a[i];
	}
	return maximum;
}
			
int main()
{
	int t;
	int ng, nm;
	int *godzilla;
	int *mecha;
	cin>>t;
	int largeGodzilla=0;
	int largeMecha=0;
	
	for(int i=0; i<t; i++)
	{
		cin>>ng>>nm;
		godzilla = new int[ng];
		mecha = new int[nm];
		for(int j=0; j<ng; j++)
		{
			scanf("%d",&godzilla[j]);
		}
		for(int j=0; j<nm; j++)
		{
			scanf("%d",&mecha[j]);
		}

		largeGodzilla =max(godzilla,ng);
		largeMecha   = max(mecha,nm);
	
	
		if(largeGodzilla >= largeMecha)
			cout<<"Godzilla"<<endl;
		else
			cout<<"MechaGodzilla"<<endl;
	}
}



