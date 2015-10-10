#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;
bool vis[maxn] ;
int cnt ;
LL p[maxn] ;
void pre_cal()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i)
        vis[j]=1 ;
    cnt=0 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++cnt]=(LL)i ;
}

main()
{
    pre_cal() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL l,r ; scanf("%lld%lld",&l,&r) ;
        int ans=0 ;
        for(int i=1;i<=cnt;i++)
        {
            if(r/p[i] < p[i]) continue ;
            for(LL j=p[i]*p[i];;j*=p[i])
            {
                if(j>=l) ans++ ;
                if(r/p[i] < j) break ;
            }
        }
        printf("%d\n",ans) ;
    }
}
