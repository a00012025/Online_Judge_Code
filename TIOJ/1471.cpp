#include<bits/stdc++.h>
#define MOD 1000000000
const int maxn=3000+10 ;

int sum1[maxn][maxn],sum2[maxn][maxn] ;

main()
{
    int n,s ; scanf("%d",&n) ;
    int ans=0 ;
    for(int i=1;i<=n;i++) for(int j=0;j<=n;j++)
    {
        if(j>i)
        {
            s=(s+sum1[i][j-1])%MOD ;
            s-= (j>=2*i+1) ? sum2[i][j-2*i-1] : sum2[j-i-1][0] ;
            s=(s%MOD+MOD)%MOD ;
        }

        if(i>j || ((i+j)%2))
        {
            sum1[i][j]= (j ? sum1[i-1][j-1] : 0) ;
            sum2[i][j]=sum2[i-1][j+1] ;
            continue ;
        }

        if(i==j)
        {
            s=0 ;
            sum1[i][j]=(sum1[i-1][j-1]+1)%MOD ;
            sum2[i][j]=(sum2[i-1][j+1]+1)%MOD ;
            if(i+j==n) ans++ ;
            continue ;
        }

        if(i+j==n) ans=(ans+s)%MOD ;
        sum1[i][j]=(sum1[i-1][j-1]+s)%MOD ;
        sum2[i][j]=(sum2[i-1][j+1]+s)%MOD ;
    }
    if(n<=50) printf("%d\n",ans) ;
    else printf("%09d\n",ans) ;
}
