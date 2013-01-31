#include<stdio.h>

int main()
{

//int arr[]={5,0,1,2,6,7,8,3,4,9};
int arr[]={21,2,7,9,20,15,3,23,5,0,17,11,12,13,22,14,1,8,10,4,24,19,6,18,16};
int i,j,n,temp;
n=sizeof(arr)/sizeof(arr[0]);

for(j=0;j<=1;j++)
{
        for(i=0;i<n;i++)
        {
              if(arr[i]!=i){
                        temp=arr[i];
                        arr[i]=arr[arr[i]];
                        arr[temp]=temp;

                }

        }
}

for(i=0;i<n;i++)
        printf("%d ",arr[i]);
printf("\n");
return 1;
}
