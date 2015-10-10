#include<stdio.h>
#include<stdlib.h>
main()
{
 int a[20018];
 int i,n;
 a[0]=1;
 a[1]=1;
 a[2]=2;
 for(i=1;i<=20015;i++)
    {
    a[i+2]=a[i+1]+a[i];
    a[i+2]=a[i+2]%10007 ;
    }
 while(scanf("%d",&n)==1)
 {
 if(n<=20016) printf("%d\n",a[n]);
 else
    {
    n=n%20016;
    printf("%d\n",a[n]);
    }
 }
}
