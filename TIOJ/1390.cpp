#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,last[20][20] ;
LL val[20][20],d[40000] ;
LL dp(int x)
{
    if(d[x]!=-1) return d[x] ;
    LL &ans=d[x] ; ans=0LL ;
    for(int i=0;i<n;i++) if(x&(1<<i))
        for(int j=i+1;j<n;j++) if(x&(1<<j))
    {
        ans=max(ans,val[i][j]+dp(x^(1<<i)^(1<<j)^(1<<last[i][j]))) ;
    }
    return ans ;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(d,-1,sizeof(d)) ;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            scanf("%lld",&val[i][j]) ;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            scanf("%d",&last[i][j]) ;
        printf("%lld\n",dp((1<<n)-1)) ;
    }
}
