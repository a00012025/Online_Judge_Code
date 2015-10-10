#include<stdio.h>
#include<stdlib.h>
int a[2800000];
main()
{
 int i,n;
 a[0]=10006;
 a[1]=1;
 a[2]=1;
 a[3]=1;
 for(i=4;i<=2799999;i++) 
    {
    a[i]=a[i-1]+a[i-2]+a[i-3];
    a[i]=a[i]%10007;
    }
 while(scanf("%d",&n)==1)
 {
 n=n%2781668;
 printf("%d\n",a[n]);
 }
}
