#include<stdio.h>

main()
{
	int a,b,r,q=0,d=0,c;
	printf("Enter the dividend and divisor: \n");
	scanf("%d \n %d",&a,&b);
	
	r=a;
	while(r>b)
	{
		r=r-b;
		q++;
	}
	c=r*1000;
	while(c>b)
	{
		c=c-b;
		d++;
	}
	printf("dividend= %d \ndivisor= %d \nquotient= %d \t remainder= %d \n",a,b,q,r);
	printf("value of %d/%d is %d.%d \n\n",a,b,q,d);
}
