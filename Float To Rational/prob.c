#include <stdio.h>
#include<math.h>
#include <stdlib.h>

main()
{
  	char str[10];
  	long a,b,x,y,l;
	float d;
  	int i=0,count=0,p=0;
  	printf("enter some string ");
	scanf("%s",&str);
	
	while (str[p] != '\0') 
	{
		if(str[p]=='.')
			i=1;
		if(i==1)
			count++;
		p++;
	}
	
	i=count-1;
  	printf("lenght of string %d \n",i);
  	b=pow(10,i);
	sscanf(str, "%f", &d);
	a=d*b;
  	printf("%d,%d \n",a,b);
  	
  	l=lcm(a,b);
	x=l/a;
	y=l/b;
	
	printf("%d,%d,%d \n",l,x,y);
	printf("fraction is: %d/%d \n",y,x);
}

int gcd(int m, int n)
{
int tmp;
while(m) { tmp = m; m = n % m; n = tmp; } 
return n;
}

int lcm(int m, int n)
{
return m / gcd(m, n) * n;
}

