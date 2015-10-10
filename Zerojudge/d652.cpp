#include<stdio.h>
#include<string.h>
main()
{
 char s[30],t[30];
 int n,i,j,a[60],M,b[60],N,m2,m;
 while(scanf("%d",&n)==1)
 {
 M=0;
 for(i=1;i<=n;i++)scanf("%d",&a[i]);
 m=a[1];
 for(i=1;i<=n;i++)
    {
    if(a[i]<=m) m=a[i];
    }
 N=0;
 for(i=1;i<=n;i++)
    {
    if(a[i]!=m) continue ;
    if(i==1)
        {
        for(j=2;j<=n-1;j++) M+=a[j]*a[j+1];
        M=M*a[1];
        }
    else if(i==n)
        {
        for(j=n-2;j>=1;j--) M+=a[j]*a[j+1];
        M=M*a[n];
        }
    else if(i==2)
        {
        for(j=3;j<=n-1;j++) M+=a[j]*a[j+1];
        M=M+a[1]*a[n];
        M=M*a[2];
        }
    else if(i==n-1)
        {
        for(j=n-3;j>=1;j--) M+=a[j]*a[j+1];
        M+=a[1]*a[n];
        M=M*a[n-1];
        }
    else
        {
        for(j=1;j<=i-2;j++) M+=a[j]*a[j+1];
        for(j=i+1;j<=n-1;j++) M+=a[j]*a[j+1];
        M+=a[1]*a[n];
        M=M*a[i];
        }
    b[N]=M;
    N+=1;
    }
 m2=b[0];
 for(i=0;i<=N-1;i++)
    {
    if (b[i]<=m2) m2=b[i];
    }
 printf("%d\n",m2);
 }
}
