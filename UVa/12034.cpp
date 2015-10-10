#include<stdio.h>
#define MOD 10056
int C[1001][1001],ans[1001] ;

void pre_cal()
{
    C[1][0]=C[1][1]=1 ;
    for(int i=2;i<=1000;i++) for(int j=0;j<=i;j++)
        C[i][j]= j==0 ? 1 : ( j==i ? 1 : ( (C[i-1][j]+C[i-1][j-1])%MOD) ) ;
    ans[0]=ans[1]=1 ; ans[2]=3 ;
    for(int i=3;i<=1000;i++)
    {
        ans[i]=0 ;
        for(int k=1;k<=i;k++) ans[i] += C[i][k] * ans[i-k] , ans[i] %= MOD ;
    }
}

main()
{
    pre_cal() ;
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ; printf("Case %d: %d\n",++tc,ans[n]) ;
    }
}
