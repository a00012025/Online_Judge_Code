#include<bits/stdc++.h>
#define LL long long
using namespace std;

int m ;
LL frac[10000010] ;

LL F(LL x)
{
    LL ret ;
    if(x%2) ret=((((x%m)*(((x+1)/2)%m))%m)*(x%m)+m-1)%m ;
    else ret=(((((x/2)%m)*((x+1)%m))%m)*(x%m)+m-1)%m ;
    if(x+1>=m) return ret ;
    else return (frac[x+1]+ret)%m ;
}

main()
{
    int n ; scanf("%d%d",&n,&m) ;
    frac[0]=1LL ;
    for(int i=1;i<=m+1;i++)
    {
        frac[i]=(frac[i-1]*i)%m ;
        if(frac[i]==0) break ;
    }

    LL ans=0LL ;
    while(n--)
    {
        LL x ; scanf("%lld",&x) ;
        ans+=F(x) ; ans%=m ;
    }
    printf("%lld\n",ans) ;
}
