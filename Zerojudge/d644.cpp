#include<stdio.h>
#include<stdlib.h>
int a[400000];
main()
{
 int i,n;
 a[1]=1;
 a[2]=1;
 for(i=3;i<=399999;i++)
    {
    if(i%3==1) a[i]=a[i-1]+a[i-2]-1;
    else a[i]=a[i-1]+a[i-2];
    a[i]=a[i]%100019;
    }
 while(scanf("%d",&n)==1)
 {
 n=n%300054;
 if(n==0)printf("%d\n",a[300054]);
 else printf("%d\n",a[n]);
 }
}
