#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        LL ans=INF ;
        while(m--)
        {
            LL u,d ; scanf("%lld%lld",&u,&d) ;
            LL v=(u*n)%(u+d) ;
            if(v==0) v=u+d ;
            ans=min(ans,v) ;
        }
        printf("%lld\n",ans) ;
    }
}
