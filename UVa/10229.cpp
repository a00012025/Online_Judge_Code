#include<stdio.h>
#define MOD 524288
int a[10000000] ;
main()
{
    a[0]=0 ; a[1]=1 ;
    int cyc=786432 ;
    for(int i=1;i<=800000;i++)
    {
        a[i+1]=a[i]+a[i-1] ;
        a[i+1]%=MOD ;
        if(a[i]==0 && a[i+1]==1) break ;
    }
    int n,m ;
    while(scanf("%d %d",&n,&m)==2)
    {
        int k=1 ;
        while(m--) k*=2 ;
        n%=cyc ;
        printf("%d\n",a[n]%k) ;
    }
}
