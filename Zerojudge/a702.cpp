#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a[20000010],b[100001];
main()
{
 int M,i,j,k,n;
 for(i=1;i<=20000010;i++)a[i]=1;
 for(j=2;j<=20000000;)
    {
    for(k=2;k*j<=20000000;k++) a[k*j]=0;
    for(k=j+1;a[k]==0;k++);
    j=k;
    }
 n=1;
 j=3;
 while(n<=100000)
    {
    for(i=j;((a[i]!=1)||(a[i+4]!=1));i++);
    b[n]=i;
    n=n+1;
    j=i+2;
    }
 while(scanf("%d",&n)==1)
    {
    printf("(%d, %d)\n",b[n],b[n]+4);
    }
}
