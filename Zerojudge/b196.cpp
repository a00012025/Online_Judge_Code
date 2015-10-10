#include<stdio.h>
int gcd(int x,int y)
{
    return y==0 ? x : gcd(y,x%y) ;
}
int a[10000001]={0},sum[10000001] ;
main()
{
    for(int i=1;i*i<=10000000;i++) for(int j=i+1;i*i+j*j<=10000000;j++)
    {
        if(gcd(j*j-i*i,gcd(2*i*j,i*i+j*j))!=1) continue ;
        a[i*i+j*j]++ ;
    }
    sum[0]=0 ;
    for(int i=1;i<=10000000;i++) sum[i]=sum[i-1]+a[i] ;
    int L ;
    while(scanf("%d",&L)==1 && L) printf("%d\n",sum[L]) ;
}
