#include<stdio.h>
#include<stdlib.h>
int a[1009];
main()
{
 int i,n;
 a[0]=1;
 a[1]=1;
 for(i=2;i<=1008;i++)
    {
    a[i]=a[i-1]+a[i-2];
    a[i]=a[i]%2012;
    }
 while(scanf("%d",&n)==1)
    {
    n=n%1008;
    printf("%d\n",a[n]);
    }
}
